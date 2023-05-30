-- ============================================================================
-- Fichier : vue_reparations_clients.sql
-- Auteur  : Thibaut LEFRANCOIS
-- Date    : 10/03/2023
-- Role    : Avoir les informations concernant les opérations des réparations des vélos des clients.
-- ============================================================================

CREATE OR REPLACE VIEW vue_reparations_clients (
    nom,
    prenom,
    email,
    tel,
    adresse,
    velo,
    rep_etat,
    rep_debut,
    rep_fin,
    oper_intitule,
    oper_etat
)
AS
SELECT
    cl.nom,
    cl.prenom,
    cl.email,
    cl.tel,
    cl.adresse,
    ve.num_velo,
    re.etat,
    re.date_debut_reelle,
    re.date_fin_reelle,
    op.intitule,
    op.etat
FROM client cl
    INNER JOIN depot de ON cl.id_client = de.client
    INNER JOIN velo ve ON ve.id_velo = de.velo
    INNER JOIN reparation re ON ve.id_velo = re.velo
    INNER JOIN operation op ON re.id_reparation = op.reparation;