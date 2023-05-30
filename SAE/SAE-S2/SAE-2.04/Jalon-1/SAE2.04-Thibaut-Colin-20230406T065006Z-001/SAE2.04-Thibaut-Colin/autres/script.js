document.getElementById("filter-button").addEventListener("click", filterTable);

function filterTable() {
    // Récupérer la valeur sélectionnée dans la liste déroulante
    const selectedTable = document.getElementById("table-filter").value;
    
    // Parcourir toutes les lignes du tableau
    const rows = document.querySelectorAll(".myTable tr");
    for (let i = 1; i < rows.length; i++) {
      const cells = rows[i].querySelectorAll("td");
      const table = cells[0].textContent.trim();
  
      // Cacher les lignes qui ne correspondent pas à la table sélectionnée
      if (table == selectedTable || selectedTable == "ALL") {
        rows[i].style.display = "";
      } else {
        rows[i].style.display = "none";
      }
    }
  }
  