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
void Client::sendFiles(std::string SourcePathFile,std::string DestinationPath)
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

	std::string userInput;
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

	std::string fileRequested;

	file.open(SourcePathFile);

	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		long fileSize = file.tellg();
		int64_t bytesToBeSent = fileSize;

		int bySendInfo = send(sock, (char*)&fileSize, sizeof(long), 0);
		bySendInfo = send(sock, DestinationPath.c_str(), FILENAME_MAX, 0);
		bySendInfo = send(sock, SourcePathFile.c_str(), FILENAME_MAX, 0);

		file.seekg(0, std::ios::beg);

		while (bytesToBeSent > 0)
		{
			/// <summary>
			/// 1894 primul caracter gresit!!!!!!!
			/// </summary>

			const uint32_t ssize = min((int)bytesToBeSent, (int)4096);
			char* buf = new char[ssize];

			strcpy(buf, "");

			ZeroMemory(buf, sizeof(buf));

			file.read(buf, ssize);

			//removeChars(buf);

			if (sizeof(buf) > ssize)
			{
				break;
			}
			std::cerr << buf << std::endl;

			bySendInfo = send(sock, buf, int(ssize), 0);

			if (bySendInfo < 0)
			{
				closesocket(sock);
				break;
			}
			bytesToBeSent -= bySendInfo;
		}

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
