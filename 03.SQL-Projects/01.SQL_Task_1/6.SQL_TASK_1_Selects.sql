--2: List of all debtors which have open (not fully paid) invoices which are overdue
CREATE VIEW View_2 AS
SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, INV.invoice_id, INV.Invoice_amount,
   NVL(SUM(M.Amount), 0) AS Payed_Amount, INV.Due_date
FROM Invoice INV
INNER JOIN Individual CL
ON CL.Individual_ID = INV.Individual_ID
LEFT JOIN Matching M
ON INV.Invoice_ID = M.Invoice_ID
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, INV.invoice_id, INV.Invoice_amount, INV.Due_date
HAVING INV.Invoice_amount > NVL(SUM(M.Amount), 0) AND INV.Due_date < SYSDATE
ORDER BY 1;

--DROP VIEW View_2;
SELECT * FROM View_2;

--3: List all payers which have overpaid their debts
--CREATE VIEW View_3 AS
SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, SUM(NVL(P.Payment_amount,0)),
    SUM(NVL(M.Amount,0)) AS SUM_AMOUNT, SUM(NVL(P.Payment_amount,0))-SUM(NVL(M.Amount,0)) AS Overpayed
FROM Payment P
INNER JOIN  Individual CL
ON P.Individual_ID = CL.Individual_ID
LEFT JOIN Matching M
ON P.Payment_ID = M.Payment_ID
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name
HAVING SUM(NVL(P.Payment_amount,0)) > SUM(NVL(M.Amount,0))
order by 2;

--DROP VIEW View_3;
SELECT * FROM View_3;

--4: List of all debtors who doesn't have any active contact details
--CREATE VIEW View_4 AS
SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, CONT.Contact_status_ID, CONT.Contact_info
FROM Individual CL
INNER JOIN Invoice INV
ON CL.Individual_ID = INV.Individual_ID
LEFT JOIN Contacts CONT
ON CL.Individual_ID = CONT.Individual_ID
WHERE INV.Individual_ID NOT IN (SELECT CL.Individual_ID
                                FROM Individual CL
                                INNER JOIN Contacts CONT
                                ON CONT.Individual_ID = CL.Individual_ID
                                WHERE CONT.Contact_status_ID LIKE 'Active')
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, CONT.Contact_status_ID, CONT.Contact_info
ORDER BY 1;

--DROP VIEW View_4;
SELECT * FROM View_4;

--5: List all active contacts from type e-mail which are with length at least 15 symbols
CREATE VIEW View_5 AS
SELECT CONT.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, CONT.contact_type_id, CONT.contact_status_id,
    CONT.contact_info, LENGTH(CONT.contact_info) AS LENGTH
FROM Individual CL
INNER JOIN Contacts CONT
ON CONT.Individual_ID = CL.Individual_ID
WHERE CONT.Contact_type_ID LIKE 'Mail' AND CONT.Contact_status_ID LIKE 'Active'
    AND LENGTH(CONT.contact_info) >= 15;
    
--DROP VIEW View_5;
SELECT * FROM View_5;

--6: List all invoices of individuals which don't have active contacts and due date is in the past
CREATE VIEW View_6 AS
SELECT INV.Invoice_ID, INV.Invoice_Amount, INV.Due_date, CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, 
    CONT.Contact_status_ID, CONT.Contact_type_ID, CONT.Contact_info
FROM Invoice INV
INNER JOIN Individual CL
ON CL.Individual_ID = INV.Individual_ID
INNER JOIN Contacts CONT
ON CL.Individual_ID = CONT.Individual_ID
WHERE INV.Due_date < SYSDATE AND INV.Individual_ID NOT IN (SELECT CL.Individual_ID
                                                            FROM Individual CL
                                                            INNER JOIN Contacts CONT
                                                            ON CONT.Individual_ID = CL.Individual_ID
                                                            WHERE CONT.Contact_status_ID LIKE 'Active')
GROUP BY  INV.Invoice_ID, INV.Invoice_Amount, INV.Due_date, CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, 
    CONT.Contact_status_ID, CONT.Contact_type_ID, CONT.Contact_info
ORDER BY 1;

--DROP VIEW View_6;
SELECT * FROM View_6;

--7: List moral individuals which have invoices created during APRIL and have contact "GSM"
CREATE VIEW View_7 AS
SELECT CL.Individual_ID, CL.Company_name AS Company, CL.First_name||' '||CL.Last_name AS Contact_name, CL.Individual_type_ID, INV.Invoice_ID, INV.Creation_date, 
    CONT.Contact_type_ID, CONT.Contact_info
FROM Individual CL
INNER JOIN Invoice INV
ON CL.Individual_ID = INV.Individual_ID
INNER JOIN Contacts CONT
ON CL.Individual_ID = CONT.Individual_ID
WHERE CL.Individual_type_ID LIKE 'Moral' AND CONT.Contact_type_ID LIKE 'Mobile' AND 
    EXTRACT(MONTH FROM INV.Creation_date) = 4;
    
--Drop view View_7;
SELECT * FROM View_7;

--8: List all good payers
--CREATE VIEW View_8 AS
SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, INV.Invoice_ID, INV.Invoice_amount, SUM(M.Amount) AS SUM_AMOUNT, INV.Due_date
FROM Individual CL
INNER JOIN Invoice INV
ON CL.Individual_ID = INV.Individual_ID
LEFT JOIN Matching M
ON INV.Invoice_ID = M.Invoice_ID
LEFT JOIN Payment P
ON P.Payment_ID = M.Payment_ID
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, INV.Invoice_ID, INV.Invoice_amount, INV.Due_date
HAVING (INV.Invoice_amount = SUM(M.Amount) AND MAX(P.Received_date) <= INV.Due_date) OR 
    (INV.Invoice_amount > NVL(SUM(M.Amount),0) AND SYSDATE < INV.Due_date)
ORDER BY 1;

--Drop view View_8;
SELECT * FROM View_8;


--Only names of good pairs:
--CREATE VIEW View_8_2 AS
SELECT CL.First_name, CL.Last_name, CL.Company_name, CL.Individual_ID
FROM Individual CL
RIGHT JOIN (SELECT CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, INV.Invoice_ID, INV.Invoice_amount, SUM(M.Amount) AS SUM_AMOUNT, INV.Due_date, P.Received_date
FROM Individual CL
INNER JOIN Invoice INV
ON CL.Individual_ID = INV.Individual_ID
LEFT JOIN Matching M
ON INV.Invoice_ID = M.Invoice_ID
LEFT JOIN Payment P
ON P.Payment_ID = M.Payment_ID
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name, INV.Invoice_ID, INV.Invoice_amount, INV.Due_date, P.Received_date
HAVING (INV.Invoice_amount = SUM(M.Amount) AND P.Received_date <= INV.Due_date) OR
    (INV.Invoice_amount > NVL(SUM(M.Amount),0) AND SYSDATE < INV.Due_date)) Good_Payers
ON CL.Individual_ID = Good_Payers.individual_id
GROUP BY CL.Individual_ID, CL.First_name, CL.Last_name, CL.Company_name
ORDER BY 1;

Drop view View_8_2;
SELECT * FROM View_8_2;




