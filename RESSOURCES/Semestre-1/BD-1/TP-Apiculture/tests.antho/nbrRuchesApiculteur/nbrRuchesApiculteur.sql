-- ============================================================================
-- Fichier          : nbrRuchesApiculteur.sql
-- Auteur           : 
-- Date             : 
-- Base				: 
-- Role             : 
-- ============================================================================

SELECT A.IDAPI, A.NOMAPI, A.PRENOMAPI, COUNT(*) AS NbrRuches
FROM APICULTEUR A, RUCHE B
WHERE A.IDAPI=B.IDAPI
GROUP  BY A.IDAPI, A.NOMAPI, A.PRENOMAPI;