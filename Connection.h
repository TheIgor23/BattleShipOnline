#pragma omnce

#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

class Connection
{
private:
    WSADATA WsaData;
    int result;
    
    sockaddr_in dest;
    //sockaddr_in local;
    SOCKET con_socket;


public:
    SOCKET& GetConnection(){return con_socket;}

    bool SocketInit(const char* dest_adr);
    Connection();
    ~Connection();
};

