-- ============================================================================
-- Fichier          : testapiculteurAcacia.sql
-- Auteur           : Yassine REZZIK
-- Date             : Décembre 2022
-- Base				: Apiculteur
-- Role             : Afficher les IDAPI
-- Fichier resultat : testapiculteurAcacia.out
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
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\vider_base_ruche.sql

@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\ddl_ruche.sql
-- ============================================================================
-- Jeu de test pour le DOMAINE VALIDE 
-- NB : L'insertion de chaque nuplet doit faire l'objet d'un commentaire, 
-- notamment pour motiver le/les cas dans le(s)quel(s) il intervient.
-- ============================================================================

-- Cas n°1 : Un apiculteur qui produit du miel de type "acacia" 
-- Insertion d'un appiculteur 
INSERT INTO APICULTEUR (IDAPI, NOMAPI, PRENOMAPI, TELAPI, MAILAPI, ADRAPI)
VALUES (1,'Dupont','Jean','0101010101','Jean@yahoo.fr','a') ;
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (1, 'acacia');

-- Cas n°2 : Un apiculteur qui produit du miel de type « acacia » et un autre miel de type « sapin » 
INSERT INTO APICULTEUR (IDAPI, NOMAPI, PRENOMAPI, TELAPI, MAILAPI, ADRAPI)
VALUES (2,'Cornuault','Quentin','0202020202','Quentin@yahoo.fr','b') ;
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (2, 'acacia');
INSERT INTO APICULTEUR (IDAPI,NOMAPI,PRENOMAPI,TELAPI,MAILAPI,ADRAPI)
VALUES (3,'Garcia','Brandon','0303030303','Brandon@yahoo.fr','c') ;
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (3, 'po');


-- Cas n°3 : Différents apiculteurs qui produisent du miel de type « acacia » dans le même rucher 
-- Insertion d'un appiculteur 
INSERT INTO APICULTEUR (IDAPI, NOMAPI, PRENOMAPI, TELAPI, MAILAPI, ADRAPI)
VALUES (4,'Demouge','Martin','0404040404','Martin@yahoo.fr','d') ;
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (4, 'acacia');
INSERT INTO APICULTEUR (IDAPI, NOMAPI, PRENOMAPI, TELAPI, MAILAPI, ADRAPI)
VALUES (5,'Lefrancois','Marine','0505050505','Marine@yahoo.fr','e') ;
INSERT INTO RUCHER (IDRUCHER, TYPEMIEL)
VALUES (5, 'acacia');

-- ============================================================================
-- Jeu de test pour le DOMAINE INVALIDE 
-- ============================================================================

-- Cas n°3 : Un apiculteur qui produit du miel d'un autre type que le type acacia
-- Insertion d'un Appiculteur 
-- INSERT INTO CLIENT (IDCLI,NOMCLI,PRENOMCLI,TELCLI,MAILCLI,ADRCLI)
-- VALUES (3,'Bibo' ,'Marc',0714850325,'marc@free.fr','Le Thou' );



-- Debut de l'ecriture du fichier resultat du programme de test 
SPOOL testapiculteurAcacia.out
PROMPT fichier resultat du test : testapiculteurAcacia.out

-- Appel du fichier de presentation
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\presentation_ruche.sql

-- Afficher le contenu des relations de la base de donnees
PROMPT Contenu de la base : 
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\utilitaires\afficher_base_ruche.sql

-- ============================================================================
-- Requete a tester 
-- ============================================================================
SET echo ON
@ C:\Users\tibol\Documents\IUT\RESSOURCES\BD-1\TP\Tp-api\tests.ok\apiculteurAcacia\apiculteurAcacia.sql
SET echo OFF

-- Fin de l'ecriture du fichier resultat du programme de test 
SPOOL OFF

-- ============================================================================
-- Fin du programme de test
-- ============================================================================