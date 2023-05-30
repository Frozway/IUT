-- ================================================
-- Fichier : /h2r-bdd/h2r-dr.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Définition des dépendances de références de la base de données
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

-- Définition des clés étrangères
ALTER TABLE CUSTOMER_ADDRESS
ADD CONSTRAINT FK_CUSTOMER_ADDRESS FOREIGN KEY (customer)
REFERENCES CUSTOMER (id_customer);

ALTER TABLE BOOKING
ADD CONSTRAINT FK_BOOKING_CUSTOMER FOREIGN KEY (client)
REFERENCES CUSTOMER (id_customer);

ALTER TABLE ROOM 
ADD CONSTRAINT FK_ROOM_HOTEL FOREIGN KEY (hotel)
REFERENCES HOTEL (id_hotel);

ALTER TABLE ROOM
ADD CONSTRAINT FK_ROOM_TYPE FOREIGN KEY (type)
REFERENCES ROOM_TYPE (id_room_type);

ALTER TABLE ROOM
ADD CONSTRAINT FK_ROOM_BOOKING FOREIGN KEY (current_booking)
REFERENCES BOOKING (id_booking);

ALTER TABLE HOTEL_ADDRESS
ADD CONSTRAINT FK_HOTEL_ADDRESS FOREIGN KEY (hotel)
REFERENCES HOTEL (id_hotel);