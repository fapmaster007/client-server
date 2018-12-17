#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "ClientSocket.h"
#include "ServerSocket.h"
#include <string>
#include "winsock2.h"
#include <exception>
#include <memory>
class WinApiClientSocket : public ClientSocket
{
	SOCKET s_;
public:
	WinApiClientSocket() : s_(INVALID_SOCKET) {}
	WinApiClientSocket(int af, int type, int protocol);
	void connect(int af, std::string addr, int port) override;
	void accept(std::shared_ptr<ServerSocket> sock) override;
	SOCKET getDescriptor() const override;
	void send(std::string data) override;
	std::string recv(size_t buff_len) override;
	void shutdown(int how) override;
	void close() override;
	~WinApiClientSocket();
};

