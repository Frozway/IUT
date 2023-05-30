-- ============================================================================
-- Fichier          : clientsCommandes.sql
-- Auteur           : LEFRANCOIS Thibaut 
-- Date             : Novembre 2014
-- Base				: Surgeles
-- Role             : 
-- ============================================================================

SELECT C.IDCLI, C.NOMCLI, C.PRENOMCLI, 
    CASE WHEN O.IDCOM IS NULL THEN 'aucune commande' ELSE TO_CHAR(O.IDCOM) END AS IDCOM,
    CASE WHEN O.DATECOM IS NULL THEN 'aucune commande' ELSE TO_CHAR(O.DATECOM) END AS DATECOM
FROM COMMANDE O RIGHT OUTER JOIN CLIENT C
ON O.IDCLI = C.IDCLI 
ORDER BY IDCOM DESC ;