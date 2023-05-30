-- ================================================
-- Fichier : /h2r-bdd/h2r-presentation.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Gérer la présentation des tables lors de l'affichage de données
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

SET UNDERLINE =
SET LINESIZE 150

-- Présentation de la table CUSTOMER
COLUMN FIRSTNAME FORMAT A10;
COLUMN LASTNAME FORMAT A10;
COLUMN EMAIL FORMAT A30;
COLUMN BIRTHDATE FORMAT A9;

--Présentation de la table HOTEL
COLUMN NAME FORMAT A30;

--Présentation de la table HOTEL_ADDRESS et CLIENT_ADDRESS
COLUMN COUNTRY FORMAT A15;
COLUMN COUNTRY_CODE FORMAT A12;
COLUMN CITY FORMAT A15;
COLUMN STREET_NAME FORMAT A30;