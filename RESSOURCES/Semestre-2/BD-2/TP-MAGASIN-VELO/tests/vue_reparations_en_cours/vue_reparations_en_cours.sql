-- ============================================================================
-- Fichier : vue_reparations_en_cours.sql 
-- Auteur  : Thibaut LEFRANCOIS
-- Date    : 10/03/2023
-- Role    : Gérer les réparations en cours
-- ============================================================================

CREATE OR REPLACE VIEW vue_reparations_en_cours
(
    duree_prevue,
    date_deb_prev,
    date_deb_reel,
    date_fin_prev,
    date_fin_reel,
    etat,
    cout,
    velo
)
AS 
SELECT duree_prevue,
       date_debut_prevue,
       date_debut_reelle,
       date_fin_prevue,
       date_fin_reelle,
       etat,
       cout_total,
       velo
FROM reparation
WHERE UPPER(etat) = UPPER ('encours');