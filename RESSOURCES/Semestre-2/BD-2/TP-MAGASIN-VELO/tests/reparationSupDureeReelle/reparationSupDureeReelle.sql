-- ==========================
-- Fichier : /tests/reparationSupDureeReelle/reparationSupDureeReelle.sql
-- Base : MagasinRepVelos
-- Auteur : LEFRANCOIS Thibaut
-- Date : 02/03/2023
-- Rôle : Connaître a réparation débutée en 2023, terminée, telle que sa durée réelle est supérieure à toutes les réparations terminées
-- Projet : BD2 - Création d'une base de données - Magasin de réparation de vélos
-- ==========================

SELECT R.id_reparation, R.duree_prevue, R.date_debut_prevue, R.date_fin_prevue, (R.date_fin_reelle - R.date_debut_reelle) AS duree_reelle
FROM Reparation R
WHERE R.etat='terminee' AND EXTRACT(YEAR FROM R.date_debut_reelle)=2023 
                        AND (R.date_fin_reelle - R.date_debut_reelle) >= ALL
                        (
                            SELECT (R2.date_fin_reelle - R2.date_debut_reelle)
                            FROM Reparation R2
                            WHERE R2.etat='terminee'
                        );
