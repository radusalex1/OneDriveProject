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

const std::uint8_t& Folder::Get_ID()
{
	return m_ID;
}

const std::string& Folder::Get_name()
{
	return m_name;
}

const std::uint8_t& Folder::Get_folder_parent_ID()
{
	return m_folder_parent_ID;
}

const std::vector<Folder>& Folder::Get_folder_childs()
{
	return m_folder_childs;
}

const std::vector<File>& Folder::Get_file_childs()
{
	return m_file_childs;
}

const std::string& Folder::Get_owner()
{
	return m_owner;
}

void Folder::Set_ID(std::uint8_t ID)
{
	m_ID = ID;
}

void Folder::Set_name(std::string name)
{
	m_name = name;
}

void Folder::Set_folder_parent_ID(std::uint8_t folder_parent_ID)
{
	m_folder_parent_ID = folder_parent_ID;
}

void Folder::Set_folder_childs(std::vector<Folder> folder_childs)
{
	m_folder_childs = folder_childs;
}

void Folder::Set_file_childs(std::vector<File> file_childs)
{
	m_file_childs=file_childs;
}

void Folder::Set_owner(std::string owner)
{
	m_owner = owner;
}

bool Folder::check_file_presence(File file)
{
	for (int index = 0; index < m_file_childs.size(); ++index)
	{
		if (file.Get_name() == m_file_childs[index].Get_name())
		{
			return true;
		}
	}
	return false;
}

bool Folder::check_folder_presence(Folder folder)
{
	for (int index = 0; index < m_file_childs.size(); ++index)
	{
		if (folder.Get_name() == m_folder_childs[index].Get_name())
		{
			return true;
		}
	}
	return false;
}

void Folder::check_file_names_duplicates()
{
	for (int index = 0; index < m_file_childs.size()-1; index++)
	{
		for (int index2 = 1; index2 < m_file_childs.size(); index++)
			if (m_file_childs[index].Get_name() == m_file_childs[index2].Get_name())
				std::cout << "There are two ore more files with the same name!";
	}
	
}

void Folder::check_folder_names_duplicates()
{
	for (int index = 0; index < m_folder_childs.size() - 1; index++)
	{
		for (int index2 = 1; index2 < m_folder_childs.size(); index++)
			if (m_folder_childs[index].Get_name() == m_folder_childs[index2].Get_name())
				std::cout << "There are two ore more folders with the same name!";
	}
}
