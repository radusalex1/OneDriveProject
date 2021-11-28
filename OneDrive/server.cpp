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