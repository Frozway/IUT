-- ============================================================================
-- Fichier          : testClientsCommandes.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Novembre 2014
-- Base				: Surgeles
-- Role             : 
-- Fichier resultat : testClientsCommandes.out
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

@ D:\IUT\RESSOURCES\BD-1\TP\TP6\utilitaires\vider_base_surgeles.sql
-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-- CAS1

------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(1, 'MARTIN', 'Jean', '0505050505', 'martin@example.org', 'La Rochelle'); 

-- 1ere commande de Jean MARTIN 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(1, 1, TO_DATE('05/05/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));
------- Un produit
INSERT INTO PRODUIT (IDPRO, NOMPRO, TYPEPRO)
VALUES (2, 'saumon', 'poisson');
------- Un autre produit
INSERT INTO PRODUIT (IDPRO, NOMPRO, TYPEPRO)
VALUES (3, 'chocolat', 'dessert');
------- Un autre produit
INSERT INTO PRODUIT (IDPRO, NOMPRO, TYPEPRO)
VALUES (4, 'chocolat', 'dessert');
------- 1ere ligne de commande
INSERT INTO LIGNE_COMMANDE (IDLIGCOM, QTECOM, PRIXUNIT, IDPRO, IDCOM)
VALUES (1, 7, 23.87, 2, 1);
------- 2eme ligne de commande 
INSERT INTO LIGNE_COMMANDE (IDLIGCOM, QTECOM, PRIXUNIT, IDPRO, IDCOM)
VALUES (2, 9, 54.543, 3, 1);
------- 3eme ligne de commande 
INSERT INTO LIGNE_COMMANDE (IDLIGCOM, QTECOM, PRIXUNIT, IDPRO, IDCOM)
VALUES (3, 9, 54.543, 3, 1);

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- CASn
-- VOTRE COMMENTAIRE


-- ============================================================================
-- resultats a mettre dans le fichier a nommer obligatoirement:
-- 
-- ce fichier doit contenir:	
--	1. l'etat de la base avant execution de la requete (donc juste apres 
--         les INSERT)
--	2. le texte SQL de la requete
--	3. le resultat de l'execution de la requete
-- ============================================================================

-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testClientsCommandes.out  
PROMPT fichier resultat du test : testClientsCommandes.out 

-- Appel du fichier de presentation
@ D:\IUT\RESSOURCES\BD-1\TP\TP6\utilitaires\presentation_surgeles.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base :
@ D:\IUT\RESSOURCES\BD-1\TP\TP6\utilitaires\afficher_base_surgeles.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================
prompt 'Resultat de la requete avec Distinct'
SET echo ON
D:\IUT\RESSOURCES\BD-1\TP\TP6\tests\clientsCommandes\clientsCommandes.sql
SET echo OFF

prompt 'Resultat de la requete sans Distinct'
SET echo ON
D:\IUT\RESSOURCES\BD-1\TP\TP6\tests\clientsCommandes\clientsCommandesUnion.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

