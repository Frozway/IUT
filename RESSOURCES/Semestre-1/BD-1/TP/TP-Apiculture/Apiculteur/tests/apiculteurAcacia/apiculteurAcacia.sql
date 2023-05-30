-- ============================================================================
-- Fichier          : apiculteurAcacia.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Novembre 2022
-- Base				: Apiculture
-- Role             : Création des relations
-- ============================================================================

SELECT * IDAPI 
FROM RUCHER NATURAL JOIN APICULTEUR
WHERE TYPEMIEL = 'acacia' ;