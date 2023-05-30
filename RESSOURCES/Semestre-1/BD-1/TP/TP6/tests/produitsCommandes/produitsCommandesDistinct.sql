-- ============================================================================
-- Fichier          : produitsCommandesDistinct.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Novembre 2014
-- Base				: Surgeles
-- Role             : 
-- ============================================================================

SELECT DISTINCT L.IDPRO, P.NOMPRO
FROM LIGNE_COMMANDE L, PRODUIT P
WHERE L.IDPRO = P.IDPRO ;
