#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    string itsName;
    int itsWeigth;
public:
    Person(string name, int weight);
    string getItsName() const;
    void setItsName(const string &value);
    int getItsWeigth() const;
    void setItsWeigth(int value);
    void display();
    bool operator==(const Person & person) const;
};

#endif // PERSON_H
