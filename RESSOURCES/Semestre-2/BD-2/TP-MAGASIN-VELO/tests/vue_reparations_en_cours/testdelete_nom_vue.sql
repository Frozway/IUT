-- ============================================================================
-- Fichier : testDELETE_vue_reparations_en_cours.sql 
-- Auteur  : 		
-- Date    : 10/03/2023
-- Role    : tester l'utilisation de la vue vue_NOM_VUE en UPDATE
-- ============================================================================
ALTER SESSION SET nls_date_format='dd/mm/yyyy';

-- ============================================================================
-- NB : le test est effectué sur une base vide, donc on fait la
-- suppression de tous les nuplets de toutes les relations.
-- Prise en charge des dependances de reference dans l'ordre de suppression
-- du contenu des relations de la base de donnees. 
-- ============================================================================
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\vide-contenu-base-MagasinRepVelos.sql

set echo on
-- ============================================================================
-- Insertion dans les relations referencees 
-- ============================================================================
set echo off


--=============================================================================
-- Creation du fichier resultat
--=============================================================================
SPOOL testDELETE_NOM_VUE.out

set echo on
--=============================================================================
-- Etat de la base avant DELETE 
--=============================================================================
set echo off

@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\presentation-MagasinRepVelos.sql
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\affiche-contenu-base-MagasinRepVelos.sql

set echo on
-- ============================================================================
--  Tester DELETE d'un nuplet à travers la vue NOM_VUE
-- ============================================================================
-- Contenu de la vue avant DELETE 
select *
from   vue_NOM_VUE;

-- Delete d'un nuplet à travers la vue NOM_VUE

--A FAIREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

-- Contenu de la vue apres DELETE
select 
from   vue_reparations_en_cours;

set echo off

set echo on
--=============================================================================
-- Etat de la base apres DELETE 
--=============================================================================
set echo off
@../utilitaires/affiche-contenu-base-Magasin-Reparation-Velos.sql

-- ============================================================================
-- Fin programme de test
-- ============================================================================
spool off 
