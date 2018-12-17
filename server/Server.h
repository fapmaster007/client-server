#pragma once
#include <string>
#include <thread>
class Server
{
	std::string addr_;
	int port_;
	size_t buff_size_;
	bool is_run;
	std::string foldername_;
public:
	Server(std::string addr, int port, size_t buff_size, std::string foldername) : addr_(addr), port_(port), 
		buff_size_(buff_size), is_run(false), foldername_(foldername) {}
	void run();
	void stop();
	bool getState() const { return is_run; }
	~Server();
};