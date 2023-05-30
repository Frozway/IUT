-- ============================================================================
-- Fichier          : ddl_api.sql
-- Auteur           : C. Faucher
-- Date             : Novembre 2022
-- Base				: Apiculture
-- Role             : Création des relations
-- Fichier de sortie: ddl_api.out
-- ============================================================================

@ C:\Users\tibol\Desktop\TP-Apiculture\utilitaires\drop_api.sql

--Création des tables
CREATE TABLE APICULTEUR(
IDAPI	NUMBER(4)	NOT NULL,
NOMAPI	VARCHAR2(40)	NOT NULL,
PRENOMAPI	VARCHAR2(40)	NOT NULL,
TELAPI	VARCHAR2(10)	NOT NULL,
MAILAPI	VARCHAR2(80)	NULL,
ADRAPI	VARCHAR2(255)	NOT NULL
);

CREATE TABLE RUCHER(
IDRUCHER	NUMBER(4)	NOT NULL,
TYPEMIEL	VARCHAR2(6)	NOT NULL
);

CREATE TABLE RUCHE(
IDRU	NUMBER(4)	NOT NULL,
NBCADRE	NUMBER(2)	NOT NULL,
IDAPI	NUMBER(4)	NOT NULL,
IDRUCHER	NUMBER(4)	NOT NULL
);

CREATE TABLE RECOLTE(
IDRU	NUMBER(4)	NOT NULL,
DATEREC DATE	NOT NULL,
MASSE	NUMBER(4,3)	NOT NULL
);

@ C:\Users\tibol\Desktop\TP-Apiculture\utilitaires\dr_api.sql