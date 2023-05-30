-- ============================================================================
-- Fichier : reparationsOuvertes.sql
-- Auteur  : Thibaut LEFRANCOIS
-- Date    : 20/02/2023
-- Role    : Liste des réparations ouvertes et leurs opérations éventuelles
-- ============================================================================

SELECT r.id_reparation, v.num_velo, r.etat, o.id_operation, o.etat
FROM reparation r INNER JOIN velo v ON r.velo = v.id_velo 
                  LEFT JOIN operation o ON r.id_reparation = o.reparation
WHERE r.etat = 'Ouverte' ;

-- FROM operation o RIGHT JOIN reparation r ON o.reparation = r.id_reparation
--                  INNER JOIN velo v ON r.velo = v.id_velo ; 
-- WHERE r.etat = 'Ouverte' ;



 