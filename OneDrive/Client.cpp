#include "Client.h"
#include <iostream>
#include <fstream>
#include <string>
#include <WS2tcpip.h>
/// <summary>
/// get is for get file from server to client given the path from the server
/// send is for send files from client to server given the 
/// </summary>
/// <param name="path"></param>
void Client::sendFiles(std::string path)
{
	std::string ipAddress = "127.0.0.1";  //ipadress
	uint32_t port = 54000;					  //listening port

	///initialize winsock
	WSADATA data;
	WORD ver = MAKEWORD(2, 2);
	uint32_t wsResult = WSAStartup(ver, &data);

	if (wsResult != 0)
	{
		std::cerr << "cant start winsock" << wsResult << std::endl;
		WSACleanup();
		return;
	}
	///create a socked

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		std::cerr << "cant create socket. err#" << WSAGetLastError() << std::endl;
		return;
	}

	/// fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	/// connect to server
	uint32_t connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		std::cerr << "cant con to server, err#" << WSAGetLastError() << std::endl;
		closesocket(sock);
		WSACleanup();
		return;
	}
	char buf[32768];
	std::string userInput;
	std::cout << "1-get, 2-send" << std::endl;
	userInput = "send";

	uint32_t sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
	if (sendResult == SOCKET_ERROR)
	{
		std::cerr << "error\n";
		
	}
	else
	{
		std::cerr << "server> i'm getting the file" << std::endl;
	}

	std::ifstream file;
	char fileRequested[FILENAME_MAX];

	strcpy(fileRequested, path.c_str());

	file.open(fileRequested, std::ios::binary);

	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		long fileSize = file.tellg();
		uint32_t bySendInfo = send(sock, (char*)&fileSize, sizeof(long), 0);
		bySendInfo = send(sock, fileRequested, FILENAME_MAX, 0);
		file.seekg(0, std::ios::beg);
		do
		{
			file.read(buf, 4096);
			if (file.gcount() > 0)
			{
				bySendInfo = send(sock, buf, file.gcount(), 0);
			}
			if (bySendInfo == 0 || bySendInfo == -1) {
				// error sending data - break loop
				closesocket(sock);
				break;
			}
		} while (file.gcount() > 0);
		file.close();
	}
	else
	{
		std::cerr << "file not found\n";
	}

}

void Client::getFiles(std::string path)
{
	std::string ipAddress = "127.0.0.1";  //ipadress
	uint32_t port = 54000;					  //listening port

	///initialize winsock
	WSADATA data;
	WORD ver = MAKEWORD(2, 2);
	uint32_t wsResult = WSAStartup(ver, &data);

	if (wsResult != 0)
	{
		std::cerr << "cant start winsock" << wsResult << std::endl;
		WSACleanup();
		return;
	}
	///create a socked

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		std::cerr << "cant create socket. err#" << WSAGetLastError() << std::endl;
		return;
	}

	/// fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	/// connect to server
	uint32_t connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		std::cerr << "cant con to server, err#" << WSAGetLastError() << std::endl;
		closesocket(sock);
		WSACleanup();
		return;
	}
	char buf[32768];
	std::string userInput;
	std::cout << "1-get, 2-send" << std::endl;
	userInput = "get";

	std::ofstream file;
	char fileRequested[FILENAME_MAX];
	uint32_t fileDownloaded = 0;
	long fileRequestedSize = 0;

	strcpy(fileRequested, path.c_str());

	uint32_t sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);

	if (sendResult == SOCKET_ERROR)
	{
		std::cerr << "error\n";
	}
	else
	{
		std::cerr << "server> i'm sending the file" << std::endl;
	}
	sendResult = send(sock, fileRequested, FILENAME_MAX, 0);

	if (sendResult != SOCKET_ERROR)
	{
		uint32_t bytesReceived = recv(sock, (char*)&fileRequestedSize, sizeof(long), 0);
		ZeroMemory(buf, 4096);
		//bytesReceived = recv(sock, buf, 32768, 0);

		if (bytesReceived > 0)
		{
			file.open(fileRequested, std::ios::binary, std::ios::trunc);
			do {
				memset(buf, 0, 4096);
				bytesReceived = recv(sock, buf, 4096, 0);
				if (bytesReceived == 0 || bytesReceived == -1)
				{
					break;
				}
				file.write(buf, bytesReceived);
				fileDownloaded += bytesReceived;
			} while (fileDownloaded < fileRequestedSize);
			file.close();
		}

	}
	else
	{
		std::cerr << "file not found\n";
	}


}
