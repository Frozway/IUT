-- ============================================================================
-- Fichier          : testMasseTotaleMarsMai.sql
-- Auteur           : 
-- Date             : 
-- Base				: 
-- Role             : 
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
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\ddl_ruche.sql
-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-- CAS1
-- 
INSERT INTO APICULTEUR (IDAPI, NOMAPI, PRENOMAPI, TELAPI, MAILAPI, ADRAPI)
VALUES (1,'Dupont','Jean','0101010101','Jean@yahoo.fr','a') ;
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (1, 'acacia');
INSERT INTO RUCHE (IDRU, NBCADRE, IDAPI, IDRUCHER)
VALUES (1, 3, 1, 1);
INSERT INTO RECOLTE (IDRU, DATEREC, MASSE)
VALUES (1, '01/03/22', 1.3);
INSERT INTO RECOLTE (IDRU, DATEREC, MASSE)
VALUES (1, '02/03/22', 1.3);
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (2, 'acacia');
INSERT INTO RUCHE (IDRU, NBCADRE, IDAPI, IDRUCHER)
VALUES (2, 3, 1, 2);
INSERT INTO RECOLTE (IDRU, DATEREC, MASSE)
VALUES (1, '01/05/22', 1.5);


-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================



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
SPOOL testMasseTotaleMarsMai.out
PROMPT fichier resultat du test : testMasseTotaleMarsMai.out

-- Appel du fichier de presentation
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\presentation_ruche.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base :
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\afficher_base_ruche.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================
prompt 'Resultat de la requete'
SET echo ON
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\tests.ok\masseTotaleMarsMai\masseTotaleMarsMai.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================