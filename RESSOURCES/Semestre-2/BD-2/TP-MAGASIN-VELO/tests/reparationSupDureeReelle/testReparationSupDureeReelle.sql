-- ==========================
-- Fichier : /tests/reparationSupDureeReelle/testReparationSupDureeReelle.sql
-- Base : MagasinRepVelos
-- Auteur : Demouge Colin D2
-- Date : 02/03/2023
-- Rôle : Test de la requête reparationSupDureeReelle.sql
-- Sortie : testReparationSupDureeReelle.out
-- Projet : BD2 - Création d'une base de données - Magasin de réparation de vélos
-- ==========================

-- ============================================================================
-- Modification du format de la date pour se conformer aux donnees du programme de test
-- ============================================================================
alter session set NLS_DATE_FORMAT='dd/mm/yyyy';

-- ============================================================================
-- Suppression des nuplets de la base de donnees
-- NB : Le test est effectué sur une base vide, il est nécessaire 
--      de supprimer tous les nuplets de toutes les relations
-- ============================================================================
@../utilitaires/vide-contenu-base-MagasinRepVelos.sql

-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ===========================================================================
--  Insertion dans les relations référencées 
INSERT INTO REPARATEUR (id_reparateur, login)
VALUES (1, 'reparateur1');

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '1');

-- CAS (1)
-- Une réparation terminee d'une duréee réelle de 9j et finie en 2023
INSERT INTO REPARATION VALUES (seq_REPARATION.nextval, 9, TO_DATE('20/12/2023', 'DD/MM/YYYY'), TO_DATE('20/12/2023', 'DD/MM/YYYY'), TO_DATE('29/12/2023', 'DD/MM/YYYY'), TO_DATE('29/12/2023', 'DD/MM/YYYY'), 'terminee', 100, seq_VELO.currval);

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- CAS (2)
-- Une réparation terminée d'une duréee réelle de 6j et finie en 2023
INSERT INTO REPARATION VALUES (seq_REPARATION.nextval, 6, TO_DATE('23/12/2023', 'DD/MM/YYYY'), TO_DATE('23/12/2023', 'DD/MM/YYYY'), TO_DATE('29/12/2023', 'DD/MM/YYYY'), TO_DATE('29/12/2023', 'DD/MM/YYYY'), 'terminee', 100, seq_VELO.currval);

-- CAS (3)
-- Une réparation terminée d'une duréee réelle de 4j et finie en 2023
INSERT INTO REPARATION VALUES (seq_REPARATION.nextval, 4, TO_DATE('25/12/2023', 'DD/MM/YYYY'), TO_DATE('25/12/2023', 'DD/MM/YYYY'), TO_DATE('29/12/2023', 'DD/MM/YYYY'), TO_DATE('29/12/2023', 'DD/MM/YYYY'), 'terminee', 100, seq_VELO.currval);

-- CAS (4)
-- Une réparation non terminée
INSERT INTO REPARATION VALUES (seq_REPARATION.nextval, 6, TO_DATE('27/12/2023', 'DD/MM/YYYY'), TO_DATE('27/12/2023', 'DD/MM/YYYY'), TO_DATE('30/12/2023', 'DD/MM/YYYY'), TO_DATE('30/12/2023', 'DD/MM/YYYY'), 'ouverte', 100, seq_VELO.currval);

-- CAS (5)
-- Une réparation terminée d'une duréee réelle de 9j et finie en 2023
INSERT INTO REPARATION VALUES (seq_REPARATION.nextval, 6, TO_DATE('20/12/2022', 'DD/MM/YYYY'), TO_DATE('20/12/2022', 'DD/MM/YYYY'), TO_DATE('29/12/2022', 'DD/MM/YYYY'), TO_DATE('29/12/2022', 'DD/MM/YYYY'), 'terminee', 100, seq_VELO.currval);

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
SPOOL testReparationSupDureeReelle.out  
PROMPT fichier resultat du test : testReparationSupDureeReelle.out 

-- Appel du fichier de presentation
@../utilitaires/presentation-MagasinRepVelos.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
@../utilitaires/affiche-contenu-base-MagasinRepVelos.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete:'
SET ECHO ON
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\tests\reparationSupDureeReelle\reparationSupDureeReelle.sql
SET echo OFF

-- Fin de l'écriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

