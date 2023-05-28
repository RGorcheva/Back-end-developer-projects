CREATE TABLE CUSTOMERS (
       customer_id   number,
       first_name     varchar2(60),
       family_name    varchar2(60),
       sex            varchar2(1),
       adr_city       varchar2(50),
       adr_country    varchar2(50),
       credit_limit   number(20,2),
       email          varchar2(50),
       constraint customer_id_pk primary key (customer_id)
);

create table invoices (
       inv_no      varchar2(50),
       amount      number(10,2), 
       amount_due  number(10,2),
       currency    varchar2(3),
       issue_date  date,
       due_date    date,
       customer_id number,
       seq         number,
       constraint inv_no_pk primary key (inv_no) ,
       CONSTRAINT fk_customer FOREIGN KEY (customer_id) REFERENCES CUSTOMERS(customer_id)
);

create table payments (
       invoice_no      varchar2(50),
       payment_id      varchar2(60),
       payment_dt      date,
       amount          number(10,2),
       payment_method  varchar2(10),
       currency        varchar2(3),
       fg_processed    varchar2(1),
       iban            varchar2(60),
       bank_name       varchar2(100),
       created_by      varchar2(50),
       free_text       varchar2(1000),
       constraint paym_no_pk primary key (payment_id) ,
       CONSTRAINT fk_inv FOREIGN KEY (invoice_no) REFERENCES invoices(inv_no)
);

drop table holidays;
create table holidays(
          holiday_date DATE not null,
          holiday_name VARCHAR2(100),
          constraint holidays_pk primary key (holiday_date),
          constraint is_midnight check ( holiday_date = trunc ( holiday_date ) )
        );


drop SEQUENCE customers_seq;
CREATE SEQUENCE customers_seq
 START WITH     1
 INCREMENT BY   1
 CACHE          100
 NOCYCLE;
 
 
drop sequence payments_seq;
CREATE SEQUENCE payments_seq
 START WITH     1
 INCREMENT BY   1
 CACHE          100
 NOCYCLE;

set timing on;
-- insert customers
declare
  cust_num number;
begin
  cust_num := 0;
  while cust_num < 500000
    loop 
      cust_num := cust_num+1;
      insert into CUSTOMERS (customer_id, 
                             first_name,
                             family_name,
                             sex,
                             adr_city, adr_country,
                            credit_limit, email)
       select customers_seq.nextval, 
                f_names.f_name,
                name_Fam.f_name,
                (case when mod(cust_num,16) < 11 then 'm' else 'f' end),
                'Sofia', 'Bulgaria', 
                round(dbms_random.value(10, 100))*100, 'test_' || to_char(customers_seq.currval) || '&#64;test.ts'
          from  (select (case mod(rownum,16) when 1 then 'IVAN' when 2 then 'PETAR' when 3 then 'SIMEON' when 4 then 'GEORGI'  when 5 then 'KIRIL'
                            when 6 then 'NIKOLAY' when 7 then 'STEFAN' when 8 then 'DIMITAR' when 9 then 'ATANAS'  when 10 then 'DENIS'
                            when 11 then 'PETYA' when 12 then 'SVETLA' when 13 then 'IVANKA' when 14 then 'KATERINA'  when 15 then 'SILVIA'
                             else 'ASEN' end) as f_name, mod(rownum,16) as rn
                  from dual
                 connect by level<17)  f_names,
                (select (case mod(rownum,16) when 1 then 'IVANOV' when 2 then 'PERTOV' when 3 then 'GEORGIEV' when 4 then 'NIKOLOV'  when 5 then 'SIMEONOV'
                            when 6 then 'BORISOV' when 7 then 'VLADIMIROV' when 8 then 'IVANOVA' when 9 then 'KIRILOVA' 
                              when 10 then 'GEORGIEVA' when 11 then 'VASILEVA'  when 12 then 'SIMEONOVA'
                           when 13 then 'ATANASOVA' when 14 then 'GRIGOROVA' when 15 then 'KOSTOVA'
                                 else 'KOSTOV' end) as f_name, mod(rownum,16) as rn
                   from dual
                    connect by level<17)  name_Fam 
                 where f_names.rn = mod(cust_num,16)
                   and name_Fam.rn = (case when mod(cust_num,16) < 11 then round(dbms_random.value(0, 7) ) else round(dbms_random.value(8, 15)) end)
                ;
       if mod(cust_num,10) = 0
       then
         commit;
       end if;
    end loop; 
    commit;
