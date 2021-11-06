#include "file.h"

File::File()
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
}
