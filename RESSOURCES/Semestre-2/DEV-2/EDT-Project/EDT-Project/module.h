#ifndef MODULE_H
#define MODULE_H

#include "session.h"

#include <list>
#include <vector>

#include <iostream>
using namespace std ;


class Module
{

private:
    string itsName;
    list<string> itsTeachers;
    list<Session> itsSessions;

public:
    Module(string name);
    void displayTeachers();
    void displaySessions();
    void displayPlanning();
    void addTeacher(string teacher);
    void addSession(Session session);
    bool haveSessionAt(string dateTime);
    void save();
    void load();
    bool static sortSessionByDateTime(Session s1, Session s2);
    void split(string s, char c, vector<string> v);
};

#endif // MODULE_H
