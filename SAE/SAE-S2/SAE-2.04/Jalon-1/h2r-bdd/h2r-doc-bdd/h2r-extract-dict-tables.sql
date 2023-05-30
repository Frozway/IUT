-- ================================================
-- Fichier : /h2r-bdd/h2r-doc-bdd/h2r-extract-dict-tables.sql
-- Base : H2R
-- Auteurs : Demouge Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Extractions des comments des tables de la base de données "Gestion Hotels"
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

-- Ordre SQL pour supprimer les tables qui sont dans la corbeille 
purge recyclebin; 

-- Extraction du dictionnaire des tables en HTML 
SET pagesize 80

SET MARKUP HTML ON SPOOL ON PREFORMAT OFF ENTMAP OFF - 
HEAD '<title>Description des tables</title> - 
<style type="text/css">table.myTable { border-collapse:collapse; }- 
table.myTable td, table.myTable th { border:1px solid black;padding:5px; } </style>' - 
TABLE "class='myTable'"

TTITLE '<h3>Description of the relations of the database : Hotel management</h3>'


SPOOL h2r-dict-tables.html

-- debut de l'ordre SQL d'extration

SELECT TABLE_NAME AS "Table", 
COMMENTS AS "Description"
FROM USER_TAB_COMMENTS ORDER BY TABLE_NAME;

-- fin de l'ordre SQL d'extration

SPOOL OFF      
SET MARKUP HTML OFF

