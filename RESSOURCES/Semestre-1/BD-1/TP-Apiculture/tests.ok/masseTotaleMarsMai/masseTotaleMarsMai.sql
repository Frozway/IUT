-- ============================================================================
-- Fichier          : masseTotaleMarsMai.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Décembre 2022
-- Base				: Apiculteur
-- Role             : Masse totale de miel récolté entre mars 2022 et mai 2022 par type de miel
-- ============================================================================

SELECT R.TYPEMIEL, SUM(T.MASSE) AS MASSETOTALE
FROM RUCHER R, RUCHE S, RECOLTE T
WHERE T.DATEREC BETWEEN TO_DATE('01/03/2022','DD/MM/YYYY') AND TO_DATE('31/05/2022','DD/MM/YYYY')
AND S.IDRU = T.IDRU
AND R.IDRUCHER = S.IDRUCHER
GROUP BY R.TYPEMIEL;