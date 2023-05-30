-- ============================================================================
-- Fichier : vide-contenu-base-MagasinRepVelos.sql
-- Auteur  : 
-- Date    : Janvier 2023
-- Role    : Suppression des nuplets des relations de la base de donnees
--           L'ordre de suppression des relations tient compte des 
--           dependances de reference entre ces relations. 
-- ============================================================================

DELETE FROM reglement ;
DELETE FROM detail_velo ;
DELETE FROM facture ;
DELETE FROM operation ;
--DELETE FROM taille_velo;
--DELETE FROM type_velo ;
--DELETE FROM categ_velo ;
--DELETE FROM marque_velo ;
DELETE FROM reparateur ;
DELETE FROM reparation ;
DELETE FROM depot ;
DELETE FROM velo ;
DELETE FROM client ;
DELETE FROM adresse;