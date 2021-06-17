
#include <iostream>
class Ship
{
private:
    bool IsSunk;
    bool IsFiredUpon;

    short int size;
public:
    
    void SetIsSunk(bool stat) {IsSunk = stat;}
    bool GetIsSunk() {return IsSunk; }

    void SetIsFiredUpon(bool stat) {IsFiredUpon = stat;}
    bool GetIsFiredUpon(){return IsFiredUpon;}

    void SetSize(int sz) {size=sz;}
    short int GetSize() {return size;}

    friend std::ostream& operator<< (std::ostream &out, const Ship &ship);
    Ship();
    Ship(bool isSunk, int sz);
    ~Ship(){};
};

