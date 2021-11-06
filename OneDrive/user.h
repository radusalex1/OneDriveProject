#pragma once
#include <iostream>
#include <string>

class User
{
private:
	std::uint8_t m_ID;
	std::string m_name;
	std::string m_surname;
	std::string m_email;
	std::string m_password;
	
public:
	User();
	User(const std::uint8_t& ID, const std::string& name, const std::string& surname, const std::string& email, const std::string& password);

	const std::uint8_t& Get_ID();
	const std::string& Get_name();
	const std::string& Get_surname();
	const std::string& Get_email();
	const std::string& Get_password();

	void Set_ID(std::uint8_t ID);
	void Set_Name(std::string name);
	void Set_Surname(std::string surname);
	void Set_Email(std::string email);
	void Set_Password(std::string password);
};