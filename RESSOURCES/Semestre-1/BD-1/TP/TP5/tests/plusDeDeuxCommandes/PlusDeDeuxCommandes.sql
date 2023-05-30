-- ============================================================================
-- Fichier  : PlusDeDeuxCommandes.sql
-- Auteur   : Dupont Achille
-- Date     : Novembre 2022
-- Projet   : surgeles
-- Role     : Afficher le nombre de commandes passées par
--            client lorsque ce nombre est supérieur ou égal à deux entre le 1er juin 2013 et le 31 ocotobre 2013.
-- ============================================================================

SELECT  CL.IDCLI, CL.NOMCLI, CL.PRENOMCLI, COUNT(*) NBRCOMMANDECLIENT
FROM    CLIENT CL, COMMANDE CM
WHERE   CL.IDCLI = CM.IDCLI AND 
        DATECOM >= TO_DATE('01/06/2013', 'DD/MM/YYYY') AND
        DATECOM <= TO_DATE('31/10/2013', 'DD/MM/YYYY')
GROUP BY CL.IDCLI, CL.NOMCLI, CL.PRENOMCLI
HAVING COUNT(*) >= 2;

