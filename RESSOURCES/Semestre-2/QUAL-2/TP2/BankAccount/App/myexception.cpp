#include "myexception.h"


MyException::MyException(const string &phrase) throw()
{
    itsPhrase=phrase;
}

const char *MyException::what() const throw()
{
    return itsPhrase.c_str();
}

