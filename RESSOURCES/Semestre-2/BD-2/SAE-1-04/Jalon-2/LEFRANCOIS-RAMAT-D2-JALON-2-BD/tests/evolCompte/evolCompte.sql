-- ============================================================================
-- Fichier          : evolCompte.sql
-- Auteur           : LEFRANCOIS Thibaut & RAMAT Pierre
-- Date             : Janvier 2023
-- Base				: Agence
-- Role             : Montrer le solde actuel de chaque agence du PDG du réseau de celles ci
-- ============================================================================

COMPUTE SUM LABEL 'TOTAL' OF SOLDE_AGENCE ON REPORT 
BREAK ON REPORT 
SELECT ID_AGENCE, NOM_AGENCE, IBAN_AGENCE, SOLDE_AGENCE
FROM AGENCE ;

