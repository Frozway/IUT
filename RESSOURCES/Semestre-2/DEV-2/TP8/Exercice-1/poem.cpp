#include "poem.h"

using namespace std ;

Poem::Poem(string fileName)
{
    itsVerses = new vector<Verse*> ;

    ifstream ifs(fileName);

    if(ifs.is_open())
    {
        string line ;
        Verse * theVerse = new Verse ;

        while(!ifs.eof())
        {
            getline(ifs, line);


            if(line.length() > 0)
            {
                theVerse->addLine(line);
            }
            else
            {
                itsVerses->push_back(theVerse) ;
                theVerse = new Verse() ;
            }

        }
        delete theVerse ;
    }
    ifs.close() ;
}

Poem::~Poem()
{
    for (vector<Verse *>::iterator it = itsVerses->begin() ; it != itsVerses->end() ; it++)
    {
        delete (*it) ;
    }
    delete itsVerses ;
}



