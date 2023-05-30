#include "session.h"

#include <iostream>
#include <fstream>

using namespace std ;

Session::Session(Subject subject, Type type, string dateTime, int duration, string room, string teacher)
{
    itsSubject = subject ;
    itsType = type ;
    itsDateTime = dateTime ;
    itsDuration = duration ;
    itsRoom = room ;
    itsTeacher = teacher ;
}

string Session::getDateTime()
{
    return itsDateTime;
}

string Session::getTeacher()
{
    return itsTeacher;
}

string Session::transSubject(Subject subject)
{
    switch(subject)
    {
    case BCOO : return "BCOO" ; break;
    case GPI : return "GPI" ; break ;
    case IHM : return "IHM" ; break ;
    case POO : return "POO" ; break ;
    case PT : return "PT" ; break ;
    }
}

string Session::getType()
{
    switch(itsType)
    {
    case CM : return "CM" ; break;
    case TD : return "TD" ; break ;
    case TP : return "TP" ; break ;
    }
}

void Session::display()
{
    cout << "Type : " << getType() << " || Subject : " << transSubject(itsSubject) << "\n" ;
    cout << "Teacher : " << getTeacher() << " || Date Time : " << getDateTime() << "\n" ;
    cout << "Room : " << itsRoom << " || Duration : " << itsDuration << "\n" ;

}

void Session::save(fstream saveFile)
{
    saveFile << getType() << endl
             << transSubject(itsSubject) << endl
             << getTeacher() << endl
             << getDateTime() << endl
             << itsRoom << endl
             << itsDuration << endl;
}
