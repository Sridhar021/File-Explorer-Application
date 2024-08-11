**File Explorer Application**

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

**1.Clone the repository:**
    git clone https://github.com/Sridhar021/file-explorer.git

**2.Navigate to the project directory:**
    cd file-explorer
    
**3.Compile the application:**
    We have a Makefile for the project so to compile we can use the Makefile.
    Run makefile using command:
    make

**Usage**
To run the file explorer application, use the following command:
./file_explorer

**Available Commands**
List Files:

ls

Change Directory:

cd directory

Create File:

touch filename

Delete File:

rm filename

Copy File:

cp sourcefile destinationfile

Move or Rename File:

mv sourcefile destinationfile

Search File:

search searchTerm

Change File Permission:

chmod filename mode

**Logger**

We have used a logger for logging the code output to the logger file so that we can know how the code functions and what functions are being performed.
We have used logger for INFO, DEBUG, WARNING.
When we run the code and perform commands the output will be recorded in the logfile with the date and time of the command executed with what action it performs.
We can check the logs in file_explorer.log file.


**Contributing**

We welcome contributions to enhance the file explorer application. To contribute:
 Fork the repository.
 Create a new branch (git checkout -b feature-branch).
 Implement your changes and commit them (git commit -am 'Add new feature').
 Push the changes to your branch (git push origin feature-branch).
 Submit a Pull Request.

**Contacts**

Sridhar
Project Link: https://github.com/Sridhar021/File-Explorer-Application
