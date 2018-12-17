#pragma once
#include <string>
#include <memory>
#include "ServerSocket.h"
class ClientSocket
{
public:
	ClientSocket();
	virtual void connect(int af, std::string addr, int port) = 0;
	virtual void accept(std::shared_ptr<ServerSocket> sock) = 0;
	virtual SOCKET getDescriptor() const = 0;
	virtual void send(std::string data) = 0;
	virtual std::string recv(size_t buff_len) = 0;
	virtual void shutdown(int how) = 0;
	virtual void close() = 0;
	virtual ~ClientSocket();
};

