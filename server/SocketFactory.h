#pragma once
#include "ClientSocket.h"
#include "ServerSocket.h"
#include <memory>
class SocketFactory
{
public:
	SocketFactory();
	virtual std::shared_ptr<ClientSocket> createClientSocket() = 0;
	virtual std::shared_ptr<ServerSocket> createServerSocket() = 0;
	virtual std::shared_ptr<ClientSocket> createClientSocket(int af, int type, int protocol) = 0;
	virtual std::shared_ptr<ServerSocket> createServerSocket(int af, int type, int protocol) = 0;
	virtual ~SocketFactory();
};

