#pragma once
#include <string>
#include <WS2tcpip.h>
class Client_Class
{
public:
	SOCKET initializeSocket();
	void sendFiles(std::string,std::string);
	void getFiles(std::string,std::string);

};

