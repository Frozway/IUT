-- ============================================================================
-- Fichier          : clientsCommandes.sql
-- Auteur           : C. Faucher
-- Date             : Novembre 2014
-- Base				: Surgeles
-- Role             : 
-- ============================================================================

SELECT IDCLI, NOMCLI, PRENOMCLI, IDCOM, DATECOM
FROM COMMANDE RIGHT OUTER JOIN CLIENT 
ON COMMANDE.IDCLI = CLIENT.IDCLI ; 