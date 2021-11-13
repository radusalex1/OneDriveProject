#pragma once
#include <pqxx/pqxx>
class DataBaseConnect
{
public:
	DataBaseConnect();
	bool isUser(std::string username,std::string password);
};

