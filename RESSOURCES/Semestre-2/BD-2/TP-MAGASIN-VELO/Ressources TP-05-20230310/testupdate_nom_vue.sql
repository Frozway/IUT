-- ============================================================================
-- Fichier : testUPDATE_NOM_VUE.sql 
-- Auteur  : 	
-- Date    : Mars 2023
-- Role    : tester l'utilisation de la vue NOM_VUE en UPDATE
-- ============================================================================
ALTER SESSION SET nls_date_format='dd/mm/yyyy';

-- ============================================================================
-- NB : le test est effectué sur une base vide, donc on fait la
-- suppression de tous les nuplets de toutes les relations.
-- Prise en charge des dependances de reference dans l'ordre de suppression
-- du contenu des relations de la base de donnees. 
-- ============================================================================
@../utilitaires/vide-contenu-base-Magasin-Reparation-Velos.sql

set echo on
-- ============================================================================
-- Insertion dans les relations referencees 
-- ============================================================================
set echo off


--=============================================================================
-- Creation du fichier resultat
--=============================================================================
SPOOL testUPDATE_NOM_VUE.out

set echo on
--=============================================================================
-- Etat de la base avant UPDATE 
--=============================================================================
set echo off

@../utilitaires/presentation-Magasin-Reparation-Velos.sql
@../utilitaires/affiche-contenu-base-Magasin-Reparation-Velos.sql

set echo on
-- ============================================================================
--  Tester UPDATE d'un nuplet à travers la vue NOM_VUE
-- ============================================================================
-- Contenu de la vue avant UPDATE 
select 
from   NOM_VUE;

-- Update d'un nuplet à travers la vue NOM_VUE


-- Contenu de la vue apres UPDATE
select 
from   NOM_VUE;

set echo off

set echo on
--=============================================================================
-- Etat de la base apres UPDATE 
--=============================================================================
set echo off
@../utilitaires/affiche-contenu-base-Magasin-Reparation-Velos.sql

-- ============================================================================
-- Fin programme de test
-- ============================================================================
spool off 
