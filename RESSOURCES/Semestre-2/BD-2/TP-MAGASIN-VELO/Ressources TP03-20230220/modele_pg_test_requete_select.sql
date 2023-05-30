-- ============================================================================
-- Fichier          : test...sql
-- Auteur           : 
-- Date             : 
-- Role             : tester l'ordre SQL ...sql
-- Fichier resultat : test...out
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
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\vide-contenu-base-MagasinRepVelos.sql

-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ===========================================================================
--  insertion dans les relations référencées 
-- à compléter 


-- Cas (numero)
-- texte du cas 
-- à compléter 


-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- Cas (numero)
-- texte du cas 
-- à compléter 


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
SPOOL test...out  
PROMPT fichier resultat du test : test...out 

-- Appel du fichier de presentation
@../utilitaires/presentation-Magasin-Reparation-Velos.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
@../utilitaires/affiche-contenu-base-Magasin-Reparation-Velos.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete:'
SET ECHO ON
@...sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

