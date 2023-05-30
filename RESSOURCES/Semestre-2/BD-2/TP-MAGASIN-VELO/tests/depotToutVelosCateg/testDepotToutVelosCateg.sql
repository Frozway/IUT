-- ============================================================================
-- Fichier          : testClientsVelos.sql
-- Auteur           : Thibaut LEFRANCOIS
-- Date             : 20/02/2023
-- Role             : tester l'ordre SQL clientsVelos.sql
-- Fichier resultat : testClientsVelos.out
-- ============================================================================

-- ============================================================================
-- Modification du format de la date pour se conformer aux donnees du programme de test
-- ============================================================================
alter session set NLS_DATE_FORMAT='dd/mm/yyyy';

-- ============================================================================
-- Suppression des nuplets de la base de donnees
-- NB : Le test est effectué sur une base vide, il est nécessaire 
--      de supprimer tous les nuplets de toutes les relations
-- ============================================================================
--@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\vide-contenu-base-MagasinRepVelos.sql
@../utilitaires/vide-contenu-base-MagasinRepVelos.sql
-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ===========================================================================
--  insertion dans les relations référencées 
-- à compléter 

-- Cas (1)
-- Un client qui à déposé toutes les catégories de vélos
INSERT INTO ADRESSE(id_adresse, intitule, commune, code_postal) 
VALUES (seq_ADRESSE.nextval, 'rue de la paix', 'Paris', '75000');
INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'DUPONT', 'Jean', seq_ADRESSE.currval, '0123456789', 'jeandupont@hotmail.com');

INSERT INTO VELO (num_velo) VALUES ('1');
INSERT INTO DETAIL_VELO (velo, marque, type, categ, taille, date_fabrication) VALUES (seq_VELO.currval, 1, 1, 1, 1, TO_DATE('01/01/2019', 'DD/MM/YYYY'));
INSERT INTO DEPOT (client, velo, date_depot) VALUES (seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

INSERT INTO VELO (num_velo) VALUES ('2');
INSERT INTO DETAIL_VELO (velo, marque, type, categ, taille, date_fabrication) VALUES (seq_VELO.currval, 2, 2, 2, 2, TO_DATE('01/01/2019', 'DD/MM/YYYY'));
INSERT INTO DEPOT (client, velo, date_depot) VALUES (seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

INSERT INTO VELO (num_velo) VALUES ('3');
INSERT INTO DETAIL_VELO (velo, marque, type, categ, taille, date_fabrication) VALUES (seq_VELO.currval, 3, 3, 3, 3, TO_DATE('01/01/2019', 'DD/MM/YYYY'));
INSERT INTO DEPOT (client, velo, date_depot) VALUES (seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- Cas (2)
--Un client qui à déposé que 2 catégories de vélos
INSERT INTO ADRESSE(id_adresse, intitule, commune, code_postal) 
VALUES (seq_ADRESSE.nextval, 'rue de la paix', 'La Rochelle', '17000');
INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'LEFRANCOIS', 'Thibaut', seq_ADRESSE.currval, '0101010101', 'test@hotmail.com');

INSERT INTO VELO (num_velo) VALUES ('4');
INSERT INTO DETAIL_VELO (velo, marque, type, categ, taille, date_fabrication) VALUES (seq_VELO.currval, 1, 1, 1, 1, TO_DATE('01/01/2019', 'DD/MM/YYYY'));
INSERT INTO DEPOT (client, velo, date_depot) VALUES (seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

INSERT INTO VELO (num_velo) VALUES ('5');
INSERT INTO DETAIL_VELO (velo, marque, type, categ, taille, date_fabrication) VALUES (seq_VELO.currval, 2, 2, 2, 2, TO_DATE('01/01/2019', 'DD/MM/YYYY'));
INSERT INTO DEPOT (client, velo, date_depot) VALUES (seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

-- ===================================================================
-- resultats a mettre dans le fichier a nommer obligatoirement:
-- 
-- ce fichier doit contenir:	
--	1. l'etat de la base avant execution de la requete (donc juste apres 
--         les INSERT)
--	2. le texte SQL de la requete
--	3. le resultat de l'execution de la requete
-- ============================================================================

-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testClientsVelos.out  
PROMPT fichier resultat du test : testClientsVelos.out 

-- Appel du fichier de presentation
@../utilitaires/presentation-MagasinRepVelos.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 

-- ============================================================================
-- Requete a tester 
-- ============================================================================

-- Debut de l'affichage du resultat de la requete sur le client SqlPlus
prompt 'Resultat de la requete:'
SET ECHO ON
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\tests\depotToutVelosCateg\depotToutVelosCateg.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

