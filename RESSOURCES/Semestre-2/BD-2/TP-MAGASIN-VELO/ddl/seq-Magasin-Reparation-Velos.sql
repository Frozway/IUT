-- ============================================================================
-- Fichier : seq-Magasin-Reparation-Velos.sql
-- Auteur  : 
-- Date    : Janvier 2023
-- Role    : Creation des séquences sur la BD Magasin Réparation Vélos
-- ============================================================================

-- Sequence sur ADRESSE
CREATE SEQUENCE seq_adresse
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur client
CREATE SEQUENCE seq_client
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur depot
CREATE SEQUENCE seq_depot
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur detail_velo
CREATE SEQUENCE seq_detail_velo
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur facture
CREATE SEQUENCE seq_facture
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur operation
CREATE SEQUENCE seq_operation
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur reglement
CREATE SEQUENCE seq_reglement
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur reparation
CREATE SEQUENCE seq_reparation
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;

-- Sequence sur velo
CREATE SEQUENCE seq_velo
INCREMENT BY 1
START WITH 1
MINVALUE 0
NOCYCLE
CACHE 25;



