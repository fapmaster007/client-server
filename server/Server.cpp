#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include "WSAStartupSingleton.h"
#include "WinApiServerSocket.h"
#include "WinApiClientSocket.h"
#include "WinApiSocketFactory.h"
#include "Server.h"
#include <thread>
#include "XmlParser.h"
#include <sstream>
#include <fstream>
#include <exception>

void Server::run()
{
	is_run = true;
	auto wsa = WSAStartupSingleton::instance();
	std::thread serv ([&]() {
	try
	{
#ifdef _WIN32
	WinApiSocketFactory sockets;
#endif
	std::fstream f;
	std::stringstream stream;
	auto server = sockets.createServerSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	server->bind(AF_INET, addr_, port_);
	server->listen(SOMAXCONN);
	auto incoming = sockets.createClientSocket();
	while (is_run)
	{
		incoming->accept(server);
		if (incoming->getDescriptor() != INVALID_SOCKET)
		{
			stream << incoming->recv(buff_size_);
			XmlParser xml(stream.str());
			CreateDirectoryA(foldername_.c_str(), NULL);
			f.open(foldername_+"\\"+xml.parse("root").parse("filename").getValues()[0].c_str(), std::fstream::out);
			f << xml.parse("root").parse("data").getValues()[0];
			f.close();
		}
	}
		}
	catch (std::exception& ex)
	{
		is_run = false;
		std::cout << ex.what() << std::endl;
		wsa->getLastError();
	}});
	serv.detach();
}

void Server::stop()
{
	is_run = false;
}

Server::~Server()
{
}
