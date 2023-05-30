-- ==========================
-- Fichier :  modele-insertion-MagasinRepVelos.sql
-- Base : MagasinRepVelos
-- Auteur : Demouge Colin D2
-- Date : 30/01/2023
-- Rôle : modele d'insertion des nuplets dans les relations de la base de donnees "Magasin Réparation Vélo" 
-- Projet : BD2 - Création d'une base de données - Magasin de réparation de vélos
-- ==========================

alter session set nls_date_format='dd/mm/yyyy';

-- ================================================
-- TABLE ADRESSE
-- ================================================
INSERT INTO ADRESSE(id_adresse, intitule, commune, code_postal) 
VALUES (seq_ADRESSE.nextval, 'rue de la paix', 'Paris', '75000');

-- ================================================
-- TABLE CATEG_VELO
-- ================================================
INSERT INTO CATEG_VELO(id_categ, libelle) VALUES (1, 'femme');
INSERT INTO CATEG_VELO(id_categ, libelle) VALUES (2, 'homme');
INSERT INTO CATEG_VELO(id_categ, libelle) VALUES (3, 'enfant');


-- ================================================
-- TABLE CLIENT
-- ================================================
INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'DUPONT', 'Jean', seq_ADRESSE.currval, '0123456789', 'jeandupont@hotmail.com');

-- ================================================
-- TABLE TYPE_VELO
-- ================================================
INSERT INTO TYPE_VELO (id_type, libelle) VALUES (1, 'VTC');
INSERT INTO TYPE_VELO (id_type, libelle) VALUES (2, 'VTT');
INSERT INTO TYPE_VELO (id_type, libelle) VALUES (3, 'VAE');
INSERT INTO TYPE_VELO (id_type, libelle) VALUES (4, 'CARGO');
INSERT INTO TYPE_VELO (id_type, libelle) VALUES (5, 'HOLLANDAIS');
INSERT INTO TYPE_VELO (id_type, libelle) VALUES (6, 'PLIANT');


-- ================================================
-- TABLE VELO
-- ================================================
INSERT INTO VELO (id_velo, num_velo)
VALUES (seq_VELO.nextval, '123456789');

-- ================================================
-- TABLE DEPOT
-- ================================================
INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

-- ================================================
-- TABLE TAILLE_VELO
-- ================================================
INSERT INTO TAILLE_VELO (id_taille, libelle) VALUES (1, 'S');
INSERT INTO TAILLE_VELO (id_taille, libelle) VALUES (2, 'M');
INSERT INTO TAILLE_VELO (id_taille, libelle) VALUES (3, 'L/XL');
INSERT INTO TAILLE_VELO (id_taille, libelle) VALUES (4, 'M/L');
INSERT INTO TAILLE_VELO (id_taille, libelle) VALUES (5, 'XL/XXL');
INSERT INTO TAILLE_VELO (id_taille, libelle) VALUES (6, 'XS');


-- ================================================
-- TABLE MARQUE_VELO
-- ================================================
INSERT INTO MARQUE_VELO (id_marque, libelle) VALUES (1, 'nakamura');
INSERT INTO MARQUE_VELO (id_marque, libelle) VALUES (2, 'trek');
INSERT INTO MARQUE_VELO (id_marque, libelle) VALUES (3, 'btwin');
INSERT INTO MARQUE_VELO (id_marque, libelle) VALUES (4, 'gitane');


-- ================================================
-- TABLE DETAIL_VELO
-- ================================================
INSERT INTO DETAIL_VELO (id_detail_velo, velo, marque, type, categ, taille, date_fabrication)
VALUES (seq_DETAIL_VELO.nextval, seq_VELO.currval, 1, 1, 1, 1, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

-- ================================================
-- TABLE REPARATION
-- ================================================
INSERT INTO REPARATION (id_reparation, duree_prevue, date_debut_prevue, date_debut_reelle, date_fin_prevue, date_fin_reelle, etat, cout_total, velo)
VALUES (seq_REPARATION.nextval, 28, TO_DATE('01/01/2019', 'DD/MM/YYYY'), TO_DATE('01/01/2019', 'DD/MM/YYYY'), TO_DATE('01/01/2019', 'DD/MM/YYYY'), TO_DATE('01/01/2019', 'DD/MM/YYYY'), 'terminee', 100, seq_VELO.currval);

-- ================================================
-- TABLE FACTURE
-- ================================================
INSERT INTO FACTURE (id_facture, date_emission, montant, reparation)
VALUES (seq_FACTURE.nextval, TO_DATE('01/01/2019', 'DD/MM/YYYY'), 100, seq_REPARATION.currval);

-- ================================================
-- TABLE REPARATEUR
-- ================================================
INSERT INTO REPARATEUR (id_reparateur, login)
VALUES (1, 'reparateur1');

-- ================================================
-- TABLE OPERATION
-- ================================================
INSERT INTO OPERATION (id_operation, intitule, duree_prevue, date_debut_reelle, date_fin_reelle, etat, cout, reparation, reparateur)
VALUES (seq_OPERATION.nextval, 'démontage', 1, TO_DATE('01/01/2019', 'DD/MM/YYYY'), TO_DATE('01/01/2019', 'DD/MM/YYYY'), 'terminee', 10, seq_REPARATION.currval, 1);

-- ================================================
-- TABLE REGLEMENT
-- ================================================
INSERT INTO REGLEMENT (id_reglement, date_reglement, montant, facture)
VALUES (seq_REGLEMENT.nextval, TO_DATE('01/01/2019', 'DD/MM/YYYY'), 100, seq_FACTURE.currval);