-- ============================================================================
-- Fichier          : test_reparations_clients.sql
-- Auteur           : Thibaut LEFRANCOIS
-- Date             : 10/03/2023
-- Role             : Tester la vue vue_reparations_clients
-- Fichier resultat :  test_reparations_clients.out
-- ============================================================================
ALTER SESSION SET nls_date_format='dd/mm/yyyy';

COLUMN velo FORMAT a10 ;
COLUMN oper_intitule FORMAT a20 ;

set echo on
-- ============================================================================
-- Suppression des nuplet de la base de donnees
-- NB : Le test est effectué sur une base vide donc on fait 
--      la suppression de tous les nuplets de toutes les relations
-- ============================================================================
set echo off
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\vide-contenu-base-MagasinRepVelos.sql

set echo on
-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire. 
-- Il n'est pas possible d'avoir des collaborateurs sans competence
-- ============================================================================
set echo off

-- Insertion dans les relations référencées 
-- À compléter 

-- Cas 1 : Un client qui dépose 1 vélo, 1 réparation, 1 opération

INSERT INTO ADRESSE(id_adresse, intitule, commune, code_postal) 
VALUES (seq_ADRESSE.nextval, 'rue de la paix', 'Paris', '75000');

INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'LEFRANCOIS', 'Thibaut', seq_ADRESSE.currval, '0123456789', 'jeandupont@hotmail.com');

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '1789');

INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

INSERT INTO REPARATION (id_reparation, duree_prevue, date_debut_prevue, date_debut_reelle, date_fin_prevue, date_fin_reelle, etat, cout_total, velo)
VALUES (seq_REPARATION.nextval, 5, TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('05/01/2023', 'DD/MM/YYYY'), TO_DATE('05/01/2023', 'DD/MM/YYYY'), 'terminee', 100, seq_VELO.currval);

INSERT INTO REPARATEUR (id_reparateur, login)
VALUES (1, 'reparateur1');

INSERT INTO OPERATION (id_operation, intitule, duree_prevue, date_debut_reelle, date_fin_reelle, etat, cout, reparation, reparateur)
VALUES (seq_OPERATION.nextval, 'demontage', 2, TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('03/01/2023', 'DD/MM/YYYY'), 'terminee', 10, seq_REPARATION.currval, 1);

-- Cas 2 : Un client qui dépose 1 vélo, 1 réparation, 2 opérations


INSERT INTO ADRESSE(id_adresse, intitule, commune, code_postal) 
VALUES (seq_ADRESSE.nextval, 'rue de la paix', 'Paris', '75000');

INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'DEMOUGE', 'Colin', seq_ADRESSE.currval, '0123456775', 'jean@hotmail.com');

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '123');

INSERT INTO DEPOT (id_depot, client, velo, date_depot)
VALUES (seq_DEPOT.nextval, seq_CLIENT.currval, seq_VELO.currval, TO_DATE('01/01/2019', 'DD/MM/YYYY'));

INSERT INTO REPARATION (id_reparation, duree_prevue, date_debut_prevue, date_debut_reelle, date_fin_prevue, etat, cout_total, velo)
VALUES (seq_REPARATION.nextval, 5, TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('05/01/2023', 'DD/MM/YYYY'), 'encours', 100, seq_VELO.currval);

INSERT INTO REPARATEUR (id_reparateur, login)
VALUES (2, 'reparateur1');

INSERT INTO OPERATION (id_operation, intitule, duree_prevue, date_debut_reelle, date_fin_reelle, etat, cout, reparation, reparateur)
VALUES (seq_OPERATION.nextval, 'changement de roue', 1, TO_DATE('01/01/2019', 'DD/MM/YYYY'), TO_DATE('01/01/2019', 'DD/MM/YYYY'), 'encours', 10, seq_REPARATION.currval, 2);


set echo on
-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================
set echo off

-- Cas 3 : Un client sans dépot 

INSERT INTO ADRESSE(id_adresse, intitule, commune, code_postal) 
VALUES (seq_ADRESSE.nextval, 'rue de la paix', 'Paris', '75000');

INSERT INTO CLIENT (id_client, nom, prenom, adresse, tel, email) 
VALUES (seq_CLIENT.nextval, 'CORNUAULT', 'Mathis', seq_ADRESSE.currval, '0123456459', 'dupont@hotmail.com');

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '12345');

set echo on
-- ============================================================================
-- Etat de la base
-- ============================================================================
set echo off
-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL test_vue_reparations_clients.out
PROMPT fichier resultat du test : test_vue_reparations_clients.out 

-- Appel du fichier de presentation
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\presentation-MagasinRepVelos.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
@C:\Users\tibol\Desktop\R206-BD2-Ressources-TP-01-02\utilitaires\affiche-contenu-base-MagasinRepVelos.sql

set echo on
-- ============================================================================
-- Afficher le contenu de la vue 
-- ============================================================================
set echo off

-- Debut de l'affichage du contenu de la vue sur le client SqlPlus
prompt 'Conteu de la vue : nom_vue'

select *
from   vue_reparations_clients ;

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

