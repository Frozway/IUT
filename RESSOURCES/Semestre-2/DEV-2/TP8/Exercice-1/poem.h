#ifndef POEM_H
#define POEM_H

#include<iostream>
#include<fstream>
#include<vector>
#include"verse.h"


using namespace std;

class Poem
{
private:
    vector<Verse*> * itsVerses ;
public:
    Poem(string fileName);
    ~Poem();
    void addLine(string line);
    void display();
    void displayRhymes();    
};

#endif // POEM_H
