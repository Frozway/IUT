-- ============================================================================
-- Fichier          : nbrRuchesApiculteur.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Décembre 2022
-- Base				: Ruche/apiculteur
-- Role             : Afficher nombre de ruches par IDAPI
-- ============================================================================

SELECT IDAPI, NOMAPI, PRENOMAPI, COUNT(*) AS NbrRuches
FROM APICULTEUR NATURAL JOIN RUCHE 
GROUP BY IDAPI, NOMAPI, PRENOMAPI ;


