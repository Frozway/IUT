-- ============================================================================
-- Fichier : depotToutVelos.sql
-- Auteur  : Thibaut LEFRANCOIS
-- Date    : 20/02/2023
-- Role    : Afficher les détails de tous les dépôts
-- ============================================================================

SELECT c.nom, c.prenom
FROM client c
WHERE NOT EXISTS (
                    SELECT *
                    FROM categ_velo cv
                    WHERE NOT EXISTS (
                                        SELECT *
                                        FROM depot d INNER JOIN detail_velo dv 
                                        ON d.velo = dv.velo
                                        WHERE dv.categ = cv.id_categ 
                                        AND d.client = c.id_client
                                      )
                );


 