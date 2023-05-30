-- ============================================================================
-- Fichier          : testAppartLibre.sql
-- Auteur           : LEFRANCOIS Thibaut & RAMAT Pierre
-- Date             : Janvier 2023
-- Base				: Agence Immobilière 
-- Role             : Montrer le solde actuel de chaque agence du PDG du réseau de celles ci
-- Fichier resultat : testAppartLibre.out
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

-- ==========================
-- Insertion de 5 AGENCES 
-- ==========================

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (1, 'Agence 1', 'Rue Agence 1', '0101010101', 'FR7630001007941234567890185', 75000) ;

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (2, 'Agence 2', 'Rue Agence 2', '0202020202', 'FR7630001007941234567890186', 80000) ;

-- ==========================
-- Insertion d'un PROPRIETAIRE
-- ==========================

INSERT INTO PROPRIETAIRE (ID_PROPRIO, NOM_PROPRIO, PRE_PROPRIO, TEL_PROPRIO, NB_BIEN, ID_AGENCE)
VALUES (1, 'LEFRANCOIS', 'Thibaut', '0101010101', 2, 1) ;

INSERT INTO PROPRIETAIRE (ID_PROPRIO, NOM_PROPRIO, PRE_PROPRIO, TEL_PROPRIO, NB_BIEN, ID_AGENCE)
VALUES (2, 'RAMAT', 'Pierre', '0202020202', 1, 2) ;

-- ==========================
-- Insertion d'un BIEN / Obligé d'être louable pour être compté comme valide
-- ==========================

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, STATUT_BIEN, ID_PROPRIO, CLASS_DPE, STATUT_RENOV, NB_VISITE)
VALUES (1, 'Rue Bien 1', 'Meuble', 'Louable', 1, 'A', 'Renove', 3) ;

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, STATUT_BIEN, ID_PROPRIO, CLASS_DPE, STATUT_RENOV, NB_VISITE)
VALUES (2, 'Rue Bien 2', 'Non Meuble', 'Louable', 2, 'B', 'Renove', 7) ;

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, STATUT_BIEN, ID_PROPRIO, CLASS_DPE, STATUT_RENOV, NB_VISITE)
VALUES (3, 'Rue Bien 2', 'Non Meuble', 'Louable', 2, 'B', 'Renove', 7) ;

-- ============================================================================

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- ==========================
-- Insertion de 5 AGENCES 
-- ==========================


INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE, IBAN_AGENCE, SOLDE_AGENCE)
VALUES (3, 'Agence 4', 'Rue Agence 4', '0404040404', 'FR7630001007941234567890188', 80000) ;

-- ==========================
-- Insertion d'un PROPRIETAIRE
-- ==========================

INSERT INTO PROPRIETAIRE (ID_PROPRIO, NOM_PROPRIO, PRE_PROPRIO, TEL_PROPRIO, NB_BIEN, ID_AGENCE)
VALUES (3, 'TAMISIER', 'Frank', '0101010101', 2, 2) ;

INSERT INTO PROPRIETAIRE (ID_PROPRIO, NOM_PROPRIO, PRE_PROPRIO, TEL_PROPRIO, NB_BIEN, ID_AGENCE)
VALUES (4, 'DEMOUGE', 'Colin', '0202020202', 1, 3) ;

-- ==========================
-- Insertion d'un BIEN / Obligé d'être loué car la dernière visite représente celle qui affirme la conclusion
-- ==========================

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, DEBUT_BAIL, FIN_BAIL, STATUT_BIEN, ID_PROPRIO, CLASS_DPE, STATUT_RENOV, NB_VISITE)
VALUES (4, 'Rue Bien 1', 'Meuble', TO_DATE('05/10/2023', 'DD/MM/YYYY'), TO_DATE('06/07/2024', 'DD/MM/YYYY'), 'Inlouable', 3, 'A', 'Renove', 3) ;

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, DEBUT_BAIL, FIN_BAIL, STATUT_BIEN, ID_PROPRIO, CLASS_DPE, STATUT_RENOV, NB_VISITE)
VALUES (5, 'Rue Bien 2', 'Non Meuble', TO_DATE('06/07/2023', 'DD/MM/YYYY'), TO_DATE('06/07/2024', 'DD/MM/YYYY'), 'Inlouable', 4, 'B', 'Renove', 7) ;

-- ============================================================================

-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testAppartLibre.out  
PROMPT fichier resultat du test : testAppartLibre.out 

-- Appel du fichier de presentation
@ C:\Users\tibol\Desktop\SAE\SAE-1-04\Jalon-2\LEFRANCOIS-RAMAT-D2-JALON-2-BD\bonus\presentation_gestloc.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base :
@ C:\Users\tibol\Desktop\SAE\SAE-1-04\Jalon-2\LEFRANCOIS-RAMAT-D2-JALON-2-BD\bonus\afficher_base_agence.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================

prompt 'Resultat de la requete appartLibre.sql'
SET echo ON
@ C:\Users\tibol\Desktop\SAE\SAE-1-04\Jalon-2\LEFRANCOIS-RAMAT-D2-JALON-2-BD\tests\appartLibre\appartLibre.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================

