-- ================================================
-- Fichier : /h2r-bdd/h2r-empty-database.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Supprime le conttenu de toutes les tables de la base de données
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

DELETE FROM ROOM;
DELETE FROM HOTEL_ADDRESS;
DELETE FROM HOTEL;
DELETE FROM BOOKING;
DELETE FROM CUSTOMER_ADDRESS;
DELETE FROM CUSTOMER;
DELETE FROM ROOM_TYPE;