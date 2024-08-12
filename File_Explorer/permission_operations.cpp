#include "permission_operations.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

//function to change permission of file
void changePermissions(const std::string& path, int  permissions) {
        fs::perms perms = static_cast<fs::perms>(0);

	if(permissions & 0400) perms |= fs::perms::owner_read;
	if(permissions & 0200) perms |= fs::perms::owner_write;
	if(permissions & 0100) perms |= fs::perms::owner_exec;


	if(permissions & 0040) perms |= fs::perms::group_read;
	if(permissions & 0020) perms |= fs::perms::group_write;
	if(permissions & 0010) perms |= fs::perms::group_exec;


	if(permissions & 0004) perms |= fs::perms::others_read;
	if(permissions & 0002) perms |= fs::perms::others_write;
	if(permissions & 0001) perms |= fs::perms::others_exec;

	fs::permissions(path, perms);

	std::cout<<"Permissions of "<<path<<" changed to "<<permissions<<std::endl;

}


