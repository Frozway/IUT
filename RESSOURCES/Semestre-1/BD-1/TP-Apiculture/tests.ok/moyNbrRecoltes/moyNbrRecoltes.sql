-- ============================================================================
-- Fichier          : moyNbrRecoltes.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Décembre 2022
-- Base				: Apiculteur 
-- Role             : Nombre de récoltes par rucher
-- ============================================================================

SELECT AVG(COUNT(*)) AS MoyNbrRecoltes
FROM RUCHE R, RECOLTE RE
WHERE R.IDRU=RE.IDRU
GROUP BY R.IDRUCHER;