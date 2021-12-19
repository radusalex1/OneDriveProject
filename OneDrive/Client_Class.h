#include <winsock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#pragma comment(lib, "ws2_32.lib")
class Client_Class
{
public:
	Client_Class();
	SOCKET initializeSocket();
	/*void SendUserOption(SOCKET sock,std::string);
	void sendFiles(std::string,std::string);
	void getFiles(std::string,std::string);*/

};
