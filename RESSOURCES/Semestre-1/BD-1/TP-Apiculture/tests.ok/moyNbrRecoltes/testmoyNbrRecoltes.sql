-- ============================================================================
-- Fichier          : testapiculteurAcacia.sql
-- Auteur           : Yassine REZZIK
-- Date             : Décembre 2022
-- Base				: Apiculteur
-- Role             : Afficher la Moyenne du nombre de récoltes par ruchers 
-- Fichier resultat : testmoyNbrRecoltes.out
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

-- Cas n°1 : Un rucher avec 1 récolte de 1 seule ruche  
-- Insertion d'un appiculteur 
INSERT INTO APICULTEUR (IDAPI, NOMAPI, PRENOMAPI, TELAPI, MAILAPI, ADRAPI)
VALUES (1,'Dupont','Jean','0101010101','Jean@yahoo.fr','a') ;
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (1, 'acacia');
INSERT INTO RUCHE (IDRU, NBCADRE, IDAPI, IDRUCHER)
VALUES (1, 3, 1, 1);
INSERT INTO RECOLTE (IDRU, DATEREC, MASSE)
VALUES (1, '03/10/22', 1.3);

-- -- Cas n°2 : Un rucher avec plusieurs récoltes d'une seule ruche
-- INSERT INTO CLIENT (IDCLI,NOMCLI,PRENOMCLI,TELCLI,MAILCLI,ADRCLI)
-- VALUES (2,'Duchamps','Didier' ,0478960214,'didier@wanadoo.fr' ,'Nieul-Sur-Mer');
-- INSERT INTO COMMANDE (IDCOM,IDCLI,DATECOM,daterecepprevi)
-- VALUES (2,2,'14/10/2022','20/10/2022');
-- INSERT INTO COMMANDE (IDCOM,IDCLI,DATECOM,daterecepprevi)
-- VALUES (3,2,'14/10/2022','20/10/2022');


-- -- Cas n°3 : Un rucher avec plusieurs récoltes de plusieurs ruches 
-- -- Insertion d'un appiculteur 
-- INSERT INTO CLIENT (IDCLI,NOMCLI,PRENOMCLI,TELCLI,MAILCLI,ADRCLI)
-- VALUES (1,'Dupont','Jean',0545454545,'dupont@yahoo.fr','Trizay') ;
-- -- Insertion d'un second appiculteur
-- INSERT INTO COMMANDE (IDCOM,IDCLI,DATECOM,daterecepprevi)
-- VALUES (1,1,'14/10/2022','20/10/2022');

-- -- ============================================================================
-- -- Jeu de test pour le DOMAINE INVALIDE 
-- -- ============================================================================

-- -- Cas n°4 : Un rucher sans récolte 
-- -- Insertion d'un Appiculteur 
-- INSERT INTO CLIENT (IDCLI,NOMCLI,PRENOMCLI,TELCLI,MAILCLI,ADRCLI)
-- VALUES (3,'Bibo' ,'Marc',0714850325,'marc@free.fr','Le Thou' );



-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testmoyNbrRecoltes.out
PROMPT fichier resultat du test : testmoyNbrRecoltes.out

-- Appel du fichier de presentation
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\presentation_ruche.sql


-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\afficher_base_ruche.sql


-- ============================================================================
-- Requete a tester 
-- ============================================================================
SET echo ON
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\tests.ok\moyNbrRecoltes\moyNbrRecoltes.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================