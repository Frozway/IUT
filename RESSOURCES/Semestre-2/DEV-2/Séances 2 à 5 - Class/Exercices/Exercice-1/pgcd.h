#ifndef PGCD_H
#define PGCD_H

class PGCD
{
private:
    int itsA;
    int itsB;
    int itsPGCD;
public:
    PGCD(int a, int b);
    void compute();
    void display();
    int getItsA() const;
    void setItsA(int newItsA);
    int getItsB() const;
    void setItsB(int newItsB);
    int getItsPGCD() const;
};

#endif // PGCD_H
