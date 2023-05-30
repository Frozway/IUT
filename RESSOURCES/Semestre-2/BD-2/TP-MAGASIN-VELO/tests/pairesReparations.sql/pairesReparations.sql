-- ============================================================================
-- Fichier : depotToutVelos.sql
-- Auteur  : Thibaut LEFRANCOIS
-- Date    : 20/02/2023
-- Role    : Afficher les détails de tous les dépôts
-- ============================================================================

select p1.login "Reparateur",
       r1.id_reparation "Rep1",
       r2.id_reparation "Rep2",
       o1.intitule "Intitulé",
       (o1.date_fin_reelle - o1.date_debut_reelle) * 24 "Durée OperRep1 (h)",
       o1.cout "cout oper1",
       (o2.date_fin_reelle - o2.date_debut_reelle) * 24 "Durée OperRep2 (h)",
       o2.cout "cout oper2",
from   reparation r1
       inner join operation o1 on r1.id_reparation = o1.id_reparation
       inner join reparateur p1 on o1.reparateur = p1.id_reparateur,
       reparation r2
       inner join operation o2 on o2.reparation = r2.id_reparation
       inner join reparateur p2 on o2.reparateur = p2.id_reparateur
where  p1.id_reparateur = p2.id_reparateur and
       o1.intitule = o2.intitule and o1.id_operation > o2.id_operation ;