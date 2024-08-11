#include <iostream>
#include <cassert>
#include <filesystem>
#include <fstream>
#include "file_operations.h"
#include "directory_operations.h"
#include "search_operations.h"
#include "permission_operations.h"

namespace fs = std::filesystem;

void test_file_creation() {
	std::string testFile = "test_dir/test_file.txt";
	createFile(testFile);
	assert(fs::exists(testFile) && "File creation failed");
}

void test_file_copy() {
        std::string srcFile = "test_dir/test_file.txt";
	std::string destFile = "test_dir/test_file_copy.txt";
        copyFile(srcFile, destFile);
        assert(fs::exists(destFile) && "File copy failed");
}

void test_file_move() {
        std::string srcFile = "test_dir/test_file_copy.txt";
        std::string destFile = "test_dir/test_file_moved.txt";
        moveFile(srcFile, destFile);
        assert(fs::exists(destFile) && !fs::exists(srcFile) && "File move failed");
}

void test_file_delete() {
        std::string testFile = "test_dir/test_file_moved.txt";
        deleteFile(testFile);
        assert(!fs::exists(testFile) && "File deletion failed");
}

void test_directory_listing() {
	std::string testDir = "test_dir";
	std::ofstream outfile(testDir + "/file1.txt");
	outfile.close();
	outfile.open(testDir + "/file2.txt");
	outfile.close();

	//capture output of listfiles
	std::cout<<"Listing files in directory:"<<std::endl;
	listFiles(testDir);

}



void test_file_search() {
	std::string testDir = "test_dir";
	std::ofstream outfile(testDir + "/search_file.txt");
	outfile.close();

	//capture output of searchFiles
	std::cout<<"Searching for 'search_file.txt' in directory:"<<std::endl;
	searchFiles(testDir, "search_file");

}

void test_permission_change() {

	std::string testFile = "test_dir/search_file.txt";
	changePermissions(testFile, 0644);

	fs::perms p = fs::status(testFile).permissions();

        assert((p & fs::perms::owner_read) != fs::perms::none && "Owner read permission should be set");
	assert((p & fs::perms::owner_write) != fs::perms::none && "Owner write permission should be set");
	assert((p & fs::perms::owner_exec) == fs::perms::none && "Owner execute permission should not be set");


	assert((p & fs::perms::group_read) != fs::perms::none && "Group read permission should be set");
	assert((p & fs::perms::group_write) == fs::perms::none && "Group write permission should not be set");
	assert((p & fs::perms::group_exec) == fs::perms::none && "Group execute permission should not be set");


	assert((p & fs::perms::others_read) != fs::perms::none && "Others read permission should be set");
	assert((p & fs::perms::others_write) == fs::perms::none && "Others write permission should not be set");
	assert((p & fs::perms::others_exec) == fs::perms::none && "Others exec permission should not be set");
}

int main() {

	std::string testDir = "test_dir";

	//create test directory
	if(!fs::exists(testDir)) {
		fs::create_directory(testDir);
	}

	//run test cases
	test_file_creation();
	test_file_copy();
	test_file_move();
	test_file_delete();
	test_directory_listing();
	
	test_file_search();
	test_permission_change();

	//clean up
	fs::remove_all(testDir);

	std::cout<<"All tests passed"<<std::endl;

	return 0;
}



