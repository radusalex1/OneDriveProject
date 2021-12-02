//#pragma once
//
//#include <iostream>
//#include <string>
//#include <WS2tcpip.h>
//
//#pragma comment (lib, "WS2_32.lib")
//#define MAX_BUFFER_SIZE (4096)
//
//typedef void(*MessageReveivedHandler)(CTcpListener* listener, int socketId, std::string msg);
//
//class CTcpListener
//{
//private:
//	std::string m_ipAddress;
//	int m_port;
//	MessageReveivedHandler MessageReceived;
//
//	SOCKET CreateSocket();
//	SOCKET WaitForConnection(SOCKET listening);
//
//public:
//	CTcpListener(std::string ipAddress, int port, MessageReveivedHandler handler);
//	~CTcpListener();
//
//	void Send(int clientSocket, std::string msg);
//	bool Init();
//	void Run();
//	void Cleanup();
//};