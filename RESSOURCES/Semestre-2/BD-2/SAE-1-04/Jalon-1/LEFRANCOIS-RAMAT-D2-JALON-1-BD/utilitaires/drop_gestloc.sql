-- ==========================
-- fichier : drop_gestloc.sql
-- base : gestloc
-- auteur(s) : LEFRANCOIS Thibaut et RAMAT Pierre
-- date : 17/11/2022
-- role : Ordres SQL pour supprimer les tables 
-- projet : AGENCE IMMOBILIERE / GESTION LOCATIVE
-- resultat dans : 
-- ==========================

DROP TABLE LOCATAIRE CASCADE CONSTRAINTS;
DROP TABLE LOCATION CASCADE CONSTRAINTS;
DROP TABLE GESTION CASCADE CONSTRAINTS;
DROP TABLE BIEN CASCADE CONSTRAINTS;
DROP TABLE PROPRIETAIRE CASCADE CONSTRAINTS;
DROP TABLE AGENCE CASCADE CONSTRAINTS;