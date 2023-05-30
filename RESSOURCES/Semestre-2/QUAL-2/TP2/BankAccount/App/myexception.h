#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class MyException : public exception
{
private:
    string itsPhrase;
public:
    MyException(const string &phrase) throw();
    const char* what() const throw();
};

#endif // MYEXCEPTION_H
