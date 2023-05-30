-- ============================================================================
-- Fichier          : def-dict-tables-cols-MagasinRepVelo.sql
-- Auteur           : 
-- Date             : Janvier 2023
-- Role             : Definition du dictionnaire des colonnes des tables de 
--                  la base de données "Magasin Réparation Vélos"
-- ============================================================================

COMMENT ON COLUMN ADRESSE.ID_ADRESSE IS 'Identifiant d''une adresse postale' ;
COMMENT ON COLUMN ADRESSE.INTITULE IS 'Désignation complète d''une adresse : numéro, rue, etc.' ;
COMMENT ON COLUMN ADRESSE.COMMUNE IS 'Commune d''une adressse : particulièrement les communes du 17'; 
COMMENT ON COLUMN ADRESSE.CODE_POSTAL IS 'Code postal d''une adresse'; 

COMMENT ON COLUMN CATEG_VELO.ID_CATEG IS 'Identifiant de la catégorie du vélo (PK)' ;
COMMENT ON COLUMN CATEG_VELO.LIBELLE IS 'Libellé de la catégorie du vélo : HOMME, FEMME, ENFANT (CK)' ;

COMMENT ON COLUMN CLIENT.ID_CLIENT IS 'Identifiant du client (PK)';
COMMENT ON COLUMN CLIENT.NOM IS 'Nom du client';
COMMENT ON COLUMN CLIENT.PRENOM IS 'Prénom du client';
COMMENT ON COLUMN CLIENT.EMAIL IS 'Email du client (UQ)';
COMMENT ON COLUMN CLIENT.TEL IS 'Téléphone du client';
COMMENT ON COLUMN CLIENT.ADRESSE IS 'Adresse du client (FK)';

COMMENT ON COLUMN DEPOT.ID_DEPOT IS 'Identifiant du dépôt du vélo par client (PK)';
COMMENT ON COLUMN DEPOT.CLIENT IS 'Client ayant déposé le vélo (FK)';
COMMENT ON COLUMN DEPOT.VELO IS 'Vélo déposé par client (FK)';
COMMENT ON COLUMN DEPOT.DATE_DEPOT IS 'Date de dépôt du vélo par client';

COMMENT ON COLUMN DETAIL_VELO.ID_DETAIL_VELO IS 'Identifiant du détail du vélo (PK)';
COMMENT ON COLUMN DETAIL_VELO.VELO IS 'Vélo concerné par le détail (FK)';
COMMENT ON COLUMN DETAIL_VELO.MARQUE IS 'Marque du vélo (FK)';
COMMENT ON COLUMN DETAIL_VELO.TYPE IS 'Type du vélo (FK)';
COMMENT ON COLUMN DETAIL_VELO.CATEG IS 'Catégorie du vélo (FK)';
COMMENT ON COLUMN DETAIL_VELO.TAILLE IS 'Taille du vélo (FK)';
COMMENT ON COLUMN DETAIL_VELO.DATE_FABRICATION IS 'Date de fabrication du vélo';

COMMENT ON COLUMN FACTURE.ID_FACTURE IS 'Identifiant de la facture (PK)';
COMMENT ON COLUMN FACTURE.DATE_EMISSION IS 'Date d''émission de la facture';
COMMENT ON COLUMN FACTURE.MONTANT IS 'Montant de la facture';
COMMENT ON COLUMN FACTURE.REPARATION IS 'Réparation concernée par la facture (FK)';

COMMENT ON COLUMN MARQUE_VELO.ID_MARQUE IS 'Idenfiant de la marque du vélo';
COMMENT ON COLUMN MARQUE_VELO.LIBELLE IS 'Libellé de la marque du vélo : BTWIN, GITANE, NAKAMURA, TREK (CK)';

COMMENT ON COLUMN OPERATION.ID_OPERATION IS 'Identifiant de l''opération (PK)';
COMMENT ON COLUMN OPERATION.INTITULE IS 'Intitulé de l''opération';
COMMENT ON COLUMN OPERATION.DUREE_PREVUE IS 'Durée prévue de l''opération en jours';
COMMENT ON COLUMN OPERATION.DATE_DEBUT_REELLE IS 'Date de début réelle de l''opération';
COMMENT ON COLUMN OPERATION.DATE_FIN_REELLE IS 'Date de fin réelle de l''opération';
COMMENT ON COLUMN OPERATION.ETAT IS 'Etat de l''opération : Ouverte, En cours, Annullée, Terminée (CK)';
COMMENT ON COLUMN OPERATION.COUT IS 'Coût de l''opération total TTC';
COMMENT ON COLUMN OPERATION.REPARATION IS 'Réparation associée à l''opération (FK)';
COMMENT ON COLUMN OPERATION.REPARATEUR IS 'Réparateur chargé de l''opération (FK)';

COMMENT ON COLUMN REGLEMENT.ID_REGLEMENT IS 'Identifiant du règlement de la réparation (PK)';
COMMENT ON COLUMN REGLEMENT.DATE_REGLEMENT IS 'Date de règlement de la réparation';
COMMENT ON COLUMN REGLEMENT.MONTANT IS 'Montant du règlement (partiel ou total)';
COMMENT ON COLUMN REGLEMENT.FACTURE IS 'Facture associée au règlement TTC (FK)';

COMMENT ON COLUMN REPARATION.ID_REPARATION IS 'Identifiant de la réparation (PK)';
COMMENT ON COLUMN REPARATION.DUREE_PREVUE IS 'Durée prévue de la réparation en jours';
COMMENT ON COLUMN REPARATION.DATE_DEBUT_PREVUE IS 'Date de début prévue de la réparation';
COMMENT ON COLUMN REPARATION.DATE_DEBUT_REELLE IS 'Date de début réelle de la réparation';
COMMENT ON COLUMN REPARATION.DATE_FIN_PREVUE IS 'Date de fin prévue de la réparation';
COMMENT ON COLUMN REPARATION.DATE_FIN_REELLE IS 'Date de fin réelle de la réparation';
COMMENT ON COLUMN REPARATION.ETAT IS 'Etat de la réparation : Ouverte, En cours, Annullée, Terminée, Réglée (CK)';
COMMENT ON COLUMN REPARATION.COUT_TOTAL IS 'Coût total de la réparation TTC';
COMMENT ON COLUMN REPARATION.VELO IS 'Vélo concerné par la réparation (FK)';

COMMENT ON COLUMN REPARATEUR.ID_REPARATEUR IS 'Identifiant du réparateur (PK)';
COMMENT ON COLUMN REPARATEUR.LOGIN IS 'Login du réparateur';

COMMENT ON COLUMN TAILLE_VELO.ID_TAILLE IS 'Identifiant de la taille du vélo (PK)';
COMMENT ON COLUMN TAILLE_VELO.LIBELLE IS 'Libellé de la taille du vélo : XS, S, M, M/L, L/XL, XL/XXL (CK)';

COMMENT ON COLUMN TYPE_VELO.ID_TYPE IS 'Identifiant du type du vélo (PK)';
COMMENT ON COLUMN TYPE_VELO.LIBELLE IS 'Libellé du type du vélo : VTT, VTC, VAE, CARGO, HOLLANDAIS, PLIANT (CK)';

COMMENT ON COLUMN VELO.ID_VELO IS 'Identifiant du vélo (PK)';
COMMENT ON COLUMN VELO.NUM_VELO IS 'Numéro du vélo (UQ)';




