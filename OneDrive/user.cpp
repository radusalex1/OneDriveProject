#include "user.h"

User::User()
{
	m_ID = 0;
	m_name = "";
	m_surname = "";
	m_email = "";
	m_password = "";
}
User::User(const std::uint8_t& ID, const std::string& name, const std::string& surname, const std::string& email, const std::string& password) : m_ID(ID), m_name(name), m_surname(surname), m_email(email), m_password(password)
{
}

const std::uint8_t& User::Get_ID()
{
	return m_ID;
}
const std::string& User::Get_name()
{
	return m_name;
}
const std::string& User::Get_surname()
{
	return m_surname;
}
const std::string& User::Get_email()
{
	return m_email;
}
const std::string& User::Get_password()
{
	return m_password;
}

void User::Set_ID(std::uint8_t ID)
{
	m_ID = ID;
}
void User::Set_Name(std::string name)
{
	m_name = name;
}
void User::Set_Surname(std::string surname)
{
	m_surname = surname;
}
void User::Set_Email(std::string email)
{
	m_email = email;
}
void User::Set_Password(std::string password)
{
	m_password = password;
}