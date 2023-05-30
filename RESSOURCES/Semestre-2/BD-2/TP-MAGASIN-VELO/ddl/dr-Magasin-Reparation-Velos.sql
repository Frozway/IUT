-- ============================================================================
-- fichier : dr-Magasin-Reparation-Velos.sql
-- auteur : 
-- date : janvier 2023
-- role : creation des DR des tables de la base de donnees
-- ============================================================================

ALTER TABLE REGLEMENT
  ADD CONSTRAINT FK_reglement_facture FOREIGN KEY (facture)
  REFERENCES FACTURE (id_facture);

ALTER TABLE FACTURE
  ADD CONSTRAINT FK_facture_reparation FOREIGN KEY (reparation)
  REFERENCES REPARATION (id_reparation);

ALTER TABLE OPERATION
  ADD CONSTRAINT FK_operation_reparation FOREIGN KEY (reparation)
  REFERENCES REPARATION (id_reparation);

ALTER TABLE OPERATION
  ADD CONSTRAINT FK_operation_reparateur FOREIGN KEY (reparateur)
  REFERENCES REPARATEUR (id_reparateur);

ALTER TABLE REPARATION
  ADD CONSTRAINT FK_reparation_velo FOREIGN KEY (velo)
  REFERENCES VELO (id_velo);

ALTER TABLE DETAIL_VELO
  ADD CONSTRAINT FK_detail_velo_marque FOREIGN KEY (marque)
  REFERENCES MARQUE_VELO (id_marque);

ALTER TABLE DETAIL_VELO
  ADD CONSTRAINT FK_detail_velo_taille FOREIGN KEY (taille)
  REFERENCES TAILLE_VELO (id_taille);

ALTER TABLE DETAIL_VELO
  ADD CONSTRAINT FK_detail_velo_type FOREIGN KEY (type)
  REFERENCES TYPE_VELO (id_type);

ALTER TABLE DETAIL_VELO
  ADD CONSTRAINT FK_detail_velo_categ FOREIGN KEY (categ)
  REFERENCES CATEG_VELO (id_categ);

ALTER TABLE DETAIL_VELO
  ADD CONSTRAINT FK_detail_velo_velo FOREIGN KEY (velo)
  REFERENCES VELO (id_velo);

ALTER TABLE DEPOT 
  ADD CONSTRAINT FK_depot_client FOREIGN KEY (client)
  REFERENCES CLIENT (id_client);

ALTER TABLE DEPOT
  ADD CONSTRAINT FK_depot_velo FOREIGN KEY (velo)
  REFERENCES VELO (id_velo);

ALTER TABLE CLIENT 
  ADD CONSTRAINT FK_client_adresse FOREIGN KEY (adresse)
  REFERENCES ADRESSE (id_adresse);



