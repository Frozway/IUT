-- ==========================
-- fichier : dr_surgeles.sql
-- base : surgeles
-- auteur(s) : Dupont Achille
-- date : 14/10/22
-- role : role de ce fichier
-- projet : surgelés
-- resultat dans : nom_du_fichier.out (si ce fichier produit une sortie)
-- ==========================

ALTER TABLE COMMANDE
  ADD CONSTRAINT FK_CLIENT_TO_COMMANDE
    FOREIGN KEY (idcli)
    REFERENCES CLIENT (idcli);

ALTER TABLE LIVRAISON
  ADD CONSTRAINT FK_COMMANDE_TO_LIVRAISON
    FOREIGN KEY (idcom)
    REFERENCES COMMANDE (idcom);

ALTER TABLE LIVRAISON
  ADD CONSTRAINT FK_LIVREUR_TO_LIVRAISON
    FOREIGN KEY (idliv)
    REFERENCES LIVREUR (idliv);

ALTER TABLE LIGNE_COMMANDE
  ADD CONSTRAINT FK_PRODUIT_TO_LIGNE_COMMANDE
    FOREIGN KEY (idpro)
    REFERENCES PRODUIT (idpro);

ALTER TABLE LIGNE_COMMANDE
  ADD CONSTRAINT FK_COMMANDE_TO_LIGNE_COMMANDE
    FOREIGN KEY (idcom)
    REFERENCES COMMANDE (idcom);
