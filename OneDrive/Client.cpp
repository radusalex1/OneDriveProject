#include "Client_Class.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <WS2tcpip.h>

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
	std::string serverAddress = "127.0.0.1";

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(55000);
	inet_pton(AF_INET, serverAddress.c_str(), &hint.sin_addr);
	if (connect(clientSock, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR) {
		std::cerr << "Error connect to server!, " << WSAGetLastError() << std::endl;
		closesocket(clientSock);
		WSACleanup();
		return -1;
	}
	return clientSock;
}
/// <summary>
/// get is for get file from server to client given the path from the server
/// send is for send files from client to server given the 
/// </summary>
/// <param name="path"></param>
void Client_Class::sendFiles(std::string SourcePathFile,std::string DestinationPath)
{
	SOCKET sock = initializeSocket();
	bool clientClose = false;

	const int BUFFER_SIZE = 1024;
	char bufferFile[BUFFER_SIZE];

	std::ifstream file;

	std::string fileRequested = SourcePathFile;
	std::filesystem::path p(fileRequested);
	std::string destinationPath = DestinationPath;

	do {

		int byRecv = send(sock, p.filename().string().c_str(), FILENAME_MAX, 0); //send filename
		send(sock, destinationPath.c_str(), FILENAME_MAX, 0); //send desti path
		if (byRecv == 0 || byRecv == -1) {
			// error receive data - break loop
			clientClose = true;
		}

		// open file
		file.open(fileRequested, std::ios::binary);

		// get file size
		file.seekg(0, std::ios::end);
		long fileSize = file.tellg();

		// send filesize to client
		int bySendinfo = send(sock, (char*)&fileSize, sizeof(long), 0);

		if (bySendinfo == 0 || bySendinfo == -1) {
			// error sending data - break loop
			clientClose = true;
		}
		file.seekg(0, std::ios::beg);
		// read file with do-while loop
		do {
			// read and send part file to client
			file.read(bufferFile, BUFFER_SIZE);
			if (file.gcount() > 0)
				bySendinfo = send(sock, bufferFile, file.gcount(), 0);

			if (bySendinfo == 0 || bySendinfo == -1) {
				// error sending data - break loop
				clientClose = true;
				break;
			}
		} while (file.gcount() > 0);
		file.close();

	} while (file.is_open());
}

void Client_Class::getFiles(std::string PathToFileToBeDownloaded,std::string PathWhereToDownload)
{
	

}
