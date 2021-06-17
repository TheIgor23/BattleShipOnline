#include "Ship.h"

std::ostream& operator<< (std::ostream &out, const Ship &ship)
{
    if(ship.size > 0)
    {
        if(ship.IsSunk) out << '*';
        else out << 'X';
    }
    else 
    {
        if(ship.IsFiredUpon) out << '`';
        else out<<' ';
    }
    return out;
}

Ship::Ship(bool isSunk, int sz): IsSunk(isSunk), size(sz)
{

}

Ship::Ship(): IsSunk(false),  IsFiredUpon(false), size(0)
{
    
}

