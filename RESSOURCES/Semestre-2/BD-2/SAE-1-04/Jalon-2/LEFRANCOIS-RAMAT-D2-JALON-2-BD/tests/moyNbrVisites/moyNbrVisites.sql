-- ============================================================================
-- Fichier          : evolCompte.sql
-- Auteur           : LEFRANCOIS Thibaut & RAMAT Pierre
-- Date             : Janvier 2023
-- Base				: Agence
-- Role             : Connaître le nombre moyen de visites nécessaires avant d'avoir conclu
-- ============================================================================


COMPUTE AVG LABEL 'Moyenne' OF NB_VISITE ON REPORT
BREAK ON REPORT 
SELECT ID_AGENCE, ID_BIEN, ADR_BIEN, TYPE_BIEN, STATUT_BIEN, NB_VISITE
FROM BIEN NATURAL JOIN PROPRIETAIRE NATURAL JOIN AGENCE
WHERE STATUT_BIEN = 'Occupe' ;

