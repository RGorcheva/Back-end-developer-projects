create or replace TRIGGER payment_test_trigger
BEFORE INSERT ON payments_test
FOR EACH ROW
DECLARE
   v_inv_amount_due invoices_test.amount_due%TYPE;
   v_pay_amt payments_test.amount%TYPE;
   v_pay_id payments_test.payment_id%TYPE;
   v_residual payments_test.amount%TYPE;
BEGIN
   IF :NEW.invoice_no IS NOT NULL AND :OLD.invoice_no IS NULL THEN
      SELECT amount_due INTO v_inv_amount_due FROM invoices_test WHERE inv_no = :NEW.invoice_no;
      IF :NEW.amount > v_inv_amount_due THEN
         v_residual := :NEW.amount - v_inv_amount_due;
         v_pay_id := :NEW.payment_id;
         v_pay_amt := v_inv_amount_due;
         :NEW.amount := v_inv_amount_due;
         INSERT INTO over_payments_test (PAYMENT_ID, payment_dt, amount, payment_method, currency, fg_processed, iban, bank_name, created_by,original_payment_id)
         VALUES (payments_seq_test.NEXTVAL,:NEW.payment_dt, v_residual, :NEW.payment_method, :NEW.currency, :NEW.fg_processed, :NEW.iban, :NEW.bank_name, :NEW.created_by,:NEW.payment_id);

         UPDATE invoices_test SET amount_due = 0 WHERE inv_no = :NEW.invoice_no;

      ELSIF :NEW.amount <= v_inv_amount_due THEN
        UPDATE invoices_test SET amount_due = v_inv_amount_due - :NEW.amount  WHERE inv_no = :NEW.invoice_no;
      END IF;
   END IF;
END;
/