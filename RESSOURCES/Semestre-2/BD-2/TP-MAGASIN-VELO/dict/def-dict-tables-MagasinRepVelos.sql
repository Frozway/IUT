-- ============================================================================
-- Fichier          : def-dict-tables-MagasinRepVelo.sql
-- Auteur           : 
-- Date             : Janvier 2023
-- Role             : Definition du dictionnaire des tables de la base de 
--					données "Magasin Réparation Vélos"
-- ============================================================================

COMMENT ON TABLE ADRESSE IS 'Adresse postale du client';

COMMENT ON TABLE CATEG_VELO IS 'Categorie du velo : HOMME, FEMME, ENFANT';

COMMENT ON TABLE CLIENT IS 'Client : informations principales';

COMMENT ON TABLE DEPOT IS 'Depot du velo par le client. A une date donnee, le client peut deposer plusieurs velos.';

COMMENT ON TABLE DETAIL_VELO IS 'Detail du velo depose par le client.';

COMMENT ON TABLE FACTURE IS 'Facture d''une reparation.';

COMMENT ON TABLE MARQUE_VELO IS 'Marque du velo : BTWIN, GITANE, NAKAMURA, TREK';

COMMENT ON TABLE OPERATION IS 'Operation faisant partie de la reparation.';

COMMENT ON TABLE REGLEMENT IS 'Reglement partiel ou total d''une facture de reparation.';

COMMENT ON TABLE REPARATEUR IS 'Reparateur affecte a l''operation d''une reparation';

COMMENT ON TABLE REPARATION IS 'Reparation du velo.';

COMMENT ON TABLE TAILLE_VELO IS 'Taille du velo : XS, S, M, M/L, L/XL, XL/XXL';

COMMENT ON TABLE TYPE_VELO IS 'Type du velo : VTT, VTC, VAE, CARGO, HOLLANDAIS, PLIANT';

COMMENT ON TABLE VELO IS 'Velo depose par un client.';

