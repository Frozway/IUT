-- ============================================================================
-- Fichier          : testApiculteurAcacia.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Décembre 2022
-- Base				: Apiculteur
-- Role             : Quels sont les apiculteurs qui produisent du miel de type « acacia » 
-- Fichier resultat : testApiculteurAcacia.out
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

@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\TP-Apiculture\Apiculteur\utilitaires\vider_base_ruche.sql

-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-- CAS1

------- Le client qui n'a PAS de commande 

INSERT INTO APICULTEUR (IDAPI, NOMAPI, PRENOMAPI, TELAPI, MAILAPI, ADRAPI)
VALUES(1, 'LEFRANCOIS', 'Thibaut', '01 02 03 04 05', 'thibaut.apiculture@org', 'adresse thibaut')

INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(1, 'MARTIN', 'Jean', '0505050505', 'martin@example.org', 'La Rochelle'); 

------- Un client avec UNE commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(2, 'DEMOUGE', 'Colin', '0102030405', 'colin@example.org', 'La Rochelle'); 

INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(1, 2, TO_DATE('05/05/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));



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
@ C:\Users\tibol\Desktop\IUT\RESSOURCES\BD-1\TP\TP7\utilitaires\presentation_surgeles.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base :
@ C:\Users\tibol\Desktop\IUT\RESSOURCES\BD-1\TP\TP7\utilitaires\afficher_base_surgeles.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================
prompt 'Resultat de la requete avec le case'
SET echo ON
@ C:\Users\tibol\Desktop\IUT\RESSOURCES\BD-1\TP\TP7\tests\clientsCommandes\clientsCommandes.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

