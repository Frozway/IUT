-- ============================================================================
-- Fichier          : testNbrCommandeClient.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Novembre 2022
-- Role             : test pour la requete "nombre de commandes passées
--					  pour chaque client".
-- Projet			: surgeles
-- Fichier resultat : testNbrCommandeClient.out
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

-- CAS1 : Un client qui a passé 2 commandes

-- 1ère commande de Jean MARTIN
------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(1, 'MARTIN', 'Jean', '0505050505', 'martin@example.org', 'La Rochelle'); 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(1, 1, TO_DATE('01/05/2013', 'DD/MM/YYYY'), TO_DATE('20/06/2013', 'DD/MM/YYYY'));


-- 2ème commande de Jean MARTIN
------- Le client de la commande
-- Le client est Jean MARTIN de code 1, MEME client que pour la commande 1, donc on ne le recrée pas
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(3, 1, TO_DATE('01/10/2013', 'DD/MM/YYYY'), TO_DATE('20/12/2013', 'DD/MM/YYYY'));

-------------------------- A COMPLETER --------------------------

-- CAS2: Un client qui a passé 1 commande

-- commande de Jean DUPONT
------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(2, 'DUPONT', 'Jean', '0606060606', 'dupont@example.org', 'La Rochelle'); 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(2, 2, TO_DATE('23/09/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire,
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-------------------------- A COMPLETER --------------------------

-- CAS3: Le client n'a pas passé de commande

------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(3, 'DUPONT', 'Martin', '0707070707', 'dupontmartin@example.org', 'Poitiers'); 


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
SPOOL testNbrCommandeClient.out
PROMPT fichier resultat du test : testNbrCommandeClient.out

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
@ D:/IUT/RESSOURCES/BD-1/TP/TP5/tests/nbrCommandeClient/nbrCommandeClient.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

