#pragma once
#include <iostream>
#include <string>

class User
{
private:
	std::uint8_t ID;
	std::string name;
	std::string surname;
	std::string email;
	std::string password;
	
public:
	User();
	User(const std::uint8_t& ID, const std::string& name, const std::string& surname, const std::string& email, const std::string& password);
};