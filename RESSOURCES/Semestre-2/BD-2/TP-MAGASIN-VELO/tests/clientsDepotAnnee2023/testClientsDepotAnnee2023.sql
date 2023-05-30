-- ==========================
-- Fichier : /tests/clientsDepotAnnee2023/testClientsDepotAnnee2023.sql
-- Base : MagasinRepVelos
-- Auteur : Demouge Colin D2
-- Date : 02/03/2023
-- Rôle : Test de la requête clientsDepotAnnee2023.sql
-- Spertie : testClientsDepotAnnee2023.out
-- Projet : BD2 - Création d'une base de données - Magasin de réparation de vélos
-- ==========================

-- ============================================================================
-- Modification du format de la date pour se conformer aux donnees du programme de test
-- ============================================================================
alter session set NLS_DATE_FORMAT='dd/mm/yyyy';

-- ============================================================================
-- Suppression des nuplets de la base de donnees
-- NB : Le test est effectué sur une base vide, il est nécessaire 
--      de supprimer tous les nuplets de toutes les relations
-- ============================================================================
@../../utilitaires/vide-contenu-base-MagasinRepVelos.sql

-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================
--  Insertion dans les relations référencées 
INSERT INTO ADRESSE(id_adresse, intitule, commune, code_postal) 
VALUES (seq_ADRESSE.nextval, 'rue de la paix', 'Paris', '75000');

INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'DUPONT', 'Jean', seq_ADRESSE.currval, '0123456789', 'jeandupont@hotmail.com');

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '1');

-- CAS (1)
-- Une Client qui a déposé le même vélo en 2022 et en 2023
INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/10/2022', 'DD/MM/YYYY'));

INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2023', 'DD/MM/YYYY'));

-- Insertion dans les relations référencées
INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'DROUET', 'Melissa', seq_ADRESSE.currval, '0728639223', 'meloche@hotmail.com');

-- CAS (2)
-- Une Cliente qui a déposé deux vélos différents en 2023
INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '2');

INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('28/10/2023', 'DD/MM/YYYY'));

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '3');

INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('12/04/2023', 'DD/MM/YYYY'));

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- CAS (3)
-- Un Client qui a déposé un vélo en 2020
INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'PINAUT', 'Mathis', seq_ADRESSE.currval, '0763928333', 'pinthis@hotmail.com');

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '4');

INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('28/10/2020', 'DD/MM/YYYY'));

-- ============================================================================
-- resultats a mettre dans le fichier a nommer obligatoirement:
-- 
-- ce fichier doit contenir:	
--	1. l'etat de la base avant execution de la requete (donc juste apres 
--         les INSERT)
--	2. le texte SQL de la requete
--	3. le resultat de l'execution de la requete
-- ============================================================================

-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testClientsDepotAnnee2023.out  
PROMPT fichier resultat du test : testClientsDepotAnnee2023.out 

-- Appel du fichier de presentation
@../../utilitaires/presentation-MagasinRepVelos.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
@../../utilitaires/affiche-contenu-base-MagasinRepVelos.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete:'
SET ECHO ON
@clientsDepotAnnee2023.sql
SET echo OFF

-- Fin de l'écriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

