#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#pragma warning(disable: 4996)

int main(int argc, char* argv[]) {
	
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	std::cout << "Enter ip: ";
	char* ip = new char[16];
	ip[15] = '\n';
	std::cin >> ip;

	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);


	int Counter = 0;
	SOCKET newConnection;
	SOCKET Connections[2];
	for (int i = 0; i < 2; i++) {
		
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cout << "Error #2\n";
			return -1;
		}
		else {
			std::cout << "Client Connected!\n";
			
			Connections[i] = newConnection;
			Counter++;
			

		}
	}

	std::cout << "All connected!\n";
	SOCKET* curPlayer = &Connections[0];
	SOCKET* nextPlayer = &Connections[1];

	

	while (true) {
		send(*curPlayer, "1" , 2, NULL);
		send(*nextPlayer, "2", 2, NULL);

		char* msg = new char[3];
		msg[2] = '\0';


		recv(*curPlayer, msg, 3, NULL);
		send(*nextPlayer, msg, 3, NULL);
		recv(*nextPlayer, msg, 3, NULL);
		send(*curPlayer, msg, 3, NULL);

		if (msg[0] == 'n')
		{
			if (curPlayer == &Connections[0])
			{
				curPlayer = &Connections[1];
				nextPlayer = &Connections[0];
			}
			else if (curPlayer == &Connections[1])
			{
				curPlayer = &Connections[0];
				nextPlayer = &Connections[1];
			}
		}
		if (msg[1] == 'l')
		{
			std::cout << "Game End";
			system("pause");
			return 0;
		}
		delete[] msg;
	}
	
	system("pause");
	return 0;
}