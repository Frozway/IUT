-- ============================================================================
-- Fichier          : appartLibre.sql
-- Auteur           : LEFRANCOIS Thibaut & RAMAT Pierre
-- Date             : Janvier 2023
-- Base				: Agence Immobilière
-- Role             : Connaître les appartements libres du réseau d'une agence
-- ============================================================================

COMPUTE COUNT LABEL 'Louable' OF STATUT_BIEN ON REPORT
BREAK ON REPORT 
SELECT ID_AGENCE, ID_PROPRIO, ID_BIEN, STATUT_BIEN
FROM BIEN NATURAL JOIN PROPRIETAIRE NATURAL JOIN AGENCE
WHERE STATUT_BIEN = 'Louable' ;
