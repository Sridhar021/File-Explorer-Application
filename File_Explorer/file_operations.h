#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>

void copyFile(const std::string &src, const std::string &dest);
void moveFile(const std::string &src, const std::string &dest);
void deleteFile(const std::string &path);
void createFile(const std::string &path);

#endif // FILE_OPERATIONS_H
