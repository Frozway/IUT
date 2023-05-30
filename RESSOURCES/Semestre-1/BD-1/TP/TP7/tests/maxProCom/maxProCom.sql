-- ============================================================================
-- Fichier          : maxProCom.sql
-- Auteur           : C. Faucher
-- Date             : Novembre 2015
-- Base             : Surgeles
-- Role             : Quel est le nombre maximum de produit commandés par commande ?
-- ============================================================================

SET MARKUP HTML ON SPOOL ON PREFORMAT OFF ENTMAP ON
- HEAD " - " - BODY "TEXT='#000000'"
- TABLE "WIDTH='90%' BORDER='5'" @testMaxProCom.sql SPOOL maxProCom.html @maxProCom.sql SPOOL OFF

SPOOL report.html

-- Requête IV du T6 
SELECT MAX(SUM(QTECOM)) AS maxProCom
FROM LIGNE_COMMANDE
GROUP BY IDCOM ;

--Nouvelle requete avec compute
COMPUTE SUM LABEL NbrProCom OF QTECOM ON IDCOM ;
BREAK ON IDCOM SKIP 1 ;
SELECT IDCOM, IDPRO, QTECOM
FROM COMMANDE NATURAL JOIN LIGNE_COMMANDE ;

SPOOL OFF 