#include "server.h"

CTcpListener::CTcpListener(std::string ipAddress, int port, MessageReveivedHandler handler) : m_ipAddress(ipAddress), m_port(port), MessageReceived(handler)
{

}

CTcpListener::~CTcpListener()
{
	Cleanup();
}