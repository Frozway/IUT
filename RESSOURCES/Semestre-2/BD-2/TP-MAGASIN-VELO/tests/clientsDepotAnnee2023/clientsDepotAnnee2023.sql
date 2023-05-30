-- ==========================
-- Fichier : /tests/clientsDepotAnnee2023/clientsDepotAnnee2023.sql
-- Base : MagasinRepVelos
-- Auteur : Demouge Colin D2
-- Date : 02/03/2023
-- Rôle : Connaître les clients ayant déposés leurs vélos au moins une fois courant l’année 2023
-- Projet : BD2 - Création d'une base de données - Magasin de réparation de vélos
-- ==========================

-- Requête 
SELECT DISTINCT C.nom, C.prenom
FROM Client C INNER JOIN Depot D ON D.client=C.id_client
WHERE EXTRACT(YEAR FROM D.date_depot)=ANY
(
    SELECT EXTRACT(YEAR FROM D2.date_depot) AS annee
    FROM Depot D2
    WHERE EXTRACT(YEAR FROM D2.date_depot) = '2023'
);

--ou 

-- ============================================================================
-- Version 2
-- ============================================================================
SELECT c.nom, c.prenom
FROM client c 
WHERE c.id_client = ANY (
    SELECT d.client 
    FROM depot d inner join client c on d.client = c.id_client 
    and extract(year from d.date_depot) = 2023
    );


