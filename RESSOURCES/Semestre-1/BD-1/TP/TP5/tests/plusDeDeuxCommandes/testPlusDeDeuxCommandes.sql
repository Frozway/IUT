-- ============================================================================
-- Fichier          : testPlusDeDeuxCommandes.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Novembre 2022
-- Role             : test pour la requete "nombre de commandes passées par
--                    client lorsque ce nombre est supérieur ou égal à deux entre le 1er juin 2013 et le 31 ocotobre 2013".
-- Projet			: surgeles
-- Fichier resultat : testPlusDeDeuxCommandes.out
-- ============================================================================

-- ============================================================================
-- Modification du format de la date pour se conformer aux donnees du programme de test
-- ============================================================================
alter session set NLS_DATE_FORMAT='dd/mm/yyyy';

-- ============================================================================
-- Suppression des nuplets de la base de donnees
-- NB : Le test est effectué sur une base vide, il est nécessaire 
--      de supprimer tous les nuplets de toutes les relations
-- ============================================================================
@ D:/IUT/RESSOURCES/BD-1/TP/TP5/utilitaires/vider_base_surgeles.sql

-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-- CAS1 : Un client qui a passé 2 commandes dans la période

-- 1ère commande de Jean MARTIN
------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(1, 'MARTIN', 'Jean', '0505050505', 'martin@example.org', 'La Rochelle'); 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(1, 1, TO_DATE('02/06/2013', 'DD/MM/YYYY'), TO_DATE('20/06/2013', 'DD/MM/YYYY'));


-- 2ème commande de Jean MARTIN
------- Le client de la commande
-- Le client est Jean MARTIN de code 1, MEME client que pour la commande 1, donc on ne le recrée pas
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(2, 1, TO_DATE('01/10/2013', 'DD/MM/YYYY'), TO_DATE('20/12/2013', 'DD/MM/YYYY'));

-------------------------- A COMPLETER --------------------------

-- CAS2: Un client qui a passé 2 commande dans la période et une commande hors de la période

-- 1ere commande de Jean DUPONT
------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(2, 'DUPONT', 'Jean', '0606060606', 'dupont@example.org', 'La Rochelle'); 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(3, 2, TO_DATE('05/05/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));

-- 2eme commande de Jean DUPONT
------- Le client de la commande
-- Le client est Jean MARTIN de code 1, MEME client que pour la commande 3, donc on ne le recrée pas
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(4, 2, TO_DATE('23/09/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));

-- 3eme commande de Jean DUPONT
------- Le client de la commande
-- Le client est Jean DUPONT de code 1, MEME client que pour la commande 3, donc on ne le recrée pas
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(5, 2, TO_DATE('15/10/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire,
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-------------------------- A COMPLETER --------------------------

-- CAS3: Le client a passé une commande hors période

------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(3, 'DUPONT', 'Martin', '0707070707', 'dupontmartin@example.org', 'Poitiers');
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(6, 3, TO_DATE('02/02/2013', 'DD/MM/YYYY'), TO_DATE('20/06/2013', 'DD/MM/YYYY'));

-- CAS4: Le client a passé une commande dans la période

------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(4, 'CAVIN', 'Pauline', '0808080808', 'cavinpauline@example.org', 'Poitiers');
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(7, 4, TO_DATE('06/08/2013', 'DD/MM/YYYY'), TO_DATE('20/06/2013', 'DD/MM/YYYY'));

-- CAS5: Un client qui a passé une commande dans la période et une commande hors de la période

-- 1ere commande de Michel LOUP
------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(5, 'LOUP', 'Michel', '0909090909', 'michel@example.org', 'La Rochelle'); 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(8, 5, TO_DATE('22/03/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));

-- 2eme commande de Michel LOUP
------- Le client de la commande
-- Le client est Michel LOUP de code 1, MEME client que pour la commande 8, donc on ne le recrée pas
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(9, 5, TO_DATE('18/10/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));

-- CAS6: Un client qui a passé deux commandes hors de la période

-- 1ere commande de Patrick CHOUX
------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(6, 'CHOUX', 'Patrick', '1010101010', 'patrick@example.org', 'La Rochelle'); 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(10, 6, TO_DATE('02/01/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));

-- 2eme commande de Patrick CHOUX
------- Le client de la commande
-- Le client est Patrick CHOUX de code 1, MEME client que pour la commande 10, donc on ne le recrée pas
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(11, 6, TO_DATE('15/12/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));


-- ============================================================================
-- resultats a mettre dans le fichier out a nommer obligatoirement:
-- 
-- ce fichier doit contenir:	
--	1. l'etat de la base avant execution de la requete (donc juste apres 
--         les INSERT)
--	2. le texte SQL de la requete
--	3. le resultat de l'execution de la requete
-- ============================================================================

-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testPlusDeDeuxCommandes.out
PROMPT fichier resultat du test : testPlusDeDeuxCommandes.out

-- Appel du fichier de presentation
@ D:/IUT/RESSOURCES/BD-1/TP/TP5/utilitaires/presentation_surgeles.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base :
@ D:/IUT/RESSOURCES/BD-1/TP/TP5/utilitaires/afficher_base_surgeles.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
PROMPT 'Resultat de la requete:'
SET echo ON
@ D:/IUT/RESSOURCES/BD-1/TP/TP5/tests/plusDeDeuxCommandes/PlusDeDeuxCommandes.sql ;
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

