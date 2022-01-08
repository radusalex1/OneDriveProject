#include "file.h"

File::File()
	:m_ID(0), m_name(""), m_size(0), m_folder_parent_ID(0), m_owner("")
{
	m_ID = 0;
	m_name = "";
	m_size = 0;
	m_folder_parent_ID = 0;
	m_owner = "";
}

File::File(const std::uint8_t& ID, const std::string& name, const std::uint32_t& size, const std::uint8_t& folder_parent_ID, const std::string& owner)
	:m_ID(ID),m_name(name),m_size(size),m_folder_parent_ID(folder_parent_ID),m_owner(owner)
{
	m_ID = ID;
	m_name = name;
	m_size = size;
	m_folder_parent_ID =folder_parent_ID;
	m_owner = owner;
}

const std::uint8_t& File::Get_ID()
{
	return m_ID;
}

const std::string& File::Get_name()
{
	return m_name;
}

const std::uint32_t& File::Get_size()
{
	return m_size;
}

const std::uint8_t& File::Get_folder_parent_ID()
{
	return m_folder_parent_ID;
}

const std::string& File::Get_owner()
{
	return m_owner;
}

void File::Set_ID(std::uint8_t ID)
{
	m_ID = ID;
}

void File::Set_name(std::string name)
{
	m_name = name;
}

void File::Set_size(std::uint32_t size)
{
	m_size = size;
}

void File::Set_folder_parent_ID(std::uint8_t folder_parent_ID)
{
	m_folder_parent_ID = folder_parent_ID;
}

void File::Set_owner(std::string owner)
{
	m_owner = owner;
}
