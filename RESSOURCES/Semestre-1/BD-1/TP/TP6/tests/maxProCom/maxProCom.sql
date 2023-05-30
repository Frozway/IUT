-- ============================================================================
-- Fichier          : maxProCom.sql
-- Auteur           : C. Faucher
-- Date             : Novembre 2015
-- Base             : Surgeles
-- Role             : Quel est le nombre maximum de produit commandés par commande ?
-- ============================================================================

BREAK ON REPORT 
COMPUTE MAX LABEL MAX_PROCOM OF MAX_PROCOM ON REPORT
SELECT IDCOM, SUM(IDPRO) AS MAX_PROCOM
FROM COMMANDE C NATURAL JOIN LIGNE_COMMANDE
GROUP BY IDCOM ;