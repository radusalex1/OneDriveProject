#include "Client.h"
#include <iostream>
#include <fstream>
#include <filesystem>
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
	int port = 54000;					  //listening port

	///initialize winsock
	WSADATA data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);

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
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		std::cerr << "cant con to server, err#" << WSAGetLastError() << std::endl;
		closesocket(sock);
		WSACleanup();
		return;
	}

	std::string userInput;
	userInput = "send";

	int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);

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

			const int ssize = min((int)bytesToBeSent, (int)4096);
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

void Client::getFiles(std::string PathToFileToBeDownloaded,std::string PathWhereToDownload)
{
	std::string ipAddress = "127.0.0.1";  //ipadress
	int port = 54000;					  //listening port

	///initialize winsock
	WSADATA data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);

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
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		std::cerr << "cant con to server, err#" << WSAGetLastError() << std::endl;
		closesocket(sock);
		WSACleanup();
		return;
	}
	std::string userInput;
	userInput = "get";

	int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);

	if (sendResult == SOCKET_ERROR)
	{
		std::cerr << "error\n";
		
	}
	else
	{
		std::cerr << "server> i'm sending the file" << std::endl;
	}

	std::ofstream file;

	PathWhereToDownload += std::filesystem::path(PathToFileToBeDownloaded).filename().string();

	sendResult = send(sock, PathToFileToBeDownloaded.c_str(), FILENAME_MAX, 0);

	uint64_t fileSize = 0;
	int bytesReceived = recv(sock, (char*)&fileSize, sizeof(uint64_t), 0);
	if (bytesReceived > 0)
	{
		file.open(PathWhereToDownload.c_str());
		int64_t i = fileSize;
		while (i > 0)
		{
			const int64_t ssize = min((int64_t)i, (int64_t)4096);
			char* buff = new char[ssize];
			const int r = recv(sock, buff, ssize, 0);
			if (r < 0)
			{
				break;
			}
			file.write(buff, r);
			i -= r;
		}
		file.close();
	}
	else
	{
		std::cerr << "file not found\n";
	}

}
