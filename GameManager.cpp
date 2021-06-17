#include "GameManager.h"
#include <fstream>

void GameManager::PrintLogo()
{
    std::ifstream file("print.txt");
    char* buff = new char[255];
    buff[254]='\0';

    if(!file)
    {
        std::cout<<"Error. Can't find print.txt";
        return;
    }
    while(!file.eof())
    {
        file.getline(buff, 255);
        std::cout<<buff<<std::endl;
    }

    delete[] buff;
}

int GameManager::Run()
{
    
    p1.GetBoard().AutomaticShipSet();
   
    bool IsAllEnemySunk = false;

    char xCh,yCh;
    int x, y;

    PrintLogo();

    std::string ip;
    
    std::cout<<"Please, enter server ip: ";
    
    std::cin >> ip;
    

    if(connection.SocketInit(ip.c_str()))
    {
        std::cout << "Connected!\n";
    }
    else
    {
        std::cout<<"Error connect";
    }
    
    char* MyMsg = new char[3];
    MyMsg[2] = '\0';

    char* servMes = new char[3];
	servMes[2] = '\0';
    
    do
    {
        system("cls");
        std::cout<<"\nMy board:\n";
        p1.GetBoard().Print();
        std::cout<<"\nEnemy board:\n";
        p1.GetEnemyBoard().Print();
        std::cout<<std::endl<<std::endl;


       recv(connection.GetConnection(), servMes, 2, 0);
       p1.SetId(servMes[0]);

       if(p1.GetId()=='1')
	   {
          
		    do
            {
            
                std::cout << "My turn turn!\n(a-j)(0-9)";
                std::cin >> xCh >>yCh;

                x = (int)xCh - 97;
                y = yCh - '0';
            
                std::cin.ignore(32767,'\n');

            } while ((x < 0) || (x > 9) || (y >9) || (y<0));

			
            MyMsg[0]=xCh;
            MyMsg[1]=yCh;


			send(connection.GetConnection(), MyMsg, 3, 0);

            std::cout<<"\nShoot at "<<xCh <<y<<std::endl;

            
            servMes[0]=' ';
            servMes[1]=' ';
            recv(connection.GetConnection(), servMes, 3, 0);



            
            if(servMes[0]=='y')
            {
                std::cout<<"Shoot!\n";
                p1.Fire(true ,x, y);
                if(servMes[1]=='l')
                {
                    IsAllEnemySunk = true;
                }

            }
            else if(servMes[0]=='n')
            {
                p1.Fire(false ,x, y);
                std::cout<<"Miss\n";
            }
            
           
		}
		else
		{
			servMes[0]=' ';
            servMes[1]=' ';
			    
			recv(connection.GetConnection(), servMes, 3, 0);
			std::cout <<"Enemy shoot at: "<< servMes << std::endl;

            x = (int)servMes[0] - 97;
            y = servMes[1] - '0';

            bool IsShooted = p1.Fire(x, y);
               

            if(IsShooted)
            {
                MyMsg[0] = 'y';
                if(p1.GetBoard().IsAllSunk())
                {
                    MyMsg[1] = 'l';
                }
                send(connection.GetConnection(), MyMsg, 3, 0);
                
            }
            else
            {
                MyMsg[0] = 'n';
                send(connection.GetConnection(), MyMsg, 3, 0);
            }

        }
		
    } while (!p1.GetBoard().IsAllSunk() && !IsAllEnemySunk);
    
   
    if(p1.GetBoard().IsAllSunk())
        std::cout<<"\n\nYou lose!\n\n";
    else
        std::cout<<"\n\nYou Win\n\n";
   

    system("pause");
    

    delete[] servMes;
    delete[] MyMsg;
    return 1;
}


