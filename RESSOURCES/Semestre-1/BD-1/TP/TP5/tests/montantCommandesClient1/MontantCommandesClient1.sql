-- ============================================================================
-- Fichier  : MontantCommandesClient.sql
-- Auteur   : LEFRANCOIS Thibaut
-- Date     : Novembre 2022
-- Projet   : surgeles
-- Role     : Calculer le montant de chaque commande du client de code 1.
-- ============================================================================


SELECT  IDCOM, SUM(LC.PRIXUNIT * LC.QTECOM) "MONTANT_TOTAL"
FROM    COMMANDE CM, LIGNE_COMMANDE LC
WHERE   CM.IDCOM = LC.IDCOM
AND     CM.IDCLI = 1
GROUP BY CM.IDCOM;
