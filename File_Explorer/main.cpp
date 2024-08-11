#include "file_operations.h"
#include "directory_operations.h"
#include "search_operations.h"
#include "permission_operations.h"
#include "logger.h"
#include <iostream>
#include <string>
#include <sys/stat.h>


int main() {

	Logger logger("file_explorer.log");
	std::string command;
	std::string currentPath = ".";

	while (true) {

		std::cout<<"> ";
		std::getline(std::cin, command);

		if(command.substr(0, 2)  == "cp") {
			std::string src = command.substr(3, command.find(' ', 3) - 3);
			std::string dest = command.substr(command.find(' ', 3) + 1);
			copyFile(src, dest);
			logger.log(INFO, "Copied file from " + src + " to " + dest);
			
		} else if(command.substr(0, 2)  == "mv") {
                        std::string src = command.substr(3, command.find(' ', 3) - 3);
                        std::string dest = command.substr(command.find(' ', 3) + 1);
                        moveFile(src, dest);
                        logger.log(INFO, "Moved file from " + src + " to " + dest);
                        
                } else if(command.substr(0, 2) == "rm") {
			std::string file = command.substr(3);
			deleteFile(file);
			logger.log(INFO, "Deleted file " + file);
		} else if(command.substr(0, 5) == "touch") {
                        std::string file = command.substr(6);
                        createFile(file);
                        logger.log(INFO, "Created file " + file);
                } else if(command.substr(0, 2) == "cd") {
			std::string newDir = command.substr(3);
                        changeDirectory(currentPath, newDir);
                        logger.log(INFO, "Changed directory to  " + newDir);
                } else if(command.substr(0, 2) == "ls") {
                        listFiles(currentPath);
                        logger.log(INFO, "Listed files in directory " + currentPath);
                } else if(command.substr(0, 6)  == "search") {
                        std::string dir = command.substr(7, command.find(' ', 7) - 7);
                        std::string term = command.substr(command.find(' ', 7) + 1);
                        searchFiles(dir, term);
                        logger.log(INFO, "Searched for term " + term + " in directory " + dir);

                } else if(command.substr(0, 5)  == "chmod") {
                        std::string file = command.substr(6, command.find(' ', 6) - 6);
                        std::string perms = command.substr(command.find(' ', 6) + 1);
                        changePermissions(file, std::stoi(perms));
                        logger.log(INFO, "Changed permissions of " + file + " to " + perms);

                } else if(command == "exit") {
			logger.log(INFO, "Exited the application");
			break;
		} else {
			std::cout<<"Unknown command"<<std::endl;
		}
	}

	return 0;
}

		

