#include "file_operations.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;


//function to copy file
void copyFile(const std::string& src, const std::string& dest) {
	fs::copy(src, dest);
	std::cout<<"File copied"<<std::endl;
}

//function to move file
void moveFile(const std::string& src, const std::string& dest) {
	fs::rename(src, dest);
	std::cout<<"File moved"<<std::endl;
	
}

//function to delete file
void deleteFile(const std::string& file) {
	fs::remove(file);
	std::cout<<"File deleted"<<std::endl;
	
}

//function to create file
void createFile(const std::string& file) {
        std::ofstream outfile(file);
	std::cout<<"File created"<<std::endl;
        outfile.close();

}

