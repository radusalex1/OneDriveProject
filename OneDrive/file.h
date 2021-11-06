#pragma once
#include <iostream>
#include <string>

class File
{
private:
	std::uint8_t m_ID;
	std::string m_name;
	uint32_t m_size;//size is represented in kb
	std::uint8_t m_folder_parent_ID;//this variable takes the id from his parent folder
	std::string m_owner;

public:
	File();
	File(const std::uint8_t& ID, const std::string& name, const std::uint32_t& size, const std::uint8_t& folder_parent_ID, const std::string& owner);
};