-- ============================================================================
-- Fichier : ddl-modif-Magasin-Reparation-Velos.sql
-- Auteur  : 
-- Date    : Janvier 2023
-- Role    : Modification des tables concernées par les séquences
-- ============================================================================

alter table adresse modify
id_adresse default seq_adresse.nextval;

alter table client modify
id_client default seq_client.nextval;

alter table depot modify
id_depot default seq_depot.nextval;

alter table detail_velo modify
id_detail_velo default seq_detail_velo.nextval;

alter table facture modify
id_facture default seq_facture.nextval;

alter table operation modify
id_operation default seq_operation.nextval;

alter table reglement modify
id_reglement default seq_reglement.nextval;

alter table reparation modify
id_reparation default seq_reparation.nextval;

alter table velo modify
id_velo default seq_velo.nextval;