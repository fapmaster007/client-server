#include "stdafx.h"
#include "Server.h"
#include <thread>
#include <iostream>

int main()
{
	Server s("127.0.0.1", 80, 4094, "server1");
	s.run();
	if (!s.getState())
	{
		system("pause");
		return 1;
	}
	std::string state;
	std::cout << "Server is running. Press 's' for terminate\n";
	for (;;)
	{
		std::cin >> state;
		if (state == "s")
		{
			s.stop();
			std::cout << "Server stopping...\n";
			break;
		}
	}
	system("pause");
	return 0;
}