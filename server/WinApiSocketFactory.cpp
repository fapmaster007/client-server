#include "stdafx.h"
#include "WinApiSocketFactory.h"


WinApiSocketFactory::WinApiSocketFactory()
{
}

std::shared_ptr<ClientSocket> WinApiSocketFactory::createClientSocket()
{
	return std::shared_ptr<WinApiClientSocket>(new WinApiClientSocket());
}

std::shared_ptr<ServerSocket> WinApiSocketFactory::createServerSocket()
{
	return std::shared_ptr<WinApiServerSocket>(new WinApiServerSocket());
}

std::shared_ptr<ClientSocket> WinApiSocketFactory::createClientSocket(int af, int type, int protocol)
{
	return std::shared_ptr<WinApiClientSocket>(new WinApiClientSocket(af, type, protocol));
}

std::shared_ptr<ServerSocket> WinApiSocketFactory::createServerSocket(int af, int type, int protocol)
{
	return std::shared_ptr<WinApiServerSocket>(new WinApiServerSocket(af, type, protocol));
}

WinApiSocketFactory::~WinApiSocketFactory()
{
}
