#pragma once
#include "SocketFactory.h"
#include "WinApiClientSocket.h"
#include "WinApiServerSocket.h"
#include <memory>
class WinApiSocketFactory :
	public SocketFactory
{
public:
	WinApiSocketFactory();
	std::shared_ptr<ClientSocket> createClientSocket() override;
	std::shared_ptr<ServerSocket> createServerSocket() override;
	std::shared_ptr<ClientSocket> createClientSocket(int af, int type, int protocol) override;
	std::shared_ptr<ServerSocket> createServerSocket(int af, int type, int protocol) override;
	~WinApiSocketFactory();
};

