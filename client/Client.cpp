// Client.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Client.h"
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include "../Server/WSAStartupSingleton.h"
#include "../Server/WinApiServerSocket.h"
#include "../Server/WinApiClientSocket.h"
#include "../Server/WinApiSocketFactory.h"
#include <sstream>
#include <fstream>
#include "../Server/XmlParser.h"

void Client::connect()
{
	wsa = WSAStartupSingleton::instance();
#ifdef _WIN32
	WinApiSocketFactory sockets;
#endif // _WIN32

	try
	{
		client = sockets.createClientSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		client->connect(AF_INET, server_addr_, server_port_);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << '\n';
		wsa->getLastError();
		throw;
	}
}

void Client::send(std::string filename)
{
	try
	{
		std::fstream f;
		std::stringstream stream;
		XmlParser xml("<root></root>");
		f.open(filename);
		if (!f.is_open())
			throw std::exception("file not found exception");
		stream << f.rdbuf();
		xml.parse("root").insertNode("filename").setValues(std::vector<std::string>{filename});
		xml.parse("root").insertNode("data").setValues(std::vector<std::string>{stream.str()});
		client->send(xml.getBuf());
		f.close();
		std::cout << "Send success\n";
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << '\n';
		wsa->getLastError();
		throw;
	}
}