end;
/
-- ~ 3m

CREATE OR REPLACE TYPE nt_date IS TABLE OF DATE;
/

CREATE OR REPLACE FUNCTION generate_1st_month_pipelined(
  p_months IN NUMBER
)
  RETURN nt_date PIPELINED DETERMINISTIC
IS
  v_start DATE := TRUNC(add_months(sysdate, p_months*(-1)),'MM');
  v_end   DATE := TRUNC(sysdate);
BEGIN
  LOOP
    EXIT WHEN v_start >= v_end;
    PIPE ROW (v_start);
    v_start := v_start + INTERVAL '1' Month;
  END LOOP;
  RETURN;
END generate_1st_month_pipelined;
/

CREATE OR REPLACE FUNCTION generate_dates(
  p_from IN DATE,
  p_to   IN DATE
)
  RETURN nt_date PIPELINED DETERMINISTIC
IS
  v_start DATE := TRUNC(LEAST(p_from, p_to));
  v_end   DATE := TRUNC(GREATEST(p_from, p_to));
BEGIN
  LOOP
    PIPE ROW (v_start);
    EXIT WHEN v_start >= v_end;
    v_start := v_start + INTERVAL '1' DAY;
  END LOOP;
  RETURN;
END generate_dates;
/



declare 
  cursor c_data(id NUMBER) is 
               select customer_id, days.column_value dt, credit_limit/100 as amount, 
                      row_number() over (partition by customer_id order by days.column_value) rn ,
                      min(days.column_value )  over (partition by customer_id ) min_dt_cust,
                      ora_hash(CUSTOMERS.first_name || CUSTOMERS.family_name, 2)+1 as y
                 from CUSTOMERS,   TABLE(generate_1st_month_pipelined((id+1)*12)) days
               where ora_hash (customer_id, 7) = id 
                 and days.column_value > add_months(sysdate, (case when id > 2 then 24 else (id*12) end )*(-1) - ora_hash (credit_limit, 11))
              ;
  TYPE inv_t IS TABLE OF c_data%ROWTYPE INDEX BY PLS_INTEGER;
  l_inv inv_t;
begin
for i in (select rownum-1 n from dual connect by level <= 8 ) -- 0 to 7
loop
   OPEN c_data(i.n);
   loop
     FETCH c_data BULK COLLECT INTO l_inv LIMIT 1000;
     EXIT WHEN l_inv.COUNT = 0;
     FORALL i IN 1..l_inv.count
       insert into invoices (inv_no, amount, amount_due, currency, issue_date, due_date, customer_id, seq)
           values (l_inv(i).customer_id || '_' || l_inv(i).rn || '_' || to_char(l_inv(i).dt, 'YYYYMMDD'), l_inv(i).amount, NULL, 'BGN', l_inv(i).dt, NULL, l_inv(i).customer_id, l_inv(i).rn);
   end loop;
   commit;
   CLOSE c_data;
end loop;  
end;
/
-- ~ 10min

-- insert payments 

declare
 CURSOR c_payments(id number) IS 
    select inv_no, amount, issue_date
     from invoices
    where ( issue_date < to_date('02122022', 'DDMMYYYY') or ora_hash(customer_id, 3) = 0)
      and ora_hash(inv_no, 5) = id;  -- 0, 1, 2, 3, 4
 TYPE data_t IS TABLE OF c_payments%ROWTYPE INDEX BY PLS_INTEGER;
 l_data data_t;
begin
  for i in (select rownum-1 n from dual connect by level <= 6 ) -- 0 to 4
  loop
    OPEN c_payments(i.n);
    LOOP
      FETCH c_payments BULK COLLECT INTO l_data LIMIT 1000;
      EXIT WHEN l_data.COUNT = 0;
      FORALL i IN 1..l_data.count
         insert into payments (invoice_no, payment_id, payment_dt, amount,payment_method, currency, fg_processed,
                                iban, bank_name, created_by/*, free_text*/)
         values (l_data(i).inv_no, payments_seq.nextval, l_data(i).issue_date + round(dbms_random.value(1, 15)),  l_data(i).amount, 'BankTransf', 'BGN', 'Y',
                      'MY_TEST_IBAN1234567', 'MY_TEST_BANK_NAME', 'Test big data');
        COMMIT;
   end loop;
   CLOSE c_payments;
  end loop;
end;
/

