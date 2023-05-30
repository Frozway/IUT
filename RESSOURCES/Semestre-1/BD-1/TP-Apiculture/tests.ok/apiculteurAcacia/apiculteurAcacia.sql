-- ============================================================================
-- Fichier          : apiculteurAcacia.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Décembre 2022
-- Base				: Ruche/apiculteur
-- Role             : Afficher IDAPI qui font 'acacia'
-- ============================================================================

SELECT DISTINCT IDAPI
FROM APICULTEUR NATURAL JOIN RUCHER 
WHERE TYPEMIEL='acacia';