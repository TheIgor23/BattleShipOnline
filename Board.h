
#include "Ship.h"

class Board
{
private:
    static const int BOARD_SIZE = 10;
    static const int ShipsAmount = 10;
    Ship gameBoard[BOARD_SIZE][BOARD_SIZE];
    Ship ships[ShipsAmount];

    const char letters[11] = "ABCDEFGHIJ"; 
public:

    void AutomaticShipSet();
    bool CoorFitCheck(int x1, int y1, int x2, int y2);
    bool PlaceCheck(int x1, int y1, int x2, int y2);
    Ship& GetShip(int x, int y){return gameBoard[y][x];}
   
    bool IsAllSunk();
    void Print();
    Board();
    ~Board(){};
};

