
-- ============================================================================
-- Fichier          : extract-dict-tables-MagasinRepVelos.sql
-- Auteur           : 
-- Date             : Janvier 2023
-- Role             : Extractions des comments des tables de la base
--					de données "Magasin Réparation Vélos"
-- Fichier resultat : dict-tables-MagasinRepVelos.html
-- ============================================================================
-- Ordre SQL pour supprimer les tables qui sont dans la corbeille 
purge recyclebin; 

-- Extraction du dictionnaire des tables en HTML 
SET pagesize 80
SET MARKUP HTML ON SPOOL ON PREFORMAT OFF ENTMAP OFF - 
HEAD '<title>Description des colonnes des tables</title> - 
<style type="text/css">table.myTable { border-collapse:collapse; }- 
table.myTable td, table.myTable th { border:1px solid black;padding:5px; } </style>' - 
TABLE "class='myTable'"

TTITLE '<h3>Description des relations de la bases de donnees : Magasin Reparation Velos</h3>'

SPOOL dict-tables-MagasinRepVelos.html

-- debut de l'ordre SQL d'extration

SELECT TABLE_NAME AS "Table", 
COMMENTS AS "Description"
FROM USER_TAB_COMMENTS ORDER BY TABLE_NAME;

-- fin de l'ordre SQL d'extration

SPOOL OFF      
SET MARKUP HTML OFF

