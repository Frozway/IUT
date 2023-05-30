-- ==========================
-- fichier : data.sql
-- base : gestloc
-- auteur(s) : LEFRANCOIS Thibaut et RAMAT Pierre
-- date : 17/11/2022
-- role : Ordres des requêtes SQL permettant d’afficher l’ensemble du contenu des tables de la base de données.
-- projet : AGENCE IMMOBILIERE / GESTION LOCATIVE
-- ==========================

-- ==========================
-- Insertion d'une AGENCE 
-- ==========================

INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE)
VALUES (1, 'Agence 1', 'Rue Agence 1', '0101010101') ;
INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE)
VALUES (2, 'Agence 2', 'Rue Agence 2', '0102030405') ;
INSERT INTO AGENCE(ID_AGENCE, NOM_AGENCE, ADR_AGENCE, TEL_AGENCE)
VALUES (3, 'Agence 3', 'Rue Agence 3', '9090909090') ;

-- ==========================
-- Insertion d'un PROPRIETAIRE
-- ==========================

INSERT INTO PROPRIETAIRE (ID_PROPRIO, NOM_PROPRIO, PRE_PROPRIO, TEL_PROPRIO, NB_BIEN, ID_AGENCE)
VALUES (1, 'LEFRANCOIS', 'Thibaut', '0102030405', 1, 1) ;
INSERT INTO PROPRIETAIRE (ID_PROPRIO, NOM_PROPRIO, PRE_PROPRIO, TEL_PROPRIO, NB_BIEN, ID_AGENCE)
VALUES (2, 'NIL', 'Julien', '0665248621', 2, 2) ;
INSERT INTO PROPRIETAIRE (ID_PROPRIO, NOM_PROPRIO, PRE_PROPRIO, TEL_PROPRIO, NB_BIEN, ID_AGENCE)
VALUES (3, 'TAMISIER', 'Frank', '0789651245', 2, 1) ;

-- ==========================
-- Insertion d'un BIEN 
-- ==========================

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, DEBUT_BAIL, FIN_BAIL, STATUT_BIEN, ID_PROPRIO)
VALUES (1, 'Rue Bien 1', 'Meuble', TO_DATE('01/01/2023', 'DD/MM/YYYY'), TO_DATE('01/01/2024', 'DD/MM/YYYY'), 'Occupe', 1) ;

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, DEBUT_BAIL, FIN_BAIL, STATUT_BIEN, ID_PROPRIO)
VALUES (2, 'Rue Bien 2', 'Non Meuble', TO_DATE('06/07/2023', 'DD/MM/YYYY'), TO_DATE('06/07/2024', 'DD/MM/YYYY'), 'Pas occupe', 2) ;

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, DEBUT_BAIL, FIN_BAIL, STATUT_BIEN, ID_PROPRIO)
VALUES (3, 'Rue Bien 3', 'Meuble', TO_DATE('06/07/2023', 'DD/MM/YYYY'), TO_DATE('06/07/2025', 'DD/MM/YYYY'), 'Occupe', 2) ;

INSERT INTO BIEN(ID_BIEN, ADR_BIEN, TYPE_BIEN, DEBUT_BAIL, FIN_BAIL, STATUT_BIEN, ID_PROPRIO)
VALUES (4, 'Rue Bien 4', 'Non Meuble', TO_DATE('09/07/2023', 'DD/MM/YYYY'), TO_DATE('12/07/2024', 'DD/MM/YYYY'), 'Pas occupe', 3) ;

-- ==========================
-- Insertion d'une GESTION (relation propriétaire/agence)
-- ==========================

-- Chaque table gestion doit se réinitialiser chaque mois 

INSERT INTO GESTION(ID_GESTION, ID_FACTURE_PROPRIO, TOTAL_GESTION, STATUT_GESTION, ID_PROPRIO)
VALUES (1, 1, 500, 'Paye', 1) ;

INSERT INTO GESTION(ID_GESTION, ID_FACTURE_PROPRIO, TOTAL_GESTION, STATUT_GESTION, ID_PROPRIO)
VALUES (2, 1, 425, 'Pas Paye', 2) ;

INSERT INTO GESTION(ID_GESTION, ID_FACTURE_PROPRIO, TOTAL_GESTION, STATUT_GESTION, ID_PROPRIO)
VALUES (3, 1, 675, 'Paye', 3) ;

-- ==========================
-- Insertion d'une LOCATION
-- ==========================

INSERT INTO LOCATION(ID_LOCATION, ID_FACTURE_LOYER, TOTAL_CHARGES, TOTAL_LOYER, STATUT_LOYER, ID_BIEN)
VALUES (1, 1, 50, 600, 'Paye', 1) ;

INSERT INTO LOCATION(ID_LOCATION, ID_FACTURE_LOYER, TOTAL_CHARGES, TOTAL_LOYER, STATUT_LOYER, ID_BIEN)
VALUES (2, 1, 65, 850, 'Pas paye', 3) ;

-- ==========================
-- Insertion d'un LOCATAIRE 
-- ==========================

INSERT INTO LOCATAIRE(ID_LOCATAIRE, NOM_LOCATAIRE, PRE_LOCATAIRE, TEL_LOCATAIRE, ID_LOCATION)
VALUES (1, 'RAMAT', 'Pierre', '0202020202', 1) ;

INSERT INTO LOCATAIRE(ID_LOCATAIRE, NOM_LOCATAIRE, PRE_LOCATAIRE, TEL_LOCATAIRE, ID_LOCATION)
VALUES (2, 'LEBLANC', 'Pascal', '0646231389', 2) ;

