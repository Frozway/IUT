#include "merchandise.h"

int Merchandise::getItsWeigth() const
{
    return itsWeigth;
}

int Merchandise::getItsVolume() const
{
    return itsVolume;
}

Merchandise::Merchandise(int weigth, int volume)
{
    itsWeigth = weigth ;
    itsVolume = volume ;
}

bool operator==(const Merchandise& merchandiseA, const Merchandise& merchandiseB)
{
    return (merchandiseA.itsVolume == merchandiseB.itsVolume && merchandiseA.itsWeigth == merchandiseB.itsWeigth);
}
