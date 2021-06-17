
#include "Player.h"
#include "Connection.h"

class GameManager
{
private:
    Player p1;
    Connection connection;
public:
    GameManager(){};
    ~GameManager(){};
    void PrintLogo();
    int Run();
    
};
