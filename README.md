**Console-Based File Explorer**

This project is a console-based file explorer application developed in C++ that interfaces with the Linux operating system to manage files and directories. It provides a command-line interface to perform common file operations such as listing, creating, deleting, and navigating through directories.

**Table of Contents**
- Introduction
- Installation
- Usage
- Contributing
- Contact

**Introduction**

The Console-Based File Explorer allows users to manage files and directories from the command line. It supports basic file operations and is designed to interact directly with the Linux filesystem. This tool is useful for users who prefer or require a terminal-based interface for file management.

**Installation**

To set up the file explorer application, follow these steps:

**1. Clone the repository:**
    git clone https://github.com/Sridhar021/file-explorer.git

**2.Navigate to the project directory:**
    cd file-explorer
    
**3.Compile the application:**
    g++ -o file_explorer main.cpp

**Usage**
To run the file explorer application, use the following command:
./file_explorer
**Available Commands**
List Files:
./file_explorer ls

Change Directory:
./file_explorer cd <directory>

Create File:
./file_explorer touch <filename>

Delete File:
./file_explorer rm <filename>

Create Directory:
./file_explorer mkdir <directory>

Delete Directory:
./file_explorer rmdir <directory>

For detailed usage instructions, refer to the documentation provided within the application or consult the help command:
./file_explorer --help

**Contributing**
We welcome contributions to enhance the file explorer application. To contribute:
 Fork the repository.
 Create a new branch (git checkout -b feature-branch).
 Implement your changes and commit them (git commit -am 'Add new feature').
 Push the changes to your branch (git push origin feature-branch).
 Submit a Pull Request.
**Contacts**

Sridhar
Project Link: https://github.com/Sridhar021/file-explorer
