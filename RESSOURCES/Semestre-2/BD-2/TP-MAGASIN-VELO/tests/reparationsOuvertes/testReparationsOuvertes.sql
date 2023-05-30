-- ============================================================================
-- Fichier          : testReparationOuvertes.sql
-- Auteur           : Thibaut LEFRANCOIS
-- Date             : 20/02/2023
-- Role             : tester l'ordre SQL reparationOuvertes.sql
-- Fichier resultat : reparationOuvertes.out
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
--@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\vide-contenu-base-MagasinRepVelos.sql
@../../utilitaires/vide-contenu-base-MagasinRepVelos.sql
-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ===========================================================================
--  insertion dans les relations référencées 
-- à compléter 
INSERT INTO adresse VALUES (seq_adresse.nextval, 'Rue de la paix', 'Paris', '75000');

-- Cas (1)
-- 
-- INSERT INTO client VALUES (seq_client.nextval, 'DUPONT', 'Jean', 'dupont.jean@org.com', '0102030405', seq_adresse.currval); 
-- INSERT INTO velo VALUES (seq_velo.nextval, 10) ;
-- INSERT INTO depot VALUES (seq_depot.nextval, seq_client.currval, seq_velo.currval, '06/06/2022');
-- INSERT INTO velo VALUES (seq_velo.nextval, 15) ;
-- INSERT INTO depot VALUES (seq_depot.nextval, seq_client.currval, seq_velo.currval, '08/10/2022');

-- Cas (2)
-- Client qui dépose un vélo pour réparation
-- INSERT INTO client VALUES (seq_client.nextval, 'LEFRANCOIS', 'Jean', 'durand.jean@org.com', '0102030406', seq_adresse.currval);
-- INSERT INTO velo VALUES (seq_velo.nextval, 20) ;
-- INSERT INTO depot VALUES (seq_depot.nextval, seq_client.currval, seq_velo.currval, '10/12/2022');

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- Cas (3)
-- 1 Client qui dépose pas de vélo pour réparation
-- INSERT INTO client VALUES (seq_client.nextval, 'RAMAT', 'Brandon', 'dumont.brandon@org.com', '0102030407', seq_adresse.currval);

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
SPOOL testClientsVelos.out  
PROMPT fichier resultat du test : testReparationOuvertes.out 

-- Appel du fichier de presentation
@../../utilitaires/presentation-MagasinRepVelos.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete:'
SET ECHO ON
@reparationsOuvertes.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

