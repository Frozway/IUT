-- ============================================================================
-- Fichier          : test_nom_vue.sql
-- Auteur           : 
-- Date             : Mars 2023
-- Role             : Tester la vue nom_vue
-- Fichier resultat :  test_nom_vue.out
-- ============================================================================
ALTER SESSION SET nls_date_format='dd/mm/yyyy';

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

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '123456789');

INSERT INTO REPARATION (id_reparation, duree_prevue, date_debut_prevue, date_debut_reelle, date_fin_prevue, etat, cout_total, velo)
VALUES (seq_REPARATION.nextval, 5, TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('05/01/2023', 'DD/MM/YYYY'), 'encours', 100, seq_VELO.currval);




set echo on
-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================
set echo off

INSERT INTO VELO (id_velo, num_velo) 
VALUES (seq_VELO.nextval, '123456788');

INSERT INTO REPARATION (id_reparation, duree_prevue, date_debut_prevue, date_debut_reelle, date_fin_prevue, date_fin_reelle, etat, cout_total, velo)
VALUES (seq_REPARATION.nextval, 5, TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('05/01/2023', 'DD/MM/YYYY'),  TO_DATE('05/01/2023', 'DD/MM/YYYY'), 'terminee', 100, seq_VELO.currval);


set echo on
-- ============================================================================
-- Etat de la base
-- ============================================================================
set echo off
-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL test_nom_vue.out
PROMPT fichier resultat du test : test_nom_vue.out 

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
from   vue_reparations_en_cours ;

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

