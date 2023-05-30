-- ================================================
-- Fichier : /h2r-bdd/h2r-def-dict-tables-cols.sql
-- Base : H2R
-- Auteurs : DEMOUGE Colin & LEFRANCOIS Thibaut D2
-- Date : 27/03/2023
-- Rôle : Definition du dictionnaire de toutes les colonnes des tables de la base de données "Gestion Hotels"
-- Projet : SAE2.04 - Exploitation d'une base de données - Gestion Hotels
-- ================================================

-- Table CUSTOMER_ADDRESS
COMMENT ON COLUMN CUSTOMER_ADDRESS.CUSTOMER IS 'Identifier of the customer who live here';
COMMENT ON COLUMN CUSTOMER_ADDRESS.POSTAL_CODE IS 'Postal code of the customer address';
COMMENT ON COLUMN CUSTOMER_ADDRESS.CITY IS 'City of the customer address';
COMMENT ON COLUMN CUSTOMER_ADDRESS.STREET_NUM IS 'Street number of the customer address';
COMMENT ON COLUMN CUSTOMER_ADDRESS.STREET_NAME IS 'Street name of the customer address';
COMMENT ON COLUMN CUSTOMER_ADDRESS.COUNTRY IS 'Country of the customer address';
COMMENT ON COLUMN CUSTOMER_ADDRESS.COUNTRY_CODE IS 'Country code of the customer address';

-- Table CUSTOMER
COMMENT ON COLUMN CUSTOMER.ID_CUSTOMER IS 'Identifier of the customer';
--COMMENT ON COLUMN CUSTOMER.ADDRESS IS 'Customer address';
COMMENT ON COLUMN CUSTOMER.FIRSTNAME IS 'First name of the customer';
COMMENT ON COLUMN CUSTOMER.LASTNAME IS 'Last name of the customer';
COMMENT ON COLUMN CUSTOMER.BIRTHDATE IS 'Birth date of the customer';
COMMENT ON COLUMN CUSTOMER.EMAIL IS 'Email of the customer';
COMMENT ON COLUMN CUSTOMER.PHONE_NUMBER IS 'Phone number of the customer';

-- Table BOOKING
COMMENT ON COLUMN BOOKING.ID_BOOKING IS 'Identifier of the booking';
COMMENT ON COLUMN BOOKING.DEPARTURE IS 'Departure date of the booking';
COMMENT ON COLUMN BOOKING.ARRIVAL IS 'Arrival date of the booking';
COMMENT ON COLUMN BOOKING.PRICE IS 'Price of the booking';
COMMENT ON COLUMN BOOKING.FEES IS 'Fees of the booking';
COMMENT ON COLUMN BOOKING.CLIENT IS 'Customer who made the booking';

-- Table ROOM_TYPE
COMMENT ON COLUMN ROOM_TYPE.ID_ROOM_TYPE IS 'Identifier of the room type';
COMMENT ON COLUMN ROOM_TYPE.BEDS_NUM IS 'Number of beds in the room type';
COMMENT ON COLUMN ROOM_TYPE.CAPACITY IS 'Capacity of the room type';
COMMENT ON COLUMN ROOM_TYPE.CONFORT_LEVEL IS 'Comfort level of the room type';

-- Table ROOM
COMMENT ON COLUMN ROOM.ID_ROOM IS 'Identifier of the room';
COMMENT ON COLUMN ROOM.HOTEL IS 'Hotel where the room is located';
COMMENT ON COLUMN ROOM.TYPE IS 'Type of the room';
COMMENT ON COLUMN ROOM.CURRENT_BOOKING IS 'Booking currently assigned to the room';
COMMENT ON COLUMN ROOM.ROOM_NO IS 'Number of the room';

-- Table HOTEL_ADDRESS
COMMENT ON COLUMN HOTEL_ADDRESS.HOTEL IS 'Identifier of the hotel located at this address';
COMMENT ON COLUMN HOTEL_ADDRESS.POSTAL_CODE IS 'Postal code of the hotel address';
COMMENT ON COLUMN HOTEL_ADDRESS.CITY IS 'City of the hotel address';
COMMENT ON COLUMN HOTEL_ADDRESS.STREET_NUM IS 'Street number of the hotel address';
COMMENT ON COLUMN HOTEL_ADDRESS.STREET_NAME IS 'Street name of the hotel address';
COMMENT ON COLUMN HOTEL_ADDRESS.COUNTRY IS 'Country of the hotel address';
COMMENT ON COLUMN HOTEL_ADDRESS.COUNTRY_CODE IS 'Country code of the hotel address';

-- Table HOTEL
COMMENT ON COLUMN HOTEL.ID_HOTEL IS 'Identifier of the hotel';
COMMENT ON COLUMN HOTEL.EMAIL IS 'Email of the hotel';
COMMENT ON COLUMN HOTEL.PHONE_NUMBER IS 'Phone number of the hotel';
COMMENT ON COLUMN HOTEL.NAME IS 'Name of the hotel';