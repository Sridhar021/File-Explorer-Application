#include "file_operations.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void copyFile(const std::string& src, const std::string& dest) {
	fs::copy(src, dest);
}

void moveFile(const std::string& src, const std::string& dest) {
	fs::rename(src, dest);
	
}

void deleteFile(const std::string& file) {
	fs::remove(file);
	
}

void createFile(const std::string& file) {
        std::ofstream outfile(file);
        outfile.close();

}

