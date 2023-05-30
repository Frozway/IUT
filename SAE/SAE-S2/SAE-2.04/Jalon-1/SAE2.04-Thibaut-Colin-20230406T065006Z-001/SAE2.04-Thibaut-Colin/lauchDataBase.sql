-- ================================================
-- Fichier : /h2r-bdd/h2r-def-dict-tables-cols.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Definition du dictionnaire de toutes les colonnes des tables de la base de données "Gestion Hotels"
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

-- ==================TOUT SUPPRIMER===================

@h2r-bdd\h2r-seq-drop.sql
@h2r-bdd\h2r-empty-database.sql
@h2r-bdd\h2r-drop-tables.sql

-- ==================TOUT RÉIMPLANTER===================

@h2r-bdd\h2r-ddl.sql
@h2r-bdd\h2r-dr.sql
@h2r-bdd\h2r-seq.sql
@h2r-bdd\h2r-ddl-modif.sql
@h2r-bdd\h2r-presentation.sql

-- ==============DICTIONNAIRE DE DONNÉES=================

@h2r-doc-bdd\h2r-def-dict-tables-cols.sql
@h2r-doc-bdd\h2r-def-dict-tables.sql
@h2r-doc-bdd\h2r-extract-dict-tables-cols.sql
@h2r-doc-bdd\h2r-extract-dict-tables.sql



