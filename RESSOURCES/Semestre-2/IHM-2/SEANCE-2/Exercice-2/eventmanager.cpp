#include "eventmanager.h"

#include "EventManager.h"
#include <QMessageBox>

// Création d'une instance de notre gestionnaire d'évènements
EventManager* eventManager = new EventManager();

// Connexion des évènements "clic bouton" à notre gestionnaire d'évènements
connect(ui->bPerimeter, &QPushButton::clicked, eventManager, &EventManager::onPerimeterButtonClicked);
connect(ui->bArea, &QPushButton::clicked, eventManager, &EventManager::onAreaButtonClicked);

