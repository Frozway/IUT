-- ================================================
-- Fichier : /h2r-bdd/h2r-ddl-modif.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Modification des tables concernées par les séquences
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

ALTER TABLE CUSTOMER MODIFY
ID_CUSTOMER DEFAULT SEQ_CUSTOMER.NEXTVAL;

ALTER TABLE BOOKING MODIFY
ID_BOOKING DEFAULT SEQ_BOOKING.NEXTVAL;

ALTER TABLE ROOM MODIFY
ID_ROOM DEFAULT SEQ_ROOM.NEXTVAL;

ALTER TABLE HOTEL MODIFY
ID_HOTEL DEFAULT SEQ_HOTEL.NEXTVAL;

