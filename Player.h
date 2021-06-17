
#include "Board.h"

class Player
{
private:
    char id;
    
   
    Board myBoard;
    Board EnemyBoard;
public:
    Board& GetBoard(){return myBoard;}
    Board& GetEnemyBoard(){return EnemyBoard;}

    void Fire(bool isShooted, int x, int y);
    bool Fire(int x, int y);

    

    void SetId(char Id){id = Id;}
    char GetId(){return id;}

    Player(){};
    ~Player(){};
};


