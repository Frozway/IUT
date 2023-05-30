#ifndef MERCHANDISE_H
#define MERCHANDISE_H


class Merchandise
{
private:
    int itsWeigth ;
    int itsVolume ;
public:
    Merchandise(int weigth, int volume);
    int getItsWeigth() const;
    int getItsVolume() const;
    friend bool operator == (const Merchandise& merchandiseA, const Merchandise& merchandiseB)  ;
};

#endif // MERCHANDISE_H
