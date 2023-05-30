#include "verse.h"
#include"line.h"

Verse::Verse()
{
    itsLines = new vector<Line*> ;
}

void Verse::addLine(string line)
{
    itsLines->push_back(new Line(line));
}
