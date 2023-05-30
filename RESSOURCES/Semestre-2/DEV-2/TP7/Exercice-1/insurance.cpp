#include "insurance.h"

Insurance::Insurance(string name)
{
    itsName = name;
    itsVehicleContracts = new map<Client *, vector<Vehicle*>> ;
}

Insurance::~Insurance()
{
    for (auto it = itsVehicleContracts->begin(); it != itsVehicleContracts->end(); ++it)
    {
        it->second.clear(); // supprime les contrats d'assurance pour chaque client
        //delete it->second; // supprime le vecteur de contrats d'assurance pour chaque client
    }
    itsVehicleContracts->clear(); // supprime tous les clients

}




void Insurance::addContract(Client *client, Vehicle *vehicle)
{

    int nbVehicule = itsVehicleContracts->size() ;
    int nbTemp = nbVehicule ;

    bool notYetInsured = true;
    bool clientExist = false;

    //Vérifier si le client existe déjà
    for (map<Client *, vector<Vehicle*>>::iterator it = itsVehicleContracts->begin() ; it != itsVehicleContracts->end(); it ++)
    {
        //Si le nom correspond à l'un des noms de la liste alors il existe donc sortir de la boucle
        if(it->first == client)
        {
            clientExist = true ;
            break ;
        }
    }

    if (clientExist == true)
    {
        //Vérifier si le véhicule est déjà assuré
        //Récupéré dans un vecteur, la liste des véhicules assuré dans la map itsVehicleContracts
        vector<Vehicle*> clientVehicles = itsVehicleContracts->at(client);

        //Parcourir la liste des véhicules assuré du client et vérifié si le véhicule entré en paramètre n'y est pas déjà
        for (int i = 0; i < int(clientVehicles.size()); i++)
        {
            if (clientVehicles[i] == vehicle)
            {
                notYetInsured = false;
                break;
            }
        }
        // Si le véhicule n'est pas déjà assuré, ajouter le véhicule dans la liste du client puis mettre à jour la liste d'assurance véhicule
        if (notYetInsured)
        {
            clientVehicles.push_back(vehicle);
            itsVehicleContracts->at(client).push_back(vehicle) ;// = clientVehicles;
        }
        nbTemp += 1;
    }
    else
    {
        // Si le client n'existe pas encore, ajouter le client et le véhicule dans la map
        vector<Vehicle*> clientVehicles;
        clientVehicles.push_back(vehicle);
        itsVehicleContracts->insert({client, clientVehicles});
        nbTemp += 1 ;
    }

    //Si le compteur temporaire à bien 1 de plus (soit l'ajout d'un véhicule) alors l'ajout du contract c'est bien réalisé
    if(nbTemp == (nbVehicule + 1) )
    {
        cout << "Contrat ajoute" << endl  ;
    }


}

void Insurance::displayContracts()
{

    //Si il n'y a plus de contracts d'assurance, ne rien faire
    if(itsVehicleContracts->size() == 0 )
    {
        cout << "Pas de contracts d'assurance encore associe" << endl ;
        return ;
    }
    else
    {
        vector<Vehicle*> allInsuredVehicles;
        //Boucle qui créera une liste de véhicule assuré pour chaque client, et les ajoutera ensuite dans une liste composé de tout les véhicules sans distinction de client
        for (map<Client *, vector<Vehicle*>>::iterator it = itsVehicleContracts->begin(); it != itsVehicleContracts->end(); it++)
        {
            vector<Vehicle*> clientVehicles = it->second;

            for (Vehicle* v : clientVehicles)
            {
                allInsuredVehicles.push_back(v);
            }
        }

        cout << "Liste des clients assures : " << endl << endl ;

        for(map<Client *, vector<Vehicle*>>::iterator it = itsVehicleContracts->begin() ; it != itsVehicleContracts->end() ; it ++)
        {
            cout << "- Nom d'un client assure : " << it->first->getItsLastName() << endl ;
        }

        cout << endl << "Liste des vehicules assures : " << endl << endl ;

        for(int i = 0 ; i < int(allInsuredVehicles.size()) ; i++)
        {
            cout << "-  Vehicule "<< i + 1 << " assure : " ;
            allInsuredVehicles[i]->display();
            cout << endl ;
        }

        cout << endl << endl ;

    }


}

void Insurance::removeContract(Client *client, Vehicle *vehicle)
{

    bool clientExist = false;

    //Vérifier si le client existe déjà
    for (map<Client *, vector<Vehicle*>>::iterator it = itsVehicleContracts->begin() ; it != itsVehicleContracts->end(); it ++)
    {
        //Si le nom correspond à l'un des noms de la liste alors il existe donc sortir de la boucle
        if(it->first->getItsLastName() == client->getItsLastName())
        {
            clientExist = true ;
            break ;
        }
    }

    if(clientExist == false)
    {
        cout << "Client non existant..." << endl ;
        return ;
    }

    // Récupérer la liste des véhicules assurés du client
    vector<Vehicle*> clientVehicles = itsVehicleContracts->at(client);

    // Parcourir les véhicules assurés du client pour trouver celui qui doit être retiré
    for (vector<Vehicle*>::iterator it = clientVehicles.begin(); it != clientVehicles.end(); it++)
    {
        if (*it == vehicle)
        {
            // Supprimer le véhicule de la liste des véhicules assurés du client
            clientVehicles.erase(it);

            // Si le client n'a plus de véhicule assuré, le supprimer également
            if (clientVehicles.empty())
            {
                itsVehicleContracts->erase(client);
                cout << "Client supprime" << endl;
            }
            else
            {
                cout << "Véhicule supprime pour le client" << endl;
            }

            return;
        }
    }

    // Si le véhicule n'est pas trouvé dans la liste des véhicules assurés du client
    cout << "Véhicule non trouve pour le client" << endl;
}

void Insurance::displayContractsClient(Client *client)
{

    vector<Vehicle*> clientVehicles = itsVehicleContracts->at(client);

    cout << "Liste des véhicules assurés pour le client " << client->getItsLastName() << ":" << endl;

    for (int i = 0; i < int(clientVehicles.size()); i++)
    {
        cout << "Vehicule " << i+1 << ": ";
        clientVehicles[i]->display();
        cout << endl;
    }
}





