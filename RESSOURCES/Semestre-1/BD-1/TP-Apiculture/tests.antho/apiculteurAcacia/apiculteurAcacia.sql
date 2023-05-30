-- ============================================================================
-- Fichier          : apiculteurAcacia.sql
-- Auteur           : 
-- Date             : 
-- Base				: 
-- Role             : 
-- ============================================================================

SELECT DISTINCT R.IDAPI
FROM RUCHE R,RUCHER RU
WHERE RU.TYPEMIEL='acacia'
AND R.IDRUCHER=RU.IDRUCHER;
