-- ================================================
-- Fichier : /h2r-bdd/h2r-ddl.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Définition de la base de donnée : Création des tables
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

-- CUSTOMER_ADDRESS
-- CUSTOMER
-- BOOKING
-- ROOM_TYPE
-- ROOM
-- HOTEL_ADDRESS
-- HOTEL

-- CREATION DES TABLES

CREATE TABLE CUSTOMER_ADDRESS
(
  CUSTOMER             NUMBER(6) NOT NULL,
  POSTAL_CODE          NUMBER(5) NOT NULL,
  CITY                 VARCHAR2(20) NOT NULL,
  STREET_NUM           NUMBER(4) NOT NULL,
  STREET_NAME          VARCHAR2(30) NOT NULL,
  COUNTRY              VARCHAR2(20) NOT NULL,
  COUNTRY_CODE         VARCHAR2(3) NOT NULL,
  CONSTRAINT PK_CUSTOMER_ADDRESS PRIMARY KEY (CUSTOMER)
);

CREATE TABLE CUSTOMER (
  ID_CUSTOMER  NUMBER(6) NOT NULL,
  FIRSTNAME    VARCHAR2(30) NOT NULL,
  LASTNAME     VARCHAR2(30) NOT NULL,
  BIRTHDATE    DATE DEFAULT SYSDATE NOT NULL,
  EMAIL        VARCHAR2(30) NULL,
  PHONE_NUMBER NUMBER(10) NOT NULL,
  CONSTRAINT PK_CUSTOMER PRIMARY KEY (ID_CUSTOMER),
  CONSTRAINT UQ_CUSTOMER UNIQUE (EMAIL)
);

CREATE TABLE BOOKING (
  ID_BOOKING  NUMBER(6) NOT NULL,
  DEPARTURE   DATE NOT NULL,
  ARRIVAL     DATE NOT NULL,
  PRICE       NUMBER(5) NOT NULL,
  FEES        NUMBER NOT NULL,
  CLIENT      NUMBER NOT NULL,
  DURATION    NUMBER(3) NOT NULL,
  CONSTRAINT PK_BOOKING PRIMARY KEY (ID_BOOKING),
  CONSTRAINT CK_DATES CHECK(DEPARTURE >= ARRIVAL)
);

CREATE TABLE ROOM_TYPE (
  ID_ROOM_TYPE  NUMBER(5) NOT NULL,
  BEDS_NUM      NUMBER NOT NULL,
  CAPACITY      NUMBER NOT NULL,
  CONFORT_LEVEL VARCHAR2(10) NOT NULL,
  CONSTRAINT PK_ROOM_TYPE PRIMARY KEY (ID_ROOM_TYPE),
  CONSTRAINT CK_ROOM_TYPE_CONFORT_LEVEL CHECK (CONFORT_LEVEL IN ('ECONOMY', 'STANDARD', 'LUXE', 'PRESTIGE'))
);

CREATE TABLE ROOM (
  ID_ROOM           NUMBER(7) NOT NULL,
  HOTEL             NUMBER(5) NOT NULL,
  TYPE              NUMBER NOT NULL,
  CURRENT_BOOKING   NUMBER NULL,
  ROOM_NO           NUMBER NOT NULL,
  CONSTRAINT PK_ROOM PRIMARY KEY (ID_ROOM)
);

CREATE TABLE HOTEL_ADDRESS (
  HOTEL             NUMBER(5) NOT NULL,
  POSTAL_CODE       NUMBER NOT NULL,
  CITY              VARCHAR2(50) NOT NULL,
  STREET_NUM        NUMBER NOT NULL,
  STREET_NAME       VARCHAR2(50) NOT NULL,
  COUNTRY           VARCHAR2(50) NOT NULL,
  COUNTRY_CODE      VARCHAR2(3) NOT NULL,
  CONSTRAINT PK_HOTEL_ADDRESS PRIMARY KEY (HOTEL)
);

CREATE TABLE HOTEL (
  ID_HOTEL      NUMBER(5) NOT NULL,
  EMAIL         VARCHAR2(30) NOT NULL,
  PHONE_NUMBER  NUMBER(10) NOT NULL,
  NAME          VARCHAR2(50) NOT NULL,
  CONSTRAINT UQ_HOTEL UNIQUE (EMAIL),
  CONSTRAINT PK_HOTEL PRIMARY KEY (ID_HOTEL)
);