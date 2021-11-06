#include "folder.h"

Folder::Folder()
{
	m_ID = 0;
	m_name = "";
	m_folder_parent_ID=0;
	m_folder_childs.clear();
	m_file_childs.clear();
	m_owner = "";
}

Folder::Folder(const std::uint8_t& ID, const std::string& name, const std::uint8_t& folder_parent_ID, const std::vector<Folder>& folder_childs, const std::vector<File>& file_childs, const std::string& owner)
	:m_ID(ID),m_name(name), m_folder_parent_ID(folder_parent_ID),m_folder_childs(folder_childs),m_file_childs(file_childs),m_owner(owner)
{
}
