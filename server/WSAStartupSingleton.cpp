#include "stdafx.h"
#include "WSAStartupSingleton.h"


WSAStartupSingleton::WSAStartupSingleton()
{
}

std::shared_ptr<WSAStartupSingleton> WSAStartupSingleton::s_ = nullptr;

std::shared_ptr<WSAStartupSingleton> WSAStartupSingleton::instance()
{
	if (!s_)
	{
		s_ = std::shared_ptr<WSAStartupSingleton>(new WSAStartupSingleton());
		WSADATA w;
		WSAStartup(2.2, &w);
	}
	return s_;
}

void WSAStartupSingleton::getLastError()
{
	std::cout << "Error code: " << WSAGetLastError() << std::endl;
}


WSAStartupSingleton::~WSAStartupSingleton()
{
	WSACleanup();
}