-- ~6min
declare
 CURSOR c_payments(id NUMBER) IS 
    select ora_hash(customer_id, 3) as Cust_gr, inv_no, amount, issue_date, rowid
     from invoices
    where issue_date > to_date('02122022', 'DDMMYYYY')
      and ora_hash(inv_no, 6) = id
      and ora_hash(customer_id, 3) > 0;
 TYPE data_t IS TABLE OF c_payments%ROWTYPE INDEX BY PLS_INTEGER;
 l_data data_t;
begin
for c in (select rownum-1 n from dual connect by level <= 7 ) -- 0 to 6 -- ne za vsichki ima plashtaniq
loop
    OPEN c_payments(c.n);
    LOOP
      FETCH c_payments BULK COLLECT INTO l_data LIMIT 5000;
      EXIT WHEN l_data.COUNT = 0;
      if ( c.n=2) 
      then
        FORALL i IN 1..l_data.count
        update invoices set amount_due = l_data(i).amount where rowid = l_data(i).rowid and issue_date = to_date('01022023', 'DDMMYYYY') ;
        commit;
      end if;  -- no payments in these inovices
      --at least one payment for the rest
      
      FORALL i IN 1..l_data.count
      insert into payments (invoice_no, payment_id, payment_dt, amount,payment_method, currency, fg_processed,
                            iban, bank_name, created_by/*, free_text*/)
        select l_data(i).inv_no, payments_seq.nextval, l_data(i).issue_date + round(dbms_random.value(1, 15)),  round(l_data(i).amount/(c.n+2), 2), 'BankTransf', 'BGN', 'N',
              'MY_TEST_IBAN1234567', 'MY_TEST_BANK_NAME', 'Test big data'  
           from dual 
          where ( l_data(i).issue_date < to_date('01022023', 'DDMMYYYY') or c.n != 2 );
      COMMIT;
 
     
      if c.n in (4,5)
       then
         FORALL i IN 1..l_data.count
         insert into payments (invoice_no, payment_id, payment_dt, amount,payment_method, currency, fg_processed,
                              iban, bank_name, created_by/*, free_text*/)
            values (l_data(i).inv_no, payments_seq.nextval, l_data(i).issue_date + round(dbms_random.value(1, 15)),  round(l_data(i).amount/(c.n), 2), 'BankTransf', 'BGN', 'N',
                 'MY_TEST_IBAN1234567', 'MY_TEST_BANK_NAME'
                 , 'Test big data');  
        commit;       
      end if;
      if c.n = 5
       then
         FORALL i IN 1..l_data.count
         insert into payments (invoice_no, payment_id, payment_dt, amount,payment_method, currency, fg_processed,
                              iban, bank_name, created_by/*, free_text*/)
            select l_data(i).inv_no, payments_seq.nextval, l_data(i).issue_date + round(dbms_random.value(1, 15)),  round(l_data(i).amount/2, 2), 'BankTransf', 'BGN', 'N',
                 'MY_TEST_IBAN1234567', 'MY_TEST_BANK_NAME'
                 , 'Test big data'
               from dual where l_data(i).issue_date = to_date('01022023', 'DDMMYYYY');  
        commit;      
        FORALL i IN 1..l_data.count
         insert into payments (invoice_no, payment_id, payment_dt, amount,payment_method, currency, fg_processed,
                              iban, bank_name, created_by/*, free_text*/)
            select l_data(i).inv_no, payments_seq.nextval, l_data(i).issue_date + round(dbms_random.value(1, 15)), l_data(i).amount - round(l_data(i).amount/(c.n+2), 2) - round(l_data(i).amount/2, 2), 'BankTransf', 'BGN', 'N',
                 'MY_TEST_IBAN1234567', 'MY_TEST_BANK_NAME'
                 , 'Test big data'
               from dual where l_data(i).issue_date = to_date('01012023', 'DDMMYYYY');  
        commit;  
      end if;
      if c.n = 4
       then
         FORALL i IN 1..l_data.count
         insert into payments (invoice_no, payment_id, payment_dt, amount,payment_method, currency, fg_processed,
                              iban, bank_name, created_by/*, free_text*/)
            select l_data(i).inv_no, payments_seq.nextval, l_data(i).issue_date + round(dbms_random.value(1, 15)), l_data(i).amount - round(l_data(i).amount/(c.n+2), 2) - round(l_data(i).amount/2, 2), 'BankTransf', 'BGN', 'N',
                 'MY_TEST_IBAN1234567', 'MY_TEST_BANK_NAME'
                 , 'Test big data'
               from dual where l_data(i).issue_date = to_date('01012023', 'DDMMYYYY');  
        commit;  
      end if;
      if c.n not in ( 4, 5)
      then
         FORALL i IN 1..l_data.count
         insert into payments (invoice_no, payment_id, payment_dt, amount,payment_method, currency, fg_processed,
                                iban, bank_name, created_by/*, free_tex*/)
             select l_data(i).inv_no, payments_seq.nextval, l_data(i).issue_date + round(dbms_random.value(1, 15)), l_data(i).amount - round(l_data(i).amount/(c.n+2), 2), 'BankTransf', 'BGN', 'N',
                  'MY_TEST_IBAN1234567', 'MY_TEST_BANK_NAME', 'Test big data' 
                from dual where l_data(i).issue_date = to_date('01012023', 'DDMMYYYY');
      COMMIT;
      end if;
      
   end loop;
  CLOSE c_payments;
end loop;
end;
/
-- ~4min

create index payments_noinv_ind on payments (invoice_no);
create index payments_dt_ind on payments (payment_dt);
create index invoces_dt_ind on invoices (issue_date);
create index invoces_cust_id on invoices (customer_id);
/
MERGE INTO invoices i USING
 (SELECT  sum(p.amount) as paid_am, p.invoice_no from payments p where p.payment_dt >  to_date('01122022', 'DDMMYYYY') group by p.invoice_no) pay
  ON (i.inv_no=pay.invoice_no AND i.issue_date > to_date('01122022', 'DDMMYYYY'))
  WHEN MATCHED
   THEN UPDATE SET i.amount_due = (case when i.amount - pay.paid_am = 0 then NULL else i.amount - pay.paid_am end );
commit;
-- ~5min

INSERT into holidays (HOLIDAY_DATE,HOLIDAY_NAME)
        WITH dts as (
          select to_date('01-01-2022 00:00:00','DD-MM-YYYY HH24:MI:SS'), 'New Year''s Day'                                                  from dual union
          select to_date('03-01-2022 00:00:00','DD-MM-YYYY HH24:MI:SS'), 'Special public holiday because of January 1 being on a Sunday'    from dual union
          select to_date('03-03-2022','DD-MM-YYYY'), 'Liberation Day, Bulgaria''s national day'                                             from dual union
          select to_date('22-04-2022','DD-MM-YYYY'), 'Good Friday (Eastern Orthodox)'                                                       from dual union
          select to_date('24-04-2022','DD-MM-YYYY'), 'Easter (Eastern Orthodox)'                                                            from dual union
          select to_date('25-04-2022','DD-MM-YYYY'), 'Easter Monday (Eastern Orthodox)'                                                     from dual union
          select to_date('01-05-2022','DD-MM-YYYY'), 'Labour Day'                                                                           from dual union
          select to_date('02-05-2022','DD-MM-YYYY'), 'Special public holiday because of May 1 being on a Sunday'                            from dual union
          select to_date('06-05-2022','DD-MM-YYYY'), 'St George''s Day and Armed Forces Day'                                                from dual union
          select to_date('24-05-2022','DD-MM-YYYY'), 'Day of Bulgarian Learning'                                                            from dual union
          select to_date('06-09-2022','DD-MM-YYYY'), 'Unification Day'                                                                      from dual union
          select to_date('22-09-2022','DD-MM-YYYY'), 'Independence Day'                                                                     from dual union
          select to_date('24-12-2022','DD-MM-YYYY'), 'Christmas Eve'                                                                        from dual union
          select to_date('25-12-2022','DD-MM-YYYY'), 'Christmas Day'                                                                        from dual union
          select to_date('26-12-2022','DD-MM-YYYY'), 'Christmas Day, second day'                                                            from dual union
          select to_date('27-12-2022','DD-MM-YYYY'), 'Special public holidays because of Christmas Eve and Christmas Day being on a Saturday and Sunday'   from dual union
          select to_date('28-12-2022','DD-MM-YYYY'), 'Special public holidays because of Christmas Eve and Christmas Day being on a Saturday and Sunday'   from dual union
          select to_date('01-01-2023','DD-MM-YYYY'), 'New Year''s Day'                                                                      from dual union
          select to_date('02-01-2023','DD-MM-YYYY'), 'New Year Holiday'                                                                     from dual union
          select to_date('03-03-2023','DD-MM-YYYY'), 'Liberation Day'                                                                       from dual
        )
        SELECT * from dts;
commit;