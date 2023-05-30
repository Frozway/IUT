-- ============================================================================
-- fichier : ddl-Magasin-Reparation-Velos.sql
-- auteur : LEFRANCOIS Thibaut
-- date : janvier 2023
-- role : creation des tables de la base de donnees
-- ============================================================================

--9 contraintes check


CREATE TABLE adresse
(
  id_adresse  NUMBER        NOT NULL,
  intitule     VARCHAR2(500) NOT NULL,
  commune     VARCHAR2(50)  NOT NULL,
  code_postal VARCHAR2(10)  NOT NULL,
  CONSTRAINT PK_adresse PRIMARY KEY (id_adresse)
);

CREATE TABLE taille_velo
(
  id_taille NUMBER NOT NULL,
  libelle   VARCHAR2(20) NOT NULL,
  CONSTRAINT PK_taille_velo PRIMARY KEY (id_taille),
  CONSTRAINT UQ_taille_velo UNIQUE(libelle),
  CONSTRAINT CK_taille_velo CHECK (libelle IN ('XS', 'S', 'M', 'M/L', 'L/XL', 'XL/XXL'))
);

CREATE TABLE type_velo
(
  id_type NUMBER       NOT NULL,
  libelle VARCHAR2(20) NOT NULL,
  CONSTRAINT PK_type_velo PRIMARY KEY (id_type),
  CONSTRAINT UQ_type_velo UNIQUE(libelle),
  CONSTRAINT CK_libelle_type CHECK (libelle IN ('VTT', 'VTC', 'VAE', 'CARGO', 'HOLLANDAIS', 'PLIANT'))
);

CREATE TABLE categ_velo
(
  id_categ NUMBER       NOT NULL,
  libelle  VARCHAR2(20) NOT NULL,
  CONSTRAINT PK_categ_velo PRIMARY KEY (id_categ),
  CONSTRAINT UQ_categ_velo UNIQUE(libelle),
  CONSTRAINT CK_categ_velo_libelle CHECK (libelle IN ('femme', 'homme', 'enfant'))
);

CREATE TABLE marque_velo
(
  id_marque NUMBER       NOT NULL,
  libelle   VARCHAR2(20) NOT NULL,
  CONSTRAINT PK_marque_velo PRIMARY KEY (id_marque),
  CONSTRAINT UQ_marque_velo UNIQUE(libelle),
  CONSTRAINT CK_marque_velo_libelle CHECK (libelle IN ('btwin', 'gitane', 'nakamura', 'trek'))
);

CREATE TABLE client
( 
  id_client NUMBER        NOT NULL,
  nom       VARCHAR2(20)  NOT NULL,
  prenom    VARCHAR2(20)  NOT NULL,
  email     VARCHAR2(100) NOT NULL,
  tel       CHAR(10)      NOT NULL,
  adresse   NUMBER        NOT NULL,
  CONSTRAINT PK_client PRIMARY KEY (id_client),
  CONSTRAINT UQ_client UNIQUE(email)
);

CREATE TABLE depot
(
  id_depot   NUMBER NOT NULL,
  client     NUMBER NOT NULL,
  velo       NUMBER NOT NULL,
  date_depot DATE DEFAULT SYSDATE  NOT NULL ,
  CONSTRAINT PK_depot PRIMARY KEY (id_depot)
);

CREATE TABLE detail_velo
(
  id_detail_velo NUMBER NOT NULL,
  velo           NUMBER NOT NULL,
  marque         NUMBER NOT NULL,
  type           NUMBER NOT NULL,
  categ          NUMBER NOT NULL,
  taille         NUMBER NOT NULL, 
  date_fabrication DATE,
  CONSTRAINT PK_detail_velo PRIMARY KEY (id_detail_velo)        
);

CREATE TABLE facture
(
  id_facture    NUMBER NOT NULL,
  date_emission DATE   NOT NULL,
  montant       NUMBER NOT NULL,
  reparation    NUMBER NOT NULL,
  CONSTRAINT PK_facture PRIMARY KEY (id_facture)
);

CREATE TABLE operation
(
  id_operation      NUMBER       NOT NULL,
  intitule          VARCHAR2(50) NOT NULL,
  duree_prevue      NUMBER       NOT NULL,
  date_debut_reelle DATE,
  date_fin_reelle   DATE,
  etat              CHAR(10)     NOT NULL,
  cout              NUMBER,
  reparation        NUMBER, 
  reparateur        NUMBER, 
  CONSTRAINT PK_operation PRIMARY KEY (id_operation),
  CONSTRAINT CK_operation_etat CHECK (etat IN ('ouverte', 'encours', 'annulee', 'terminee'))
);

CREATE TABLE reglement
(
  id_reglement   NUMBER NOT NULL,
  date_reglement DATE NOT NULL,
  montant        NUMBER NOT NULL,
  facture        NUMBER NOT NULL,
  CONSTRAINT PK_reglement PRIMARY KEY (id_reglement)
);

CREATE TABLE reparation
(
  id_reparation     NUMBER NOT NULL,
  duree_prevue      NUMBER NOT NULL,
  date_debut_prevue DATE   NOT NULL,
  date_debut_reelle DATE       NULL,
  date_fin_prevue   DATE   NOT NULL,
  date_fin_reelle   DATE       NULL,
  etat              CHAR(10) DEFAULT 'ouverte' NOT NULL,
  cout_total        NUMBER DEFAULT 0 NULL,
  velo              NUMBER NOT NULL,
  CONSTRAINT PK_reparation PRIMARY KEY (id_reparation),
  CONSTRAINT UQ_reparation UNIQUE (velo, date_debut_prevue),
  CONSTRAINT CK_reparation_etat CHECK (lower(etat) IN ('ouverte', 'encours', 'annulee', 'terminee')),
  CONSTRAINT CK_dates_prevues CHECK(date_fin_prevue >= date_debut_prevue),
  CONSTRAINT CK_dates_debut_1 CHECK( (date_debut_reelle IS NULL) OR (date_debut_reelle >= date_debut_prevue) ),
  CONSTRAINT CK_dates_debut_2 CHECK( (date_fin_reelle IS NULL) OR ( (date_debut_reelle IS NOT NULL) AND (date_fin_reelle >= date_debut_reelle)))
);

CREATE TABLE reparateur
(
  id_reparateur NUMBER       NOT NULL,
  login         VARCHAR2(20) NOT NULL,
  CONSTRAINT PK_reparateur PRIMARY KEY (id_reparateur)
);

CREATE TABLE velo
(
  id_velo  NUMBER        NOT NULL,
  num_velo VARCHAR2(100) NOT NULL,
  CONSTRAINT PK_velo PRIMARY KEY (id_velo),
  CONSTRAINT UQ_velo UNIQUE (num_velo)
);


