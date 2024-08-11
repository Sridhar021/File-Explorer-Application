#ifndef DIRECTORY_OPERATIONS_H
#define DIRECTORY_OPERATIONS_H

#include <string>

void listFiles(const std::string &path);
void changeDirectory(std::string &currentPath, const std::string &newDir);

#endif // DIRECTORY_OPERATIONS_H

