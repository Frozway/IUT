-- ============================================================================
-- Fichier          : drop_api.sql
-- Auteur           : C. Faucher
-- Date             : Novembre 2022
-- Base				: Apiculture
-- Role             : Suppression des tables et contraintes associées
-- ============================================================================

DROP TABLE APICULTEUR CASCADE CONSTRAINTS;
DROP TABLE RUCHER CASCADE CONSTRAINTS;
DROP TABLE RUCHE CASCADE CONSTRAINTS;
DROP TABLE RECOLTE CASCADE CONSTRAINTS;
