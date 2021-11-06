#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "file.h"
class Folder
{
private:
	std::uint8_t m_ID;
	std::string m_name;
	std::uint8_t m_folder_parent_ID;//this variable takes the id from his parent folder
	std::vector<Folder> m_folder_childs;
	std::vector<File> m_file_childs;
	std::string m_owner;

public:
	Folder();
	Folder(const std::uint8_t& ID, const std::string& name, const std::uint8_t& folder_parent_ID, const std::vector<Folder>& folder_childs, const std::vector<File>& file_childs,const std::string &owner);

	const std::uint8_t& Get_ID();
	const std::string& Get_name();
	const std::uint8_t& Get_folder_parent_ID();
	const std::vector<Folder>& Get_folder_childs();
	const std::vector<File>& Get_file_childs();
	const std::string& Get_owner();

	void Set_ID(std::uint8_t ID);
	void Set_name(std::string name);
	void Set_folder_parent_ID(std::uint8_t folder_parent_ID);
	void Set_folder_childs(std::vector<Folder> folder_childs);
	void Set_file_childs(std::vector<File> file_childs);
	void Set_owner(std::string owner);
};