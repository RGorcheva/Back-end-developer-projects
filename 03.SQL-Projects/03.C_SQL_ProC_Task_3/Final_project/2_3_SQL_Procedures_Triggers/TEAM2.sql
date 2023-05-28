select max(customer_id) from customers;

select * from customers where customer_id = 499805;
select * from customers where customer_id = 499803;

select * from invoices where customer_id = 499805;
select * from invoices where customer_id = 499803;

select count(*) from invoices where customer_id = 3427 and amount_due > 0;

delete from customers where external_reference = 'EXT499804';

select * from payments o
inner join invoices i 
on i.inv_no = o.INVOICE_NO 
where i.customer_id = 499803
and o.invoice_no LIKE '499803\_%' ESCAPE '\';
order by 2;

select * from over_payments where ORIGINAL_PAYMENT_ID = 13026479;

select * from payments where payment_id = 13026475;

select count(*) from payments where amount != 95 and invoice_no LIKE '499803\_%' ESCAPE '\';
select * from payments where invoice_no LIKE '499803\_%' ESCAPE '\';

update customers set adr_city = 'VARNA' where customer_id = 3427;
/
exec INSERT_DUE_DATE;
/
update customers set external_reference = 'EXT499803' where customer_id = 499803;
update customers set external_reference = 'EXT499805' where customer_id = 499805;

--select * from payments where amount != 95
--AND invoice_no LIKE '3427\_%' ESCAPE '\';