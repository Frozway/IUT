-- ============================================================================
-- Fichier : clientsVelos.sql
-- Auteur  : Thibaut LEFRANCOIS
-- Date    : 20/02/2023
-- Role    : Liste des clients qui ont déposé un ou plusieurs vélos
-- ============================================================================

SELECT c.nom, c.prenom, v.num_velo, d.date_depot
FROM depot d INNER JOIN client c ON d.client = c.id_client 
             INNER JOIN velo v ON d.velo = v.id_velo ;


 