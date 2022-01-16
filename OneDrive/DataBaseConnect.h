#pragma once
#include <pqxx/pqxx>
class DataBaseConnect
{
public:
	DataBaseConnect();
	bool isUser(const std::string &username, const std::string &password);
	void newUSerRegisterCredentials(const std::string &username, const std::string &password, const std::string &path);
	std::string GetUserPath(const std::string &);
};

