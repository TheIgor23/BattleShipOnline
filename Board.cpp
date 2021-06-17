#include "Board.h"
#include <iomanip>
void Board::Print()
{
    
    std::cout << "  ";


    for (int i = 0; i < Board::BOARD_SIZE; i++)
    {
        std::cout << letters[i] << ' ';
    }

    std::cout << std::endl;

    for (int i = 0; i < Board::BOARD_SIZE; i++)
    {
        std::cout  << i;
        for (int j = 0; j < Board::BOARD_SIZE; j++)
        {
            std::cout << '|' << gameBoard[i][j];
        } 
        std::cout << '|'<<std::endl;
    }
    
}

bool Board::CoorFitCheck(int x1, int y1, int x2, int y2) 
{
    if((x1 >= 0 && x1 < BOARD_SIZE) && (x2 >= 0 && x2 < BOARD_SIZE) && (y1 >= 0 && y1 < BOARD_SIZE) && (y2 >= 0 && y2 < BOARD_SIZE)) { return true; }

    return false;
}

bool Board::IsAllSunk()
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            if(!gameBoard[i][j].GetIsSunk() && gameBoard[i][j].GetSize() > 0)
                return false;
        }
        
    }
    return true;
}

bool Board::PlaceCheck(int x1, int y1, int x2, int y2)
{
    //horiz
    if(y1==y2)
    {

        for(int j=-1;j<=1;j++)
        {
            for(int i = -1; i <= (x2-x1)+1; i++)
            {
                if(CoorFitCheck(x1+i, y1+j,x1+i, y1+j))
                {
                    if(gameBoard[y1+j][x1+i].GetSize()>0)
                        return false;
                }
                else continue;
                
            }
        }
        
    }
     //vert
    else if(x1==x2)
    {
        for(int j=-1;j<=1;j++)
        {
            for(int i = -1; i <= (y2-y1)+1; i++)
            {
                if(CoorFitCheck(x1+j, y1+i,x1+j, y1+i))
                {
                    if(gameBoard[y1+i][x1+j].GetSize()>0)
                        return false;
                }
                else continue;
            }
        }
    }
    return true;

}



void Board::AutomaticShipSet()
{
   int xStart, xEnd, yStart, yEnd, dir;

    for(int i = 0; i < ShipsAmount; i++)
    {

        do
        {
            xStart=rand() % BOARD_SIZE;
            xEnd=xStart;
            yStart=rand() % BOARD_SIZE;
            yEnd=yStart;

            dir = rand()%2;
       
            //horiz
            if(dir==0)
            {
                xEnd+=(ships[i].GetSize()-1);
            }
            //vert
            else
            {
                yEnd+=(ships[i].GetSize()-1);
            }
        } while (!CoorFitCheck(xStart, yStart, xEnd, yEnd) || !PlaceCheck(xStart, yStart, xEnd, yEnd));
        
        

       
            for(int j = 0; j<ships[i].GetSize(); j++)
            {
                if(dir==0)
                {
                    gameBoard[yStart][xStart+j] = ships[i];
                }
                else
                {
                    gameBoard[yStart+j][xStart] = ships[i];
                }
            }
        

    }

    
   
    
}
Board::Board()
{
    ships[0] = Ship(false, 4);
    ships[1] = Ship(false, 3);
    ships[2] = Ship(false, 3);
    ships[3] = Ship(false, 2);
    ships[4] = Ship(false, 2);
    ships[5] = Ship(false, 2);
    ships[6] = Ship(false, 1);
    ships[7] = Ship(false, 1);
    ships[8] = Ship(false, 1);
    ships[9] = Ship(false, 1);
    
}

