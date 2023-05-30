-- ==========================
-- fichier : lmd.sql
-- base : requête
-- auteur(s) : LEFRANCOIS Thibaut
-- date : 21/10/2022
-- role : Question TP4
-- projet : Client
-- resultat dans : 
-- ==========================


-- Question 1 

INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES (1, 'MARTIN', 'JEAN', '0505050505', 'martin@example.org', 'La Rochelle') ;

-- Question 2
--Erreur car on peut pas avoir 2 fois la même clé primaire

-- Question 3
SELECT * FROM CLIENT  ; --Est censé s'afficher avec des ##### si il est pas en number

-- Question 4
ALTER TABLE CLIENT modify (TELCLI varchar2(30)); --Inutile dans notre cas car le tél client était déjà en varchar2

-- Question 5

INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES (2, 'DUPONT', 'JEAN', '0506060606', 'pas de mail', 'La Rochelle') ;

-- Question 6

INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES (0001, 2, TO_DATE('10/10/2013' , 'DD/MM/YYYY'), TO_DATE ('01/12/2013' , 'DD/MM/YYYY')) ;

-- Question 7

--INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
--VALUES (0002, 3, TO_DATE('10/10/2013' , 'DD/MM/YYYY'), TO_DATE ('01/12/2013' , 'DD/MM/YYYY')) ;
--Erreur car client 3 pas encore existant 

-- Question 8

INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES (0003, 1, TO_DATE('15/10/2013' , 'DD/MM/YYYY'), TO_DATE ('01/12/2013' , 'DD/MM/YYYY')) ;

-- Question 9

INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES (0004, 1, TO_DATE('10/10/2013' , 'DD/MM/YYYY'), TO_DATE ('01/10/2013' , 'DD/MM/YYYY')) ;
-- Impossible de vérifier car problème de connexion à Oracle en dehors de l'IUT
-- Mais on imagine une erreur car la date de réception est inférieur à la date de commande

-- Question 10

UPDATE CLIENT
SET MAILCLI = 'dupont@example.org'
WHERE IDCLI = 2 ;

-- Question 11

UPDATE COMMANDE
SET DATERECEPPREVI = TO_DATE ('06/10/2013' , 'DD/MM/YYYY')
WHERE IDCLI = 1 ;

-- Question 12

DELETE FROM COMMANDE 
WHERE IDCLI = 1 ;