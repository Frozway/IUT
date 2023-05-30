-- ============================================================================
-- Fichier          : appartInlouable.sql
-- Auteur           : LEFRANCOIS Thibaut & RAMAT Pierre
-- Date             : Janvier 2023
-- Base				: Agence Immobilière
-- Role             : Connaître le nombre de biens inlouables dû à leur DPE
-- ============================================================================

COMPUTE COUNT LABEL 'Inlouable' OF STATUT_BIEN ON REPORT
BREAK ON REPORT 
SELECT ID_AGENCE, ID_PROPRIO, ID_BIEN, STATUT_RENOV, CLASS_DPE, STATUT_BIEN
FROM BIEN NATURAL JOIN PROPRIETAIRE NATURAL JOIN AGENCE 
WHERE CLASS_DPE IN ('E', 'F', 'G')
AND STATUT_BIEN = 'Inlouable'  ;



