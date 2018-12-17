#include "stdafx.h"
#include "WinApiServerSocket.h"


WinApiServerSocket::WinApiServerSocket(int af, int type, int protocol)
{
	s_ = socket(af, type, protocol);
	if (s_ == INVALID_SOCKET)
	{
		throw std::exception("Error creating socket");
	}
}

void WinApiServerSocket::bind(int af, std::string addr, int port)
{
	IN_ADDR in_adr;
	in_adr.S_un.S_addr = inet_addr(addr.c_str());
	SOCKADDR_IN adr{ af, port, in_adr };
	if (::bind(s_, (SOCKADDR*)(&adr), sizeof(SOCKADDR))) 
		throw std::exception("Error binding socket");
}

void WinApiServerSocket::listen(int maxcon)
{
	if (::listen(s_, maxcon))
		throw std::exception("Error listen socket");
}

SOCKET WinApiServerSocket::getDescriptor() const
{
	return s_;
}

void WinApiServerSocket::close()
{
	if (closesocket(s_))
		throw std::exception("Close socket exception");
}


WinApiServerSocket::~WinApiServerSocket()
{
}
