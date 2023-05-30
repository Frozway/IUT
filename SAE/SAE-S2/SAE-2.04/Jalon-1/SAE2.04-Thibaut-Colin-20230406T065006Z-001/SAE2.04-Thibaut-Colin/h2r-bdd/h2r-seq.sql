-- ================================================
-- Fichier : /h2r-bdd/h2r-seq.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Définition de la création des séquences sur les clés primaires
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

-- SEQUENCES POUR LES TABLES

-- Sequence pour CUSTOMER
CREATE SEQUENCE SEQ_CUSTOMER
INCREMENT BY 1
START WITH 1
MINVALUE 1
NOCYCLE
CACHE 20;

-- Sequence pour BOOKING
CREATE SEQUENCE SEQ_BOOKING
INCREMENT BY 1
START WITH 1
MINVALUE 1
NOCYCLE
CACHE 20;

-- Sequence pour ROOM
CREATE SEQUENCE SEQ_ROOM
INCREMENT BY 1
START WITH 1
MINVALUE 1
NOCYCLE
CACHE 20;

-- Sequence pour HOTEL
CREATE SEQUENCE SEQ_HOTEL
INCREMENT BY 1
START WITH 1
MINVALUE 1
NOCYCLE
CACHE 20;