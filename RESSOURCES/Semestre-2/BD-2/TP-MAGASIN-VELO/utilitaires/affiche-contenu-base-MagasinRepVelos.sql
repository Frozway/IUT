-- ============================================================================
-- Fichier : affiche-contenu-base-MagasinRepVelos.sql 
-- Auteur  : 
-- Date    : Janvier 2023
-- Role    : Affichage des nuplets de la base de donnees. 
-- ============================================================================

PROMPT Contenu de la table CATEG_VELO
SELECT ID_CATEG,LIBELLE
FROM CATEG_VELO;

PROMPT Contenu de la table MARQUE_VELO
SELECT ID_MARQUE, LIBELLE
FROM MARQUE_VELO;

PROMPT Contenu de la table TAILLE_VELO
SELECT ID_TAILLE, LIBELLE
FROM TAILLE_VELO;

PROMPT Contenu de la table TYPE_VELO
SELECT ID_TYPE, LIBELLE
FROM TYPE_VELO;


-- Tout afficher 

PROMPT Contenu de la table adresse
SELECT * 
FROM adresse ;

PROMPT Contenu de la table client
SELECT * 
FROM client ;

PROMPT Contenu de la table depot
SELECT * 
FROM depot ;

PROMPT Contenu de la table detail_velo
SELECT * 
FROM detail_velo ;

PROMPT Contenu de la table facture
SELECT * 
FROM facture ;

PROMPT Contenu de la table operation
SELECT * 
FROM operation ;

PROMPT Contenu de la table reglement
SELECT * 
FROM reglement ;

PROMPT Contenu de la table reparation
SELECT * 
FROM reparation ;

PROMPT Contenu de la table reparateur
SELECT * 
FROM velo ;