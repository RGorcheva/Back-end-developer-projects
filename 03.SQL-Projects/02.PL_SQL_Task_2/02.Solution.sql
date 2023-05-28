SET TIMING ON;
SET SERVEROUTPUT ON;
/
--Задача 1: Генерирайте списък с номера на фактури за м. Март за всички клиенти,
--които имат фактура през м. Февруари 2023г., и които имат по-малко от 10 фактури общо. 
--Списъкът трябва да се генерира за по-малко от минута.

SELECT TO_CHAR(Customer_id)||'_'||TO_CHAR(MAX(seq)+1)||'_20230301' as INVOICES_MARCH
FROM Invoices
WHERE EXISTS (SELECT INV_NO, Customer_id, Seq, Issue_date 
                FROM Invoices 
                WHERE EXTRACT(MONTH FROM Issue_date) = 2 AND EXTRACT(YEAR FROM Issue_date) = 2023)
GROUP BY Customer_id
HAVING MAX(seq)<10
ORDER BY 1;
/
--Задача 2:  Извадете следните 3 резултата: Сума на всички фактури на всички клиенти, 
--чието ID (customer_id) се дели на 2 без остатък, на 3 без остатък и на 4 без остатък.
--Заявката трябва да връща резултат за по-малко от минута и половина.

DECLARE
    count_time NUMBER;
    sum_amount_CUST_MOD2 NUMBER;
    sum_amount_CUST_MOD3 NUMBER;
    sum_amount_CUST_MOD4 NUMBER;
    CURSOR c_id_amount IS SELECT customer_id,  sum(amount) as amount
                          FROM invoices
                          WHERE MOD(customer_id, 2) = 0 OR MOD(customer_id, 3) = 0
                          GROUP BY customer_id;
    rec_id_amount c_id_amount%ROWTYPE;                        
BEGIN
    count_time := DBMS_UTILITY.GET_TIME;
    sum_amount_CUST_MOD2 := 0;
    sum_amount_CUST_MOD3 := 0;
    sum_amount_CUST_MOD4 := 0;
    OPEN c_id_amount;
    FETCH c_id_amount INTO rec_id_amount;
    WHILE c_id_amount %FOUND
    LOOP
        IF MOD(rec_id_amount.customer_id, 12) = 0 THEN  BEGIN 
                                                            sum_amount_CUST_MOD4 := sum_amount_CUST_MOD4 + rec_id_amount.amount;
                                                            sum_amount_CUST_MOD2 := sum_amount_CUST_MOD2 + rec_id_amount.amount;
                                                            sum_amount_CUST_MOD3 := sum_amount_CUST_MOD3 + rec_id_amount.amount;
                                                        END;
        ELSE IF MOD(rec_id_amount.customer_id, 6) = 0 THEN  BEGIN 
                                                                sum_amount_CUST_MOD2 := sum_amount_CUST_MOD2 + rec_id_amount.amount; 
                                                                sum_amount_CUST_MOD3 := sum_amount_CUST_MOD3 + rec_id_amount.amount; 
                                                            END;
            ELSE IF MOD(rec_id_amount.customer_id, 2) = 0 THEN  sum_amount_CUST_MOD2 := sum_amount_CUST_MOD2 + rec_id_amount.amount;
                 ELSE   sum_amount_CUST_MOD3 := sum_amount_CUST_MOD3 + rec_id_amount.amount;
                 END IF;
            END IF;
        END IF;
        FETCH c_id_amount INTO rec_id_amount;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Sum of amounts of all cistomers that MOD(customer_id, 2)= 0 is:'||sum_amount_CUST_MOD2||' BGN'); 
    DBMS_OUTPUT.PUT_LINE('Sum of amounts of all cistomers that MOD(customer_id, 3)= 0 is:'||sum_amount_CUST_MOD3||' BGN'); 
    DBMS_OUTPUT.PUT_LINE('Sum of amounts of all cistomers that MOD(customer_id, 4)= 0 is:'||sum_amount_CUST_MOD4||' BGN'); 
    DBMS_OUTPUT.PUT_LINE('Time consumed:'||TO_CHAR(ROUND((DBMS_UTILITY.GET_TIME - count_time)/100/60, 2))||' min');
END;
/
--Задача 3: Намерете между кои два месеца има най-голямо нарастване на плащания. 
--Изведете двата поредни месеца и разликата в сумите на всички плащания. 
--Заявката трябва да връща резултат за по-малко от минута.

DECLARE
    max_increment NUMBER;
    count_time NUMBER;
    CURSOR c_month_amount IS SELECT extract(YEAR FROM Payment_dt) AS Year_, extract(MONTH FROM Payment_dt) AS Month_, SUM(Amount) AS Amount
                          FROM Payments
                          GROUP BY extract(YEAR FROM Payment_dt), extract(MONTH FROM Payment_dt)
                          ORDER BY 1, 2;
    rec_month_amount_prev c_month_amount%ROWTYPE;      
    rec_month_amount_curr c_month_amount%ROWTYPE; 
    rec_save_prev c_month_amount%ROWTYPE;      
    rec_save_curr c_month_amount%ROWTYPE; 
BEGIN
    count_time := DBMS_UTILITY.GET_TIME;
    OPEN c_month_amount;
    FETCH c_month_amount INTO rec_month_amount_prev;
    FETCH c_month_amount INTO rec_month_amount_curr;
    max_increment := 0;
    WHILE c_month_amount %FOUND
    LOOP
        IF max_increment <= rec_month_amount_curr.Amount - rec_month_amount_prev.Amount THEN 
            BEGIN
                rec_save_prev := rec_month_amount_prev;
                rec_save_curr := rec_month_amount_curr;
                max_increment := rec_month_amount_curr.Amount - rec_month_amount_prev.Amount;
            END;
        END IF;
        rec_month_amount_prev := rec_month_amount_curr;
        FETCH c_month_amount INTO rec_month_amount_curr;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Year-Month: '||rec_save_prev.Year_||'-'||rec_save_prev.Month_||', Amount: '||rec_save_prev.Amount||' BGN');
    DBMS_OUTPUT.PUT_LINE('Year-Month: '||rec_save_curr.Year_||'-'||rec_save_curr.Month_||', Amount: '||rec_save_curr.Amount||' BGN');
    DBMS_OUTPUT.PUT_LINE('Increment of amount: '||max_increment||' BGN');
    DBMS_OUTPUT.PUT_LINE('Time consumed:'||TO_CHAR(ROUND((DBMS_UTILITY.GET_TIME - count_time)/100/60, 2))||' min');
END;  
/
--Задача 4: За всяка фактура от тази година на клиент с ИД 18, изведете броя работни дни след които е
--направено последното плащане за съответната фактура.

CREATE OR REPLACE FUNCTION is_date_holiday(
    p_date IN DATE
)
RETURN number
AS
    tr_date DATE;
    is_holiday number := 0;
    CURSOR c_holiday IS SELECT Holiday_date FROM Holidays;
    rec_date  c_holiday%ROWTYPE;
BEGIN
    tr_date := TRUNC( p_date);
    OPEN    c_holiday;
    FETCH   c_holiday INTO rec_date;
    WHILE   c_holiday %FOUND
    LOOP
        IF tr_date = TRUNC(Rec_date.Holiday_date) THEN BEGIN
                                                    is_holiday := 1;
                                                    RETURN is_holiday;
                                                 END;
        END IF;
        FETCH c_holiday INTO rec_date;
    END LOOP;
    close c_holiday;
    RETURN is_holiday;
END;
/
CREATE OR REPLACE FUNCTION count_working_days(
  p_from IN DATE,
  p_to   IN DATE
)
  RETURN NUMBER
  AS
  count_days number :=0;
  v_start DATE := TRUNC(LEAST(p_from, p_to));
  v_end   DATE := TRUNC(GREATEST(p_from, p_to));
BEGIN
  LOOP
    EXIT WHEN v_start >= v_end;
    IF to_char(v_start, 'D') not in (6, 7) and  is_date_holiday(v_start)=0
    THEN count_days:=count_days+1;
    END IF;
    v_start := v_start + INTERVAL '1' DAY;
  END LOOP;
  RETURN COUNT_DAYS;
END;
/
SELECT INV.Customer_id, SUM(P.Amount) as Payment_amount, INV.Inv_no, INV.Issue_date, MAX(P.Payment_dt) as Last_payment_dt, 
    COUNT_WORKING_DAYS(INV.Issue_date, MAX(P.Payment_dt)) as Working_days
FROM (SELECT * FROM Invoices WHERE Customer_id = 18) INV
INNER JOIN Payments P
ON P.Invoice_no = INV.Inv_no
WHERE EXTRACT(YEAR FROM INV.Issue_date) = 2023
GROUP BY INV.CUSTOMER_id, INV.Inv_no, INV.Issue_date;
