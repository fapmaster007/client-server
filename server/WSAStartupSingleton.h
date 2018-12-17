#pragma once
#include <memory>
#include <winsock2.h>
#include <iostream>
class WSAStartupSingleton
{
	static std::shared_ptr<WSAStartupSingleton> s_;
	WSAStartupSingleton();
public:
	static std::shared_ptr<WSAStartupSingleton> instance();
	void getLastError();
	~WSAStartupSingleton();
};

