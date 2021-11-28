#include "server.h"

CTcpListener::CTcpListener(std::string ipAddress, int port, MessageReveivedHandler handler) : m_ipAddress(ipAddress), m_port(port), MessageReceived(handler)
{

}

CTcpListener::~CTcpListener()
{
	Cleanup();
}

void CTcpListener::Send(int clientSocket, std::string msg)
{
	send(clientSocket, msg.c_str(), msg.size() + 1, 0);
}

bool CTcpListener::Init()
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);

	int wsInit = WSAStartup(version, &data);
	
	return wsInit == 0;
}