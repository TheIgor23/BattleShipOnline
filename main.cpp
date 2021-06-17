#include "GameManager.h"
#include <time.h>
int main()
{
   
	srand(time(0));

    GameManager gm;
   
    return gm.Run();
   
}