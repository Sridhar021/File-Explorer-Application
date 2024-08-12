#include "directory_operations.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void listFiles(const std::string& path) {
	for(const auto &entry : fs::directory_iterator(path)) {
                std::cout<<entry.path().filename().string()<<std::endl;
        }
	
}

void changeDirectory(std::string& currentPath, const std::string& newDir) {
	if(newDir == "..") {
		fs::path parentPath = fs::current_path().parent_path();
        	fs::current_path(parentPath);
        	currentPath = parentPath.string();
	} else {
		fs::current_path(newDir);
		currentPath = fs::current_path().string();
	}

	std::cout<<"Change directory to "<<currentPath<<std::endl;
}


