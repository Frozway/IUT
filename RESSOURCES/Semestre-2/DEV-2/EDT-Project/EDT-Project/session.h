#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <fstream>
using namespace std ;

enum Subject
{
    BCOO,
    GPI,
    IHM,
    POO,
    PT
};

enum Type
{
    CM,
    TD,
    TP
};

class Session
{

private:
    Subject itsSubject ;
    Type itsType ;
    string itsDateTime ;
    int itsDuration ;
    string itsRoom ;
    string itsTeacher ;

public:
    Session(Subject subject, Type type, string dateTime, int duration, string room, string teacher);
    string getDateTime();
    string getTeacher() ;
    string getType() ;
    void display();
    void save(fstream saveFile);
    string transSubject(Subject subject);
};

#endif // SESSION_H
