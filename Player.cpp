#include "Player.h"

void Player::Fire(bool isShooted, int x, int y)
{

    if(isShooted)
    {
        EnemyBoard.GetShip(x,y).SetSize(1);
          
        EnemyBoard.GetShip(x,y).SetIsSunk(true);
        EnemyBoard.GetShip(x, y).SetIsFiredUpon(true);

    }
    else
    {
        EnemyBoard.GetShip(x, y).SetIsFiredUpon(true);
        
    }
}

bool Player::Fire(int x, int y)
{

    myBoard.GetShip(x, y).SetIsFiredUpon(true);

    if(myBoard.GetShip(x,y).GetSize()>0)
    {
       
        myBoard.GetShip(x, y).SetIsSunk(true);
        return true;
    }
    
    return false;
}

