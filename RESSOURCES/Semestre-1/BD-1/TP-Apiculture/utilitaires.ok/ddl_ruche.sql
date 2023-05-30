-- ============================================================================
-- Fichier          : ddl_api.sql
-- Auteur           : LEFRANCOIS Thibaut
-- Date             : Novembre 2022
-- Base				: Apiculture
-- Role             : Création des relations
-- Fichier de sortie: ddl_api.out
-- ============================================================================

@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\drop_ruche.sql
--Création des tables
CREATE TABLE APICULTEUR(
IDAPI	NUMBER(4)	NOT NULL,
NOMAPI	VARCHAR2(40)	NOT NULL,
PRENOMAPI	VARCHAR2(40)	NOT NULL,
TELAPI	VARCHAR2(40)	NOT NULL,
MAILAPI	VARCHAR2(80)	NULL,
ADRAPI	VARCHAR2(255)	NOT NULL,
CONSTRAINT PK_APICULTEUR PRIMARY KEY (IDAPI)
);

CREATE TABLE RUCHER(
IDRUCHER	NUMBER(4)	NOT NULL,
TYPEMIEL	VARCHAR2(60)	NOT NULL,
CONSTRAINT PK_RUCHER PRIMARY KEY (IDRUCHER)
);

CREATE TABLE RUCHE(
IDRU	NUMBER(4)	NOT NULL,
NBCADRE	NUMBER(2)	NOT NULL,
IDAPI	NUMBER(4)	NOT NULL,
IDRUCHER	NUMBER(4)	NOT NULL,
CONSTRAINT PK_RUCHE PRIMARY KEY (IDRU)
);

CREATE TABLE RECOLTE(
IDRU	NUMBER(4)	NOT NULL,
DATEREC DATE	NOT NULL,
MASSE	NUMBER(4,3)	NOT NULL,
CONSTRAINT PK_RECOLTE PRIMARY KEY (IDRU, DATEREC)
);

@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\dr_ruche.sql