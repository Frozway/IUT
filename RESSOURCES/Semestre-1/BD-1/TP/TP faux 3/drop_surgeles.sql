-- ==========================
-- fichier : drop_surgeles.sql
-- base : surgeles
-- auteur(s) : LEFRANCOIS Thibaut
-- date : 14/10/22
-- role : role de ce fichier
-- projet : surgelés
-- resultat dans : nom_du_fichier.out (si ce fichier produit une sortie)
-- ==========================

DROP TABLE COMMANDE CASCADE CONSTRAINTS;
DROP TABLE LIGNE_COMMANDE CASCADE CONSTRAINTS;
DROP TABLE PRODUIT CASCADE CONSTRAINTS;
DROP TABLE CLIENT CASCADE CONSTRAINTS;
DROP TABLE LIVRAISON CASCADE CONSTRAINTS;
DROP TABLE LIVREUR CASCADE CONSTRAINTS;