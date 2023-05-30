#ifndef LINE_H
#define LINE_H

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class Line
{
    friend bool operator == (const Line &line1, const Line& line2);
private:
    string itsLine ;
public:
    Line(string line);
    void display();
};

#endif // LINE_H
