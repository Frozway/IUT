#ifndef VERSE_H
#define VERSE_H

#include<iostream>
#include<fstream>
#include<vector>
#include"line.h"

using namespace std;

class Verse
{
private:
    vector<Line*> * itsLines ;
public:
    Verse();
    ~Verse();
    void addLine(string line);
    void display();
    void displayRyhmes();
};

#endif // VERSE_H
