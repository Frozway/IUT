-- ==========================
-- fichier 	: ddl_achat_fournisseur.sql
-- base 	: achat_fournisseur
-- auteur(s): Cyril Faucher
-- date 	: 19/09/2022
-- role 	: cr�er toutes les relations de la base + les contraintes
-- projet 	: achat_fournisseur
-- resultat dans 	: ddl_achat_fournisseur.out
-- ==========================

spool ddl_achat_fournisseur.out

--Cr�ation des tables
CREATE TABLE MAGASIN(
CODEMAG	NUMBER(4)	NOT NULL,
NOMMAG	VARCHAR2(50)	NOT NULL,
ADRMAG	VARCHAR2(50)	NOT NULL,
CONSTRAINT PK_MAGASIN PRIMARY KEY (CODEMAG),
CONSTRAINT UNQ_NOMMAG UNIQUE (NOMMAG)
);

set echo on
DESC MAGASIN;
set echo off


CREATE TABLE FOURNISSEUR(
CODEFOUR	NUMBER(4)	NOT NULL,
NOMFOUR	VARCHAR2(50)	NOT NULL,
ADRFOUR	VARCHAR2(50)	NOT NULL,
CONSTRAINT PK_FOURNISSEUR PRIMARY KEY (CODEFOUR),
CONSTRAINT UNQ_NOMFOUR UNIQUE (NOMFOUR)
);

set echo on
DESC FOURNISSEUR;
set echo off

CREATE TABLE PRODUIT(
CODEPRO	NUMBER(4)	NOT NULL,
NOMPRO	VARCHAR2(50)	NOT NULL,
CONSTRAINT PK_PRODUIT PRIMARY KEY (CODEPRO)
);

set echo on
DESC PRODUIT;
set echo off

CREATE TABLE COMMANDE(
NOCOM	NUMBER(4)	NOT NULL,
DATECOM	DATE	NOT NULL,
CODEMAG	NUMBER(4)	NOT NULL,
CONSTRAINT PK_COMMANDE PRIMARY KEY (NOCOM)
);

set echo on
DESC COMMANDE;
set echo off

CREATE TABLE LIGNE_COMMANDE(
NOLIGCOM	NUMBER(4)	NOT NULL,
NOCOM	NUMBER(4)	NOT NULL,
NOCOND	NUMBER(4)	NOT NULL,
QTECOM	NUMBER(2)	NOT NULL,
CONSTRAINT PK_LIGNE_COMMANDE PRIMARY KEY (NOLIGCOM),
CONSTRAINT CHK_QTECOM CHECK (QTECOM>0)
);

set echo on
DESC LIGNE_COMMANDE;
set echo off


CREATE TABLE CONDITION_ACHAT(
NOCOND	NUMBER(4)	NOT NULL,
CODEPRO	NUMBER(4)	NOT NULL,
CODEFOUR	NUMBER(4)	NOT NULL,
DELAPP	NUMBER(2)	NOT NULL,
PRIXACH	NUMBER(4,2)	NOT NULL,
CONSTRAINT PK_CONDITION_ACHAT PRIMARY KEY (NOCOND),
CONSTRAINT CHK_PRIXACH CHECK (PRIXACH>0)
);

set echo on
DESC CONDITION_ACHAT;
set echo off


CREATE TABLE STOCK(
CODEPRO	NUMBER(4)	NOT NULL,
CODEMAG	NUMBER(4)	NOT NULL,
QTEDISP	NUMBER(4)	NOT NULL,
QTECRIT	NUMBER(4)	NOT NULL,
DATEMAJ	DATE		NOT NULL,
CONSTRAINT PK_STOCK PRIMARY KEY (CODEPRO, CODEMAG)
);

set echo on
DESC STOCK;
set echo off

CREATE TABLE LIVRAISON(
NOLIV	NUMBER(4)	NOT NULL,
NOLIGCOM	NUMBER(4)	NOT NULL,
DATELIV	DATE	NOT NULL,
QTERECPT	NUMBER(2)	NOT NULL,
CONSTRAINT PK_LIVRAISON PRIMARY KEY (NOLIV)
);

set echo on
DESC LIVRAISON;
set echo off

spool off
