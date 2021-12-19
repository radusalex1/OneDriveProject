#include "Client_Class.h"
#include <QtCore/qlogging.h>
Client_Class::Client_Class()
{
	//default
}
SOCKET Client_Class::initializeSocket()
{
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	if (WSAStartup(ver, &wsData) != 0) {
		//std::cerr << "Error starting winsock!" << std::endl;
		return -1;
	}

	SOCKET clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientSock == INVALID_SOCKET) {
		//std::cerr << "Error creating socket!, " << WSAGetLastError() << std::endl;
		return -1;
	}
	std::string serverAddress = "192.168.1.5";

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(8080);
	inet_pton(AF_INET, serverAddress.c_str(), &hint.sin_addr);
	if (connect(clientSock, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR) {
		//std::cerr << "Error connect to server!, " << WSAGetLastError() << std::endl;
		closesocket(clientSock);
		WSACleanup();
		return -1;
	}
	return clientSock;
}
