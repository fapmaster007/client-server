#include "stdafx.h"
#include <iostream>
#include "Client.h"

int main()
{
	Client c("127.0.0.1", 80);
	std::string filename;
	for(;;)
	{
		std::cout << "Press 'q' to exit. Filename to send: ";
		std::cin >> filename;
		if (filename == "q")
			break;
		try
		{
			c.connect();
			c.send(filename);
		}
		catch(...)
		{ }
	}
	system("pause");
	return 0;
}