-- ============================================================================
-- Fichier          : moyNbrRecoltes.sql
-- Auteur           : 
-- Date             : 
-- Base				: 
-- Role             : 
-- ============================================================================

SELECT AVG(COUNT(*)) AS MoyNbrRecoltes
FROM RUCHE R, RECOLTE RE
WHERE R.IDRU=RE.IDRU
GROUP BY R.IDRUCHER;