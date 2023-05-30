-- ============================================================================
-- Fichier  : nbrCommandeClient.sql
-- Auteur   : LEFRANCOIS Thibaut
-- Date     : Novembre 2016
-- Projet   : surgeles
-- Role     : Quel est le nombre de commandes passées pour chaque client ?
-- ============================================================================

SELECT  CL.IDCLI, CL.NOMCLI, CL.PRENOMCLI, COUNT(*) NBRCOMMANDECLIENT
FROM    CLIENT CL, COMMANDE CM
WHERE   CL.IDCLI = CM.IDCLI
GROUP BY CL.IDCLI, CL.NOMCLI, CL.PRENOMCLI;
