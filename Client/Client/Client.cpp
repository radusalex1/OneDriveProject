#include <iostream>
#include <fstream>
#include <WS2tcpip.h>
#include <filesystem>
#include <string>
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
#pragma comment(lib, "ws2_32.lib")
std::ifstream file_getdetails("D:\\Facultate\\FacultateAnul2\\ModernC++\\OneDriveProject\\OneDrive\\SendFilesDetails.txt");
//std::ifstream file_getdetailsForGet("D:\\Facultate\\FacultateAnul2\\ModernC++\\OneDriveProject\\OneDrive\\GetFilesDetails.txt");

SOCKET initializeSocket()
{
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	if (WSAStartup(ver, &wsData) != 0) {
		std::cerr << "Error starting winsock!" << std::endl;
		return -1;
	}

	SOCKET clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientSock == INVALID_SOCKET) {
		std::cerr << "Error creating socket!, " << WSAGetLastError() << std::endl;
		return -1;
	}
	std::string serverAddress="127.0.0.1";

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
std::string userInputFunction()
{
	std::string option;
	std::getline(file_getdetails, option);
	if (option == "1")
	{
		return "send";
	}
	else
	{
		return "get";
	}
}
std::string SendUserOption(SOCKET sock)
{
	std::string userInput = userInputFunction();
	int userOption = send(sock, userInput.c_str(), sizeof(int), 0);
	if (userOption == 0 || userOption == -1) {
		closesocket(sock);
		WSACleanup();
		return NULL ;
	}
	return userInput;
}
std::string SourcePath()
{
	char fileRequested[FILENAME_MAX];
	memset(fileRequested, 0, FILENAME_MAX);
	std::cout << "Enter path to source file:\n";
	std::cin.getline(fileRequested, FILENAME_MAX);
	return fileRequested;
}
std::string DestinationPath()
{
	std::string pathRequested;
	std::cout << "Enter path to destination directory:\n";
	std::getline(std::cin, pathRequested);
	return pathRequested;
}
void GetFiles(SOCKET sock)
{
	std::ofstream file;
	bool clientClose = false;
	long fileRequestedsize = 0;

	const int BUFFER_SIZE = 1024;
	char bufferFile[BUFFER_SIZE];
	//char fileRequested[FILENAME_MAX];

		int fileDownloaded = 0;
		
		std::string fileRequested;
		std::getline(file_getdetails, fileRequested);

		std::filesystem::path p(fileRequested);
		std::string fileName = p.filename().string();

		std::string destinationPath;
		std::getline(file_getdetails, destinationPath);
		std::string Path = destinationPath + fileName;
		sleep_for(nanoseconds(10000));
		//std::cin.getline(fileRequested, FILENAME_MAX);
		
		


			int byRecv = send(sock, fileRequested.c_str(), FILENAME_MAX, 0);
			if (byRecv == 0 || byRecv == -1) {
				clientClose = true;
				sock = true;
				return;
			}


			byRecv = recv(sock, (char*)&fileRequestedsize, sizeof(long), 0);
			if (byRecv == 0 || byRecv == -1) {
				clientClose = true;
				return;
			}

			file.open(Path, std::ios::binary | std::ios::trunc);

			do {
				memset(bufferFile, 0, BUFFER_SIZE);
				byRecv = recv(sock, bufferFile, BUFFER_SIZE, 0);

				if (byRecv == 0 || byRecv == -1) {
					clientClose = true;
					break;
					return;
				}

				file.write(bufferFile, byRecv);
				fileDownloaded += byRecv;
			} while (fileDownloaded < fileRequestedsize);
			
			file.close();

}
void SendFiles(SOCKET sock)
{
	bool clientClose = false;

	const int BUFFER_SIZE = 1024;
	char bufferFile[BUFFER_SIZE];

	std::ifstream file;

	std::string fileRequested;
	std::getline(file_getdetails, fileRequested);
	std::filesystem::path p(fileRequested);
	std::string destinationPath;
	std::getline(file_getdetails, destinationPath);
	std::cerr << fileRequested << "\n";
	std::cerr << destinationPath << "\n";
	sleep_for(nanoseconds(5000));

	do {

		int byRecv = send(sock, p.filename().string().c_str(), FILENAME_MAX, 0); //send filename
		send(sock,destinationPath.c_str(),FILENAME_MAX,0); //send desti path
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
void main() 
{
//C:\Users\Radu\Desktop\ServerDocuments\
//D:/BackgroundLoginImg.jpg

	SOCKET sock = initializeSocket();
	
	char welcomeMsg[255];
	
	if (SendUserOption(sock) == "get")
	{
		SendFiles(sock);
	}
	else
	{
		GetFiles(sock);
	}


	closesocket(sock);


	WSACleanup();
}
