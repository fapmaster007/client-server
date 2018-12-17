#ifndef __XML_STREAM_H__
#define __XML_STREAM_H__
#endif

#include <vector>
#include <fstream>
#include <string>
#include <exception>


class XmlParser
{
	struct Position
	{
		std::size_t start;
		std::size_t end;
	};
	
	std::string buf_;
	std::vector<Position> pos;
	void resetPosition();
	
public:
	explicit XmlParser(const std::string& buf);
	XmlParser& parse(const std::string& nodeName);
	std::vector<std::string> getValues();
	void setValues(const std::vector<std::string>& values);
	XmlParser& insertNode(const std::string& nodeName);
	const std::string& getBuf() const;
};