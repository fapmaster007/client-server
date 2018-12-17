#include "stdafx.h"
#include "WinApiClientSocket.h"


WinApiClientSocket::WinApiClientSocket(int af, int type, int protocol)
{
	s_ = socket(af, type, protocol);
	if(s_ == INVALID_SOCKET)
	{
		throw std::exception("Error creating socket");
	}
}

void WinApiClientSocket::connect(int af, std::string addr, int port)
{
	IN_ADDR in_adr;
	in_adr.S_un.S_addr = inet_addr(addr.c_str());
	SOCKADDR_IN adr{ af, port, in_adr };
	if (::connect(s_, (SOCKADDR*)&adr, sizeof(SOCKADDR_IN)))
		throw std::exception("Error connection socket");
}

void WinApiClientSocket::accept(std::shared_ptr<ServerSocket> sock)
{
	s_ = ::accept(sock->getDescriptor(), NULL, NULL);
}

SOCKET WinApiClientSocket::getDescriptor() const
{
	return s_;
}

void WinApiClientSocket::send(std::string data)
{
	if (::send(s_, data.c_str(), data.size(), NULL) == SOCKET_ERROR)
		throw std::exception("send data error");
}

std::string WinApiClientSocket::recv(size_t buff_len)
{
	char *buf = new char[buff_len] {};
	if (::recv(s_, buf, buff_len, NULL) == SOCKET_ERROR)
		throw std::exception("recv error");
	return std::string(buf);
}

void WinApiClientSocket::shutdown(int how)
{
	if (::shutdown(s_, how))
		throw std::exception("Shutdown socket exception");
}

void WinApiClientSocket::close()
{
	if (closesocket(s_))
		throw std::exception("Close socket exception");
}

WinApiClientSocket::~WinApiClientSocket()
{
}
