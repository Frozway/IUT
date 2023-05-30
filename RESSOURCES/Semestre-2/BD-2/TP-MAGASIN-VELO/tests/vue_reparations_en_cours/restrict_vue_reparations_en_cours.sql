-- ============================================================================
-- Fichier : restrict_vue_reparations_en_cours.sql
-- Auteur  : Thibaut LEFRANCOIS			
-- Date    : 10/03/2023	
-- Role    : Afficher les restrictions dans l'utilisation de la vue NOM_VUE
-- Note    : Remplacer NOM_VUE pour le nom de votre vue, ex. vue_reparations_en_cours
-- ============================================================================
column COLUMN_NAME       format A20;

SPOOL restrict_NOM_VUE.out
PROMPT fichier resultat du test : restrict_NOM_VUE.out 

-- A COMPLETE
select COLUMN_NAME, UPDATABLE, INSERTABLE, DELETABLE 
from   USER_UPDATABLE_COLUMNS
where  upper(TABLE_NAME) = upper('vue_reparations_en_cours');
---
SPOOL OFF