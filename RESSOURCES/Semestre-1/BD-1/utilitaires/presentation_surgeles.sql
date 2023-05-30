-- ==========================
-- fichier : presentation_surgeles.sql
-- base : surgeles
-- auteur(s) : Dupont Achille
-- date : 14/10/22
-- role : rend plus lisible l'affichage des VARCHAR
-- projet : surgelés
-- resultat dans : nom_du_fichier.out (si ce fichier produit une sortie)
-- ==========================

set linesize 250;

column nomcli format a15;
column prenomcli format a15;
column adrcli format a15;
column mailcli format a30;

column nomliv format a15;
column prenomliv format a15;

column nompro format a15;
column typepro format a15;