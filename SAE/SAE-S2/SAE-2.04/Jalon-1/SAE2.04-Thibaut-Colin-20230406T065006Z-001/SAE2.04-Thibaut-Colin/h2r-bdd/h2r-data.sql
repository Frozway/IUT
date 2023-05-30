-- ================================================
-- Fichier : /h2r-bdd/h2r-data.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Jeu de données de la base
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

-- ======================================================================================================================================
-- Insertion des clients
-- Premier client
INSERT INTO CUSTOMER (ID_CUSTOMER, FIRSTNAME, LASTNAME, BIRTHDATE, EMAIL, PHONE_NUMBER)
VALUES (SEQ_CUSTOMER.nextval, 'Jean', 'Dupont', TO_DATE('1990-05-14', 'YYYY-MM-DD'), 'jean.dupont@mail.com', 0612345678);

INSERT INTO CUSTOMER_ADDRESS (CUSTOMER, POSTAL_CODE, CITY, STREET_NUM, STREET_NAME, COUNTRY, COUNTRY_CODE)
VALUES (SEQ_CUSTOMER.currval, 75001, 'Paris', 1, 'Rue de Rivoli', 'France', 'FRA');

-- Insertion de réservation
INSERT INTO BOOKING (ID_BOOKING, DEPARTURE, ARRIVAL, PRICE, FEES, CLIENT, DURATION)
VALUES (SEQ_BOOKING.nextval, TO_DATE('2023-04-03', 'YYYY-MM-DD'), TO_DATE('2023-04-01', 'YYYY-MM-DD'), 120, 10, SEQ_CUSTOMER.currval, 2);

-- ======================================================================================================================================

-- Deuxième client
INSERT INTO CUSTOMER (ID_CUSTOMER, FIRSTNAME, LASTNAME, BIRTHDATE, EMAIL, PHONE_NUMBER)
VALUES (SEQ_CUSTOMER.nextval, 'Sophie', 'Lefèvre', TO_DATE('1988-02-23', 'YYYY-MM-DD'), 'sophie.lefevre@mail.com', 0676543210);

INSERT INTO CUSTOMER_ADDRESS (CUSTOMER, POSTAL_CODE, CITY, STREET_NUM, STREET_NAME, COUNTRY, COUNTRY_CODE)
VALUES (SEQ_CUSTOMER.currval, 69002, 'Lyon', 5, 'Rue de la République', 'France', 33);

INSERT INTO BOOKING (ID_BOOKING, DEPARTURE, ARRIVAL, PRICE, FEES, CLIENT, DURATION)
VALUES (SEQ_BOOKING.nextval, TO_DATE('2023-04-21', 'YYYY-MM-DD'), TO_DATE('2023-04-18', 'YYYY-MM-DD'), 200, 20, SEQ_CUSTOMER.currval, 3);

-- ======================================================================================================================================

-- Insertion des types de chambres
INSERT INTO ROOM_TYPE (ID_ROOM_TYPE, BEDS_NUM, CAPACITY, CONFORT_LEVEL)
VALUES (1, 1, 2, 'ECONOMY');

INSERT INTO ROOM_TYPE (ID_ROOM_TYPE, BEDS_NUM, CAPACITY, CONFORT_LEVEL)
VALUES (2, 2, 3, 'STANDARD');

INSERT INTO ROOM_TYPE (ID_ROOM_TYPE, BEDS_NUM, CAPACITY, CONFORT_LEVEL)
VALUES (3, 2, 4, 'LUXE');

INSERT INTO ROOM_TYPE (ID_ROOM_TYPE, BEDS_NUM, CAPACITY, CONFORT_LEVEL)
VALUES (4, 4, 6, 'PRESTIGE');

-- ======================================================================================================================================

-- Insertion d'un hotel
INSERT INTO HOTEL (ID_HOTEL, EMAIL, PHONE_NUMBER, NAME)
VALUES (SEQ_HOTEL.nextval,'hotel@paix.fr', 0240884088, 'Hotel de la Paix');

INSERT INTO HOTEL_ADDRESS (HOTEL, POSTAL_CODE, CITY, STREET_NUM, STREET_NAME, COUNTRY, COUNTRY_CODE)
VALUES (SEQ_HOTEL.currval, 75001, 'Paris', 5, 'Rue de la Paix', 'France', 'FRA');

-- ======================================================================================================================================

-- Insertion des chambres
INSERT INTO ROOM (ID_ROOM, HOTEL, TYPE, CURRENT_BOOKING, ROOM_NO)
VALUES (1, SEQ_HOTEL.currval, 1, NULL, 101);

INSERT INTO ROOM (ID_ROOM, HOTEL, TYPE, CURRENT_BOOKING, ROOM_NO)
VALUES (2, SEQ_HOTEL.currval, 2, SEQ_BOOKING.currval, 102);



