-- ============================================================================
-- Fichier          : test_nom_vue.sql
-- Auteur           : 
-- Date             : Mars 2023
-- Role             : Tester la vue nom_vue
-- Fichier resultat :  test_nom_vue.out
-- ============================================================================
ALTER SESSION SET nls_date_format='dd/mm/yyyy';

set echo on
-- ============================================================================
-- Suppression des nuplet de la base de donnees
-- NB : Le test est effectué sur une base vide donc on fait 
--      la suppression de tous les nuplets de toutes les relations
-- ============================================================================
set echo off
@../utilitaires/vide-contenu-base-Magasin-Reparation-Velos.sql

set echo on
-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire. 
-- Il n'est pas possible d'avoir des collaborateurs sans competence
-- ============================================================================
set echo off

-- Insertion dans les relations référencées 
-- À compléter 



set echo on
-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================
set echo off



set echo on
-- ============================================================================
-- Etat de la base
-- ============================================================================
set echo off
-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL test_nom_vue.out
PROMPT fichier resultat du test : test_nom_vue.out 

-- Appel du fichier de presentation
@../utilitaires/presentation-Magasin-Reparation-Velos.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
@../utilitaires/affiche-contenu-base-Magasin-Reparation-Velos.sql

set echo on
-- ============================================================================
-- Afficher le contenu de la vue 
-- ============================================================================
set echo off

-- Debut de l'affichage du contenu de la vue sur le client SqlPlus
prompt 'Conteu de la vue : nom_vue'

select 
from   nom_vue	;

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

