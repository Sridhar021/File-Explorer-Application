#include "search_operations.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void searchFiles(const std::string& path, const std::string& searchTerm) {
        for(const auto& entry : fs::recursive_directory_iterator(path)) {
                if(entry.path().filename().string().find(searchTerm) != std::string::npos) {
                        std::cout<<entry.path().string()<<std::endl;
                }
        }
}


