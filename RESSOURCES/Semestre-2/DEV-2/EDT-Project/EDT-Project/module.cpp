#include "module.h"

Module::Module(string name)
{
    itsName = name ;
}

void Module::displayTeachers()
{
    cout << "Teachers : ";
    list<string>::iterator p = itsTeachers.begin();
    while(p != itsTeachers.end() )
    {
        cout << *p << " |";
        p++;
    }
}

void Module::displaySessions()
{
    cout << "Sessions : ";
    list<Session>::iterator p = itsSessions.begin();
    while(p != itsSessions.end() )
    {
        p->display();
        p++;
    }

}

bool Module::haveSessionAt(string dateTime)
{
    cout << "Sessions : ";
    list<Session>::iterator p = itsSessions.begin();
    while(p != itsSessions.end() )
    {
        if(p->getDateTime() == dateTime)
        {
            return true;
        }
        p++;
    }
    return false;
}

void Module::addTeacher(string teacher)
{
    itsTeachers.push_back(teacher) ;
}

void Module::addSession(Session session)
{
    itsSessions.push_back(session) ;
}

void Module::save()
{
    //Ouverture du fichier saveFile
    ofstream saveFile("saveModule.txt");

    cout << "Teachers : ";
    list<string>::iterator p = itsTeachers.begin();
    while(p != itsTeachers.end() )
    {
        saveFile << *p << " |";
        p++;
    }
    saveFile << endl ;

    cout << "Sessions : ";
    list<Session>::iterator q = itsSessions.begin();
    while(q != itsSessions.end() )
    {
        saveFile << q->getType() << " | " << q->getTeacher() << " | " << q->getDateTime() ;
        q++;
    }
    saveFile << endl ;

    //Fermeture du fichier saveFile
    saveFile.close();

}

bool static sortSessionByDateTime(Session s1, Session s2)
{
    // Extraire les valeurs de chaque partie de la date
    int year1 = std::stoi(s1.getDateTime().substr(0, 4));
    int month1 = std::stoi(s1.getDateTime().substr(4, 2));
    int day1 = std::stoi(s1.getDateTime().substr(6, 2));
    int hour1 = std::stoi(s1.getDateTime().substr(9, 2));
    int minute1 = std::stoi(s1.getDateTime().substr(11, 2));

    int year2 = std::stoi(s2.getDateTime().substr(0, 4));
    int month2 = std::stoi(s2.getDateTime().substr(4, 2));
    int day2 = std::stoi(s2.getDateTime().substr(6, 2));
    int hour2 = std::stoi(s2.getDateTime().substr(9, 2));
    int minute2 = std::stoi(s2.getDateTime().substr(11, 2));

    // Comparer les valeurs pour déterminer quelle date est plus grande
    if (year1 > year2) {
        return true;
    } else if (year1 < year2) {
        return false;
    }

    if (month1 > month2) {
        return true;
    } else if (month1 < month2) {
        return false;
    }

    if (day1 > day2) {
        return true;
    } else if (day1 < day2) {
        return false;
    }

    if (hour1 > hour2) {
        return true;
    } else if (hour1 < hour2) {
        return false;
    }

    if (minute1 > minute2) {
        return true;
    } else if (minute1 < minute2) {
        return false;
    }

    // Les dates sont égales
    return false;
}

void Module::displayPlanning()
{
    itsSessions.sort(sortSessionByDateTime);
}


void Module::split(string s, char c, vector<string> v)
{

}
