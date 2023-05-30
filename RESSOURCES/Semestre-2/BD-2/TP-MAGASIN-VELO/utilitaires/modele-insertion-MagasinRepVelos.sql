-- ============================================================================
-- fichier : modele-insertion-MagasinRepVelos.sql
-- auteur  : 
-- date    : Janvier 2023
-- role    : modele d'insertion des nuplets dans les relations de la base de 
-- 	     donnees "port palaisance" 
-- ============================================================================

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

-- ================================================
-- TABLE MARQUE_VELO
-- ================================================
INSERT INTO MARQUE_VELO (id_marque, libelle) VALUES (1, 'nakamura');
INSERT INTO MARQUE_VELO (id_marque, libelle) VALUES (2, 'trek');
INSERT INTO MARQUE_VELO (id_marque, libelle) VALUES (3, 'btwin');


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

-- -- ================================================
-- -- TABLE ADRESSE
-- -- ================================================
-- INSERT INTO ADRESSE (id_adresse, rue, code_postal, ville, pays) VALUES (1, 'rue de la paix', '75000', 'Paris', 'France');
-- INSERT INTO ADRESSE (id_adresse, rue, code_postal, ville, pays) VALUES (2, 'rue de la liberté', '75000', 'Paris', 'France');
-- INSERT INTO ADRESSE (id_adresse, rue, code_postal, ville, pays) VALUES (3, 'rue de la république', '75000', 'Paris', 'France');
-- INSERT INTO ADRESSE (id_adresse, rue, code_postal, ville, pays) VALUES (4, 'rue de la gare', '75000', 'Paris', 'France');
-- INSERT INTO ADRESSE (id_adresse, rue, code_postal, ville, pays) VALUES (5, 'rue de la poste', '75000', 'Paris', 'France');

-- -- ================================================
-- -- TABLE CATEG_VELO
-- -- ================================================
-- INSERT INTO CATEG_VELO (id_categ, libelle) VALUES (1, 'VTT');
-- INSERT INTO CATEG_VELO (id_categ, libelle) VALUES (2, 'VTC');
-- INSERT INTO CATEG_VELO (id_categ, libelle) VALUES (3, 'VAE');
-- INSERT INTO CATEG_VELO (id_categ, libelle) VALUES (4, 'CARGO');
-- INSERT INTO CATEG_VELO (id_categ, libelle) VALUES (5, 'HOLLANDAIS');

-- -- ================================================
-- -- TABLE CLIENT
-- -- ================================================
-- INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, mail) 
-- VALUES (1, 'DUPONT', 'Jean', 1, '0123456789', 'jeandupont@hotmail.com');

-- INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, mail)
-- VALUES (2, 'DURAND', 'Pierre', 2, '0123456789', 'pierredurand@free.fr');

-- -- ================================================
-- -- TABLE DEPOT
-- -- ================================================
-- INSERT INTO DEPOT (id_depot, client, velo, date_depot)
-- VALUES (1, 1, 1, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

-- INSERT INTO DEPOT (id_depot, client, velo, date_depot)
-- VALUES (2, 1, 2, TO_DATE('01/01/2019', 'DD/MM/YYYY'));