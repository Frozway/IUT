-- ============================================================================
-- Fichier          : clientsCommandesUnion.sql
-- Auteur           : C. Faucher
-- Date             : Novembre 2014
-- Base				: Surgeles
-- Role             : 
-- ============================================================================

SELECT IDCLI, NOMCLI, PRENOMCLI, IDCOM, DATECOM
FROM COMMANDE, CLIENT
WHERE COMMANDE.IDCLI = CLIENT.IDCLI
UNION
SELECT DISTINCT IDCLI, NOMCLI, PRENOMCLI, NULL, NULL
FROM COMMANDE
WHERE NOT EXISTS (SELET * FROM CLIENT WHERE COMMANDE.IDCLI = CLIENT.IDCLI) ;