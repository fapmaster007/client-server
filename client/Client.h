#pragma once
#include <string>
#include "..\Server\ClientSocket.h"
#include "..\Server\WSAStartupSingleton.h"
class Client
{
	std::string server_addr_;
	int server_port_;
	std::shared_ptr<ClientSocket> client;
	std::shared_ptr<WSAStartupSingleton> wsa;
public:
	Client(std::string server_addr, int server_port) : server_addr_(server_addr),
		server_port_(server_port) {}
	void connect();
	void send(std::string filename);
};