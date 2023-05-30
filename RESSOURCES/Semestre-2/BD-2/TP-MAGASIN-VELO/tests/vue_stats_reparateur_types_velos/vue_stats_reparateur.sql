-- ============================================================================
-- Fichier : vue_stats_reparateur.sql 
-- Auteur  : Thibaut LEFRANCOIS
-- Date    : 10/03/2023
-- Role    : Afficher des indicateurs concernant les réparations des réparateurs effectuées en 2023
-- ============================================================================

CREATE VIEW vue_stats_reparateur
(
    reparateur,
    sum_duree_op,
    sum_cout_op,
    types_velo
)
AS
SELECT rt.login, sum(op.date_fin_reelle - op.date_debut_reelle), sum(op.cout), 
       LISTAGG (tv.libelle, ', ') WITHIN GROUP (ORDER BY tv.libelle)
FROM reparateur rt 
    JOIN operation op ON rt.id_reparateur = op.reparateur
    JOIN reparation rp ON rp.id_reparation = op.reparation
    JOIN velo vl ON vl.id_velo = rp.velo
    JOIN detail_velo dv ON vl.id_velo = dv.velo
    JOIN type_velo tv ON dv.type = tv.id_type
WHERE EXTRACT(year from rp.date_debut_reelle) = 2023 and rp.etat = 'terminee'
GROUP BY rt.login;
