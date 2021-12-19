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
	
};
