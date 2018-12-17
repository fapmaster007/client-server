#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "ServerSocket.h"
#include "winsock2.h"
#include <string>
#include <exception>
class WinApiServerSocket : public ServerSocket
{
	SOCKET s_;
public:
	WinApiServerSocket() : s_(INVALID_SOCKET) {}
	WinApiServerSocket(int af, int type, int protocol);
	void bind(int af, std::string addr, int port) override;
	void listen(int maxcon) override;
	SOCKET getDescriptor() const override;
	void close() override;
	~WinApiServerSocket();
};

