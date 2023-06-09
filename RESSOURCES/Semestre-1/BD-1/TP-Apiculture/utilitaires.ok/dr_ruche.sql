-- ==========================
-- fichier : dr_api.sql
-- base : apiculture
-- auteur(s) : LEFRANCOIS Thibaut
-- date : 06/12/22
-- role : Ordres SQL des dépendances de référence
-- projet : APICULTURE
-- ==========================

ALTER TABLE APICULTEUR ADD CONSTRAINT UQ_MAILAPI UNIQUE (MAILAPI);
ALTER TABLE APICULTEUR ADD CONSTRAINT UQ_NOMAPI UNIQUE (NOMAPI);
ALTER TABLE APICULTEUR ADD CONSTRAINT UQ_PRENOMAPI UNIQUE (PRENOMAPI);

ALTER TABLE RUCHE
  ADD CONSTRAINT FK_APICULTEUR_TO_RUCHE
    FOREIGN KEY (IDAPI)
    REFERENCES APICULTEUR (IDAPI);

ALTER TABLE RUCHE
  ADD CONSTRAINT FK_RUCHER_TO_RUCHE
    FOREIGN KEY (IDRUCHER)
    REFERENCES RUCHER (IDRUCHER);

ALTER TABLE RECOLTE 
  ADD CONSTRAINT FK_RUCHE_TO_RECOLTE
    FOREIGN KEY (IDRU)
    REFERENCES RUCHE (IDRU);