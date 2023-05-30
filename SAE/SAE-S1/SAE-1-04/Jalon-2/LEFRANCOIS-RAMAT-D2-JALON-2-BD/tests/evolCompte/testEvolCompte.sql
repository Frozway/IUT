-- ============================================================================
-- Fichier          : testEvolCompte.sql
-- Auteur           : LEFRANCOIS Thibaut & RAMAT Pierre
-- Date             : Janvier 2023
-- Base				: Agence Immobilière 
-- Role             : Montrer le solde actuel de chaque agence du PDG du réseau de celles ci
-- Fichier resultat : testEvolCompte.out
-- ============================================================================

-- ============================================================================
-- Modification du format de la date pour se conformer aux donnees du programme de test
-- ============================================================================

ALTER SESSION SET NLS_DATE_FORMAT='dd/mm/yyyy';

-- ============================================================================
-- Suppression des nuplets de la base de donnees
-- NB : Le test est effectué sur une base vide, il est nécessaire 
--      de supprimer tous les nuplets de toutes les relations
-- ============================================================================

@ C:\Users\tibol\Desktop\SAE\SAE-1-04\Jalon-2\LEFRANCOIS-RAMAT-D2-JALON-2-BD\utilitaires\vider_base_gestloc.sql

-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- ============================================================================

-- CAS1

-- ==========================
-- Insertion de 5 AGENCES 
-- ==========================

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (1, 'Agence 1', 'Rue Agence 1', '0101010101', 'FR7630001007941234567890185', 75000) ;

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (2, 'Agence 2', 'Rue Agence 2', '0202020202', 'FR7630001007941234567890186', 63000) ;

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (3, 'Agence 3', 'Rue Agence 3', '0303030303', 'FR7630001007941234567890187', 25000) ;

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (4, 'Agence 4', 'Rue Agence 4', '0404040404', 'FR7630001007941234567890188', 32000) ;

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (5, 'Agence 5', 'Rue Agence 5', '0505050505', 'FR7630001007941234567890189', 41000) ;

-- ============================================================================

-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testEvolCompte.out  
PROMPT fichier resultat du test : testEvolCompte.out 

-- Appel du fichier de presentation
@ C:\Users\tibol\Desktop\SAE\SAE-1-04\Jalon-2\LEFRANCOIS-RAMAT-D2-JALON-2-BD\bonus\presentation_gestloc.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base :
@ C:\Users\tibol\Desktop\SAE\SAE-1-04\Jalon-2\LEFRANCOIS-RAMAT-D2-JALON-2-BD\bonus\afficher_base_agence.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

prompt 'Resultat de la requete evolCompte.sql'
SET echo ON
@ C:\Users\tibol\Desktop\SAE\SAE-1-04\Jalon-2\LEFRANCOIS-RAMAT-D2-JALON-2-BD\tests\evolCompte\evolCompte.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

