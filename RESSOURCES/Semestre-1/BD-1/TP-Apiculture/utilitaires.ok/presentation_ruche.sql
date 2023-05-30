-- ==========================
-- fichier : presentation_ruche.sql
-- base : Ruche
-- auteur(s) : LEFRANCOIS Thibaut
-- date : 17/11/2022
-- role : Créer une présentation pour clarifier l'affichage des tables
-- projet : TP-APICULTURE
-- ==========================
SET UNDERLINE =

--Table Apiculture
COLUMN NOMAPI HEADING "Nom api" FORMAT a13 ; 
COLUMN PRENOMAPI HEADING "Prenom api" FORMAT a15 ;
COLUMN TELAPI HEADING "Telephone" FORMAT a10 ;
COLUMN MAILAPI HEADING "Mail" FORMAT a16 ;
COLUMN ADRAPI HEADING "Adresse" FORMAT a10 ;

--Table Rucher
COLUMN TYPEMIEL HEADING "Type miel" FORMAT a15 ; 

--Table Ruche
COLUMN NBCADRE HEADING "Nombre cadre" FORMAT 99 ; 
COLUMN IDAPI HEADING "ID-Api" FORMAT 9999 ;
COLUMN IDRUCHER HEADING "ID-Ruche" FORMAT 9999 ;

--Table récolte
COLUMN DATEREC HEADING "Date recolte" FORMAT a10 ; 




