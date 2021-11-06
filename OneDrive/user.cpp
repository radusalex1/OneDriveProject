#include "user.h"

User::User()
{
	ID = 0;
	name = "";
	surname = "";
	email = "";
	password = "";
}

User::User(const std::uint8_t& ID, const std::string& name, const std::string& surname, const std::string& email, const std::string& password) : ID(ID), name(name), surname(surname), email(email), password(password)
{
}