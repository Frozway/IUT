-- ============================================================================
-- Fichier          : nbrTotalProCom.sql
-- Auteur           : C. Faucher
-- Date             : Novembre 2015
-- Base             : Surgeles
-- Role             : Quel est le nombre total de produits commandés par commande, le
--                    résultat doit comporter le numéro du client, le numéro de la commande et il
--                    est ordonné du plus grand nombre total vers le plus petit ?
-- ============================================================================

SELECT IDCLI, IDCOM, SUM(QTECOM) AS nbrTotal
FROM CLIENT NATURAL JOIN COMMANDE NATURAL JOIN LIGNE_COMMANDE
GROUP BY IDCLI, IDCOM 
ORDER BY SUM(QTECOM) DESC;
