#include "Connection.h"


bool Connection::SocketInit(const char* dest_adr)
{
    if(result != 0) {
		exit(1);
	}

    dest.sin_addr.s_addr = inet_addr(dest_adr);
    dest.sin_port = htons(1111);
	dest.sin_family = AF_INET;

    con_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(connect(con_socket, (SOCKADDR*)&dest, sizeof(dest)) != 0) {
		
		return false;
	}

    
    return true;
}

Connection::Connection()
{
    result = WSAStartup(MAKEWORD(2, 2), &WsaData);
    
}

Connection::~Connection()
{
    WSACleanup();
}
