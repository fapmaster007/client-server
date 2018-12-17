#pragma once
#include <string>
#include "winsock2.h"
class ServerSocket
{
public:
	ServerSocket();
	virtual void bind(int af, std::string addr, int port) = 0;
	virtual void listen(int maxcon) = 0;
	virtual SOCKET getDescriptor() const = 0;
	virtual void close() = 0;
	virtual ~ServerSocket();
};

