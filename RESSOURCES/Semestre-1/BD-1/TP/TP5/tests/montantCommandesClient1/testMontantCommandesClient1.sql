-- ============================================================================
-- Fichier          : testMontantCommandesClient1.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Novembre 2022
-- Role             : test pour la requete "calculer le montant de chaque commande du client de code 1".
-- Projet			: surgeles
-- Fichier resultat : testMontantCommandesClient1.out
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

-- CAS1 : Le client de code 1 qui a passé une commande qui contient une ligne de commande(idcom=1): prixunit=13.2 ; qtecom=5

------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(1, 'MARTIN', 'Jean', '0505050505', 'martin@example.org', 'La Rochelle'); 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(1, 1, TO_DATE('02/06/2013', 'DD/MM/YYYY'), TO_DATE('20/06/2013', 'DD/MM/YYYY'));
------- Un produit
INSERT INTO PRODUIT (IDPRO, NOMPRO, TYPEPRO)
VALUES (1, 'steak', 'viande');
------- La ligne de commande correspondante
INSERT INTO LIGNE_COMMANDE (IDLIGCOM, QTECOM, PRIXUNIT, IDPRO, IDCOM)
VALUES (1, 5, 13.2, 1, 1);

-------------------------- A COMPLETER --------------------------

-- CAS2: Le client de code 1 qui a passé une commande qui contient deux lignes de commande: (idcom=2): prix_unit=23.87 ; qtecom=7
--                                                                              (idcom=2): prix_unit=54.543 ; qtecom=9

-- 1ere commande de Jean MARTIN 
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(2, 1, TO_DATE('05/05/2013', 'DD/MM/YYYY'), TO_DATE('12/11/2013', 'DD/MM/YYYY'));
------- Un produit
INSERT INTO PRODUIT (IDPRO, NOMPRO, TYPEPRO)
VALUES (2, 'saumon', 'poisson');
------- Un autre produit
INSERT INTO PRODUIT (IDPRO, NOMPRO, TYPEPRO)
VALUES (3, 'chocolat', 'dessert');
------- 1ere ligne de commande
INSERT INTO LIGNE_COMMANDE (IDLIGCOM, QTECOM, PRIXUNIT, IDPRO, IDCOM)
VALUES (2, 7, 23.87, 2, 2);
------- 2eme ligne de commande 
INSERT INTO LIGNE_COMMANDE (IDLIGCOM, QTECOM, PRIXUNIT, IDPRO, IDCOM)
VALUES (3, 9, 54.543, 3, 2);

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire,
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-------------------------- A COMPLETER --------------------------

-- CAS3: Le client de code 2 passe une commande

------- Le client de la commande
INSERT INTO CLIENT (IDCLI, NOMCLI, PRENOMCLI, TELCLI, MAILCLI, ADRCLI)
VALUES(2, 'DUPONT', 'Martin', '0707070707', 'dupontmartin@example.org', 'Poitiers');
------- La commande passée par le client
INSERT INTO COMMANDE (IDCOM, IDCLI, DATECOM, DATERECEPPREVI)
VALUES(3, 2, TO_DATE('02/02/2013', 'DD/MM/YYYY'), TO_DATE('20/06/2013', 'DD/MM/YYYY'));
------- Ligne de commande correspondante
INSERT INTO LIGNE_COMMANDE (IDLIGCOM, QTECOM, PRIXUNIT, IDPRO, IDCOM)
VALUES (4, 2, 12.65, 2, 3);

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
SPOOL testMontantCommandesClient1.out
PROMPT fichier resultat du test : testMontantCommandesClient1.out

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

