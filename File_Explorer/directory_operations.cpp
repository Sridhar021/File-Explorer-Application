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
	currentPath = newDir;
        fs::current_path(currentPath);
        std::cout<<"Change directory to "<<currentPath<<std::endl;
}


