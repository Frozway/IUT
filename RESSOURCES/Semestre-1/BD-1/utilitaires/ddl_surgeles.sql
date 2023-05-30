-- ==========================
-- fichier : ddl_surgeles.sql
-- base : surgeles
-- auteur(s) : Dupont Achille
-- date : 14/10/22
-- role : role de ce fichier
-- projet : surgelés
-- resultat dans : nom_du_fichier.out (si ce fichier produit une sortie)
-- ==========================

spool \\qi.univ-lr.fr\homes\Windows\Mes_Documents\BD1\TP3\ddl_surgeles.out


CREATE TABLE CLIENT
(
  idcli     NUMBER   NOT NULL,
  nomcli    VARCHAR2(32) NOT NULL,
  prenomcli VARCHAR2(32) NOT NULL,
  adrcli    VARCHAR2(32) NOT NULL,
  telcli    NUMBER   NOT NULL,
  mailcli   VARCHAR2(32) NULL,
  CONSTRAINT PK_CLIENT PRIMARY KEY (idcli)
);
set echo on
DESC CLIENT
set echo off

CREATE TABLE COMMANDE
(
  idcom      NUMBER   NOT NULL,
  datecom    DATE     NOT NULL,
  datelivest DATE     NOT NULL,
  idcli      NUMBER   NOT NULL,
  CONSTRAINT PK_COMMANDE PRIMARY KEY (idcom)
);
prompt Description de la table commande:
DESC COMMANDE

CREATE TABLE LIGNE_COMMANDE
(
  idligcom  NUMBER(4) NOT NULL,
  qtecom    NUMBER NOT NULL,
  prix_unit NUMBER(5, 2) NOT NULL,
  idpro     NUMBER NOT NULL,
  idcom     NUMBER NOT NULL,
  CONSTRAINT CHK_qtecom CHECK (qtecom > 0),
  CONSTRAINT PK_LIGNE_COMMANDE PRIMARY KEY (idligcom)
);
DESC LIGNE_COMMANDE

CREATE TABLE LIVRAISON
(
  datelivreal DATE   NOT NULL,
  idcom       NUMBER NOT NULL,
  idliv       NUMBER NOT NULL,
  CONSTRAINT PK_LIVRAISON PRIMARY KEY (idcom, idliv)
);
DESC LIVRAISON

CREATE TABLE LIVREUR
(
  idliv     NUMBER   NOT NULL,
  nomliv    VARCHAR2(32) NOT NULL,
  prenomliv VARCHAR2(32) NOT NULL,
  CONSTRAINT PK_LIVREUR PRIMARY KEY (idliv)
);
DESC LIVREUR

CREATE TABLE PRODUIT
(
  idpro   NUMBER   NOT NULL,
  nompro  VARCHAR2(32) NOT NULL,
  typepro VARCHAR2(32) NOT NULL,
  CONSTRAINT CHK_typepro CHECK (typepro in ('viande', 'poisson', 'dessert')),
  CONSTRAINT PK_PRODUIT PRIMARY KEY (idpro)
);
DESC PRODUIT

spool off