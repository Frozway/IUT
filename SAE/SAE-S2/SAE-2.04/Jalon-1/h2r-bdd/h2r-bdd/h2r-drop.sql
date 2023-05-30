-- ================================================
-- Fichier : /h2r-bdd/h2r-drop.sql
-- Base : H2R
-- Auteurs : Demouge Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Définition des suppression de tables
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

DROP TABLE CUSTOMER CASCADE CONSTRAINTS;
DROP TABLE CUSTOMER_ADDRESS CASCADE CONSTRAINTS;
DROP TABLE BOOKING CASCADE CONSTRAINTS;
DROP TABLE ROOM_TYPE CASCADE CONSTRAINTS;
DROP TABLE ROOM CASCADE CONSTRAINTS;
DROP TABLE HOTEL_ADDRESS CASCADE CONSTRAINTS;
DROP TABLE HOTEL CASCADE CONSTRAINTS;