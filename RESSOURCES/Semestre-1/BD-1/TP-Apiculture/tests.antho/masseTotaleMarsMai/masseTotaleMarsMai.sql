-- ============================================================================
-- Fichier          : masseTotaleMarsMai.sql
-- Auteur           : 
-- Date             : 
-- Base				: 
-- Role             : 
-- ============================================================================

SELECT R.TYPEMIEL, SUM(T.MASSE) AS MASSETOTALE
FROM RUCHER R, RUCHE S, RECOLTE T
WHERE T.DATEREC BETWEEN TO_DATE('01/03/2018','DD/MM/YYYY') AND TO_DATE('31/05/2018','DD/MM/YYYY')
AND S.IDRU = T.IDRU
AND R.IDRUCHER = S.IDRUCHER
GROUP BY R.TYPEMIEL;