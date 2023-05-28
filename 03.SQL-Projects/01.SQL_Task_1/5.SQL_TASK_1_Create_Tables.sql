CREATE TABLE Individual_type (
Individual_type_ID VARCHAR2(45) NOT NULL PRIMARY KEY
);
/
INSERT INTO Individual_type VALUES ('Personal');
INSERT INTO Individual_type VALUES ('Moral');
/
CREATE TABLE Invoice_type (
Invoice_type_ID VARCHAR2(20) NOT NULL PRIMARY KEY
);
/
INSERT INTO Invoice_type VALUES ('Credit');
INSERT INTO Invoice_type VALUES ('Debit');
/
CREATE TABLE Contact_status (
Contact_status_ID VARCHAR2(10) NOT NULL PRIMARY KEY
);
/
INSERT INTO Contact_status VALUES ('Active');
INSERT INTO Contact_status VALUES ('Inactive');
/
CREATE TABLE Contact_type (
Contact_type_ID VARCHAR2(20) NOT NULL PRIMARY KEY
);
/
INSERT INTO Contact_type VALUES ('Address');
INSERT INTO Contact_type VALUES ('Mail');
INSERT INTO Contact_type VALUES ('Fax');
INSERT INTO Contact_type VALUES ('Office phone');
INSERT INTO Contact_type VALUES ('Home phone');
INSERT INTO Contact_type VALUES ('Mobile');
/
CREATE TABLE Individual (
Individual_ID INT NOT NULL PRIMARY KEY,
First_Name VARCHAR2(20) NOT NULL,
Last_Name VARCHAR2(20) NOT NULL,
Company_Name VARCHAR2(50),
Individual_Type_ID VARCHAR2(20) NOT NULL,
FOREIGN KEY (Individual_Type_ID) REFERENCES Individual_Type(Individual_Type_ID)
);
/
CREATE SEQUENCE Seq_Individual_ID;
/
CREATE OR REPLACE TRIGGER Individual_ID_INSERT
BEFORE INSERT ON Individual
FOR EACH ROW
BEGIN
SELECT Seq_Individual_ID.NEXTVAL
INTO :NEW.Individual_ID
FROM DUAL;
END;
/
INSERT INTO Individual VALUES(0, 'Maria', 'Asenova', 'DAHUA', 'Moral');
INSERT INTO Individual VALUES(0, 'Ivan', 'Dimitrov', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Milko', 'Ivanov', 'MILKA', 'Moral');
INSERT INTO Individual VALUES(0, 'Jordan', 'Hristov', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Milena', 'Georgieva', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Zahari', 'Boqnov', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Emil', 'Kirilov', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Georgi', 'Simeonov', 'SIEMENS', 'Moral');
INSERT INTO Individual VALUES(0, 'Petar', 'Petrov', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Ivan', 'Ivanov', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Georgi', 'Georgiev', 'GG', 'Moral');
INSERT INTO Individual VALUES(0, 'Marina', 'Marinova', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Elena', 'Elenova', ' ', 'Personal');
INSERT INTO Individual VALUES(0, 'Mihaela', 'Mihailova', 'MM', 'Moral');
INSERT INTO Individual VALUES(0, 'Matea', 'Donova', 'Canon', 'Moral');
/
CREATE TABLE Contacts (
Contact_ID INT NOT NULL PRIMARY KEY,
Individual_ID INT NOT NULL,
Contact_status_ID VARCHAR2(20) NOT NULL,
Contact_type_ID VARCHAR2(20) NOT NULL,
Contact_info VARCHAR2(300) NOT NULL,
FOREIGN KEY (Individual_ID) REFERENCES Individual(Individual_ID),
FOREIGN KEY (Contact_status_ID) REFERENCES Contact_status(Contact_status_ID),
FOREIGN KEY (Contact_type_ID) REFERENCES Contact_type(Contact_type_ID)
);
/
CREATE SEQUENCE Seq_Contact_ID;
/
CREATE OR REPLACE TRIGGER Contact_ID_INSERT
BEFORE INSERT ON Contacts
FOR EACH ROW
BEGIN
SELECT Seq_Contact_ID.NEXTVAL
INTO :NEW.Contact_ID
FROM DUAL;
END;
/
INSERT INTO Contacts VALUES (0, 1, 'Active', 'Address', 'Bulgaria, Sofia, Center, Vasil Levski blv. 45');
INSERT INTO Contacts VALUES (0, 1, 'Active', 'Mobile', '0888000001');
INSERT INTO Contacts VALUES (0, 1, 'Inactive', 'Mobile', '0888000002');
INSERT INTO Contacts VALUES (0, 2, 'Active', 'Address', 'Bulgaria, Plovdiv, Kapana, Ivan Vazov str. 12');
INSERT INTO Contacts VALUES (0, 2, 'Active', 'Mobile', '0888000003');
INSERT INTO Contacts VALUES (0, 3, 'Inactive', 'Mail', 'user3@yahoo.com');
INSERT INTO Contacts VALUES (0, 4, 'Active', 'Mobile', '0898123123');
INSERT INTO Contacts VALUES (0, 5, 'Active', 'Mobile', '0898000000');
INSERT INTO Contacts VALUES (0, 6, 'Inactive', 'Mail', 'long_string_user6@yahoo.com');
INSERT INTO Contacts VALUES (0, 6, 'Inactive', 'Mobile', '0888000005');
INSERT INTO Contacts VALUES (0, 7, 'Active', 'Mobile', '0888000006');
INSERT INTO Contacts VALUES (0, 7, 'Active', 'Home phone', '029584758');
INSERT INTO Contacts VALUES (0, 7, 'Inactive', 'Address', 'England, London, 90-92 Blackfriars Rd');
INSERT INTO Contacts VALUES (0, 8, 'Active', 'Mobile', '0888000007');
INSERT INTO Contacts VALUES (0, 8, 'Inactive', 'Address', 'Bulgaria,Varna, Izgrev  str. 187');
INSERT INTO Contacts VALUES (0, 9, 'Active', 'Mail', 'new_mail_user9@yahoo.com');
INSERT INTO Contacts VALUES (0, 10, 'Active', 'Address', 'Germany,  Berlin, Grunerstrase 20');
INSERT INTO Contacts VALUES (0, 11, 'Active', 'Mail', 'new_mail_user11@yahoo.com');
INSERT INTO Contacts VALUES (0, 12, 'Active', 'Mobile', '0888000008');
INSERT INTO Contacts VALUES (0, 12, 'Inactive', 'Home phone', '029531456');
INSERT INTO Contacts VALUES (0, 13, 'Active', 'Mobile', '0888000009');
INSERT INTO Contacts VALUES (0, 13, 'Inactive', 'Mail', 'old_mail_user14@yahoo.com');
INSERT INTO Contacts VALUES (0, 13, 'Inactive', 'Mail', 'old_mail_user14@gmail.com');
INSERT INTO Contacts VALUES (0, 14, 'Inactive', 'Mail', 'long_string_user14@yahoo.com');
INSERT INTO Contacts VALUES (0, 15, 'Active', 'Mobile', '0888586214');
/
CREATE TABLE Payment (
Payment_ID INT NOT NULL PRIMARY KEY,
Individual_ID INT NOT NULL,
Payment_amount NUMBER(10,2) NOT NULL,
Received_date DATE NOT NULL,
Creation_date DATE NOT NULL,
FOREIGN KEY (Individual_ID) REFERENCES Individual(Individual_ID));
/
CREATE SEQUENCE Seq_Payment_ID;
/
CREATE OR REPLACE TRIGGER Payment_ID_INSERT
BEFORE INSERT ON Payment
FOR EACH ROW
BEGIN
SELECT Seq_Payment_ID.NEXTVAL
INTO :NEW.Payment_ID
FROM DUAL;
END;
/
INSERT INTO Payment VALUES (0, 2, 3000, '10-01-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 3, 65000, '15-01-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 5, 300, '28-01-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 5, 300, '29-01-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 7, 140.55, '30-01-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 3, 600, '30-01-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 3, 600, '02-02-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 1, 1200, '01-02-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 4, 1000, '2-2-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 2, 1200, '14-2-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 9, 300, '17-2-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 11, 780, '25-3-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 6, 700, '25-3-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 14, 800, '25-3-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 10, 1000, '10-01-2023', SYSDATE);
INSERT INTO Payment VALUES (0, 14, 1000, '10-01-2023', SYSDATE);
/
CREATE TABLE Invoice(
Invoice_ID INT NOT NULL PRIMARY KEY,
Individual_ID INT NOT NULL,
Invoice_amount NUMBER(10,2) NOT NULL,
Invoice_type_ID VARCHAR2(20) NOT NULL,
Due_date DATE NOT NULL,
Creation_date DATE NOT NULL,
FOREIGN KEY (Individual_ID) REFERENCES Individual(Individual_ID),
FOREIGN KEY (Invoice_type_ID) REFERENCES Invoice_type(Invoice_type_ID));
/
CREATE SEQUENCE Seq_Invoice_ID;
/
CREATE OR REPLACE TRIGGER Invoice_ID_INSERT
BEFORE INSERT ON Invoice
FOR EACH ROW
BEGIN
SELECT Seq_Invoice_ID.NEXTVAL
INTO :NEW.Invoice_ID
FROM DUAL;
END;
/
INSERT INTO Invoice VALUES (0, 2, 1200, 'Debit', '14-01-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 2, 1400, 'Debit', '17-1-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 3, 65000, 'Debit', '22-1-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 5, 750.5, 'Debit', '28-1-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 7, 140.55, 'Debit', '30-1-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 8, 1200.25, 'Debit', '1-2-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 3, 1200, 'Debit', '2-2-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 1, 1110, 'Debit', '3-2-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 4, 2233, 'Debit', '2-2-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 2, 1200, 'Debit', '14-2-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 5, 750.5, 'Debit', '28-2-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 9, 500, 'Debit', '23-3-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 11, 780, 'Debit', '25-3-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 2, 1200, 'Debit', '14-3-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 5, 750.5, 'Debit', '28-3-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 6, 666, 'Debit', '8-4-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 14, 789, 'Debit', '10-4-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 2, 1200, 'Debit', '14-4-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 13, 65000, 'Debit', '12-4-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 5, 750.5, 'Debit', '28-4-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 15, 120, 'Debit', '14-1-2023', SYSDATE);
INSERT INTO Invoice VALUES (0, 14, 10, 'Debit', '14-1-2023', SYSDATE);
/
UPDATE Invoice
SET Creation_date = '02-04-2023'
WHERE Invoice_ID = 17;
/
UPDATE Invoice
SET Creation_date = '04-04-2023'
WHERE Invoice_ID = 21;
/
CREATE TABLE Matching(
Match_ID INT NOT NULL PRIMARY KEY,
Payment_ID INT NOT NULL,
Invoice_ID INT NOT NULL,
Amount NUMBER(10,2) NOT NULL,
Match_date DATE NOT NULL,
FOREIGN KEY (Payment_ID) REFERENCES Payment(Payment_ID),
FOREIGN KEY (Invoice_ID) REFERENCES Invoice(Invoice_ID));
/
CREATE SEQUENCE Seq_Match_ID;
/
CREATE OR REPLACE TRIGGER Match_ID_INSERT
BEFORE INSERT ON Matching
FOR EACH ROW
BEGIN
SELECT Seq_Match_ID.NEXTVAL
INTO :NEW.Match_ID
FROM DUAL;
END;
/
INSERT INTO Matching VALUES (0, 1, 1, 1200, SYSDATE);
/
CREATE OR REPLACE FUNCTION func_min(var1 IN NUMBER, var2 IN NUMBER)
RETURN NUMBER
AS
varMin NUMBER:=0.00;
BEGIN
IF var1 <= var2 
THEN varMin:= var1;
ELSE varMin:= var2;
END IF;
RETURN varMin;
END;
/
CREATE OR REPLACE TRIGGER INSERT_Amount_balance_MATCHING
AFTER INSERT ON Invoice
FOR EACH ROW
DECLARE
Overpayed_balance NUMBER:= 0;
Payment_ID NUMBER:=0;
BEGIN
SELECT Payment_ID_Overpayed.Payment_ID
INTO Payment_ID
FROM
(SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, P.Payment_ID, P.Payment_amount, 
SUM(M.Amount) AS SUM_AMOUNT, P.Payment_amount-SUM(M.Amount) AS Overpayed
FROM Individual CL
INNER JOIN  Invoice INV
ON CL.Individual_ID = INV.Individual_ID
INNER JOIN Matching M
ON INV.Invoice_ID = M.Invoice_ID
INNER JOIN Payment P
ON P.Payment_ID = M.Payment_ID
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, P.Payment_ID, P.Payment_amount
HAVING P.Payment_amount > SUM(M.Amount) AND CL.Individual_ID = 14) Payment_ID_Overpayed;
dbms_output.put_line(Payment_ID);

SELECT Payment_ID_Overpayed.Overpayed
INTO Overpayed_balance
FROM
(SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, P.Payment_ID, P.Payment_amount, 
SUM(M.Amount) AS SUM_AMOUNT, P.Payment_amount-SUM(M.Amount) AS Overpayed
FROM Individual CL
INNER JOIN  Invoice INV
ON CL.Individual_ID = INV.Individual_ID
INNER JOIN Matching M
ON INV.Invoice_ID = M.Invoice_ID
INNER JOIN Payment P
ON P.Payment_ID = M.Payment_ID
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, P.Payment_ID, P.Payment_amount
HAVING P.Payment_amount > SUM(M.Amount) AND CL.Individual_ID = 14) Payment_ID_Overpayed;
dbms_output.put_line(Overpayed_balance);

IF Overpayed_balance > 0 AND Payment_ID != 0 THEN
INSERT INTO Matching values(0, Payment_ID, 14, Overpayed_balance, SYSDATE); 
END IF;
END;
/
INSERT INTO Invoice VALUES (0, 14, 10, 'Debit', '14-1-2023', SYSDATE);
/
CREATE OR REPLACE PROCEDURE INSERT_Matching (
PAYMENT INT, 
INVOICE INT) 
AS
Open_payment NUMBER:= 0;
Open_invoice NUMBER:= 0; 
BEGIN 
SELECT  P.Payment_amount-NVL(SUM(M.Amount),0) AS Amount_balance
INTO Open_payment
FROM Payment P
LEFT JOIN Matching M   
ON P.Payment_ID = M.Payment_ID
LEFT JOIN Invoice INV
ON INV.Invoice_ID = M.Invoice_ID
WHERE P.Payment_ID = PAYMENT
GROUP BY P.Payment_ID, P.Payment_amount;

SELECT INV.Invoice_amount-NVL(SUM(M.Amount), 0) AS Amount_balance
INTO Open_invoice
FROM Invoice INV
LEFT JOIN Matching M
ON INV.Invoice_ID = M.Invoice_ID
WHERE inV.Invoice_ID = INVOICE
GROUP BY INV.Invoice_ID, INV.Invoice_amount;

INSERT INTO Matching
SELECT NULL, P.Payment_ID, INV.Invoice_ID, func_min(Open_payment, Open_invoice), SYSDATE 
FROM Invoice INV, Payment P
WHERE P.Payment_ID = PAYMENT AND INV.Invoice_ID =  INVOICE;
END;
/
EXEC INSERT_Matching(1, 2);
EXEC INSERT_Matching(2, 3);
EXEC INSERT_Matching(4, 4);
EXEC INSERT_Matching(5, 5);
EXEC INSERT_Matching(6, 7);
EXEC INSERT_Matching(7, 7);
EXEC INSERT_Matching(8, 8);
EXEC INSERT_Matching(9, 9);
EXEC INSERT_Matching(10, 10);
EXEC INSERT_Matching(11, 12);
EXEC INSERT_Matching(12, 13);
EXEC INSERT_Matching(13, 16);
EXEC INSERT_Matching(14, 17);

/

SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, P.Payment_ID, P.Payment_amount, 
SUM(M.Amount) AS SUM_AMOUNT, P.Payment_amount-SUM(M.Amount) AS Overpayed
FROM Individual CL
INNER JOIN  Invoice INV
ON CL.Individual_ID = INV.Individual_ID
INNER JOIN Matching M
ON INV.Invoice_ID = M.Invoice_ID
INNER JOIN Payment P
ON P.Payment_ID = M.Payment_ID
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, P.Payment_ID, P.Payment_amount
HAVING P.Payment_amount > SUM(M.Amount) AND CL.Individual_ID = 14;

select * from payment
where Individial_id = 14;