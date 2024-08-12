# Bug Report Tracker

**1.Bug Report**

Title: changeDirectory Function Does Not Correctly Handle Relative Paths (e.g., "..")
Reported By: Sridhar, Sri Mounika
Date: August 10, 2024
Severity: Medium
Priority: High
Status: Open

**Description**:

The changeDirectory function is designed to change the current working directory of the application. However, it does not correctly handle relative paths such as "..", which is intended to move up to the parent directory. The function only sets the directory to the specified path without checking if it's a valid relative path.

**Steps to Reproduce:**

Start in a directory with at least one parent directory.
Execute the changeDirectory function with ".." as the argument.
After changing the directory, attempt to list the files using the listFiles function.
Observe that the directory is not correctly set to the parent directory, or an error occurs.

**Expected Behavior:**

The function should correctly interpret ".." and navigate to the parent directory of the current path.

**Actual Behavior:**

The function either fails to change the directory or incorrectly interprets the ".." input, resulting in no directory change or an incorrect directory.

**Impact:**

Users are unable to navigate to parent directories using relative paths like "..", which is a standard operation in file systems.

**Possible Solution:**

Modify the changeDirectory function to check if the input path is a relative path (e.g., "..", "."), and handle these cases appropriately using std::filesystem::current_path().parent_path() for ".." or std::filesystem::current_path() for ".".

**Resolution:**

Resolution Date: August 11,2024
Resolved By: Sridhar,Srimounika
Resolution Description: Change the code to fix error

**2.Bug Report**

Title: Incorrect Application of Permissions in changePermissions Function
Reported By: Sridhar, Sri Mounika
Date: August 10, 2024
Severity: Medium
Priority: High
Status: Open

**Description:**

The changePermissions function is designed to modify the permissions of a file or directory based on an integer input representing the permission bits. However, the function does not correctly handle the scenario where existing permissions should be preserved. It may override existing permissions when only certain bits are provided.

**Steps to Reproduce:**

Create a file named example.txt with initial permissions set to 0644 (rw-r--r--).
Call the changePermissions function with the following input: changePermissions("example.txt", 0700);.
Observe that the permissions are set to 0700 (rwx------), overriding the original group and others permissions.

**Expected Behavior:**

The function should modify only the specified permission bits without overriding unspecified bits.
For example, if 0700 is provided, the function should only modify the owner’s permissions while preserving group and others' permissions.

**Actual Behavior:**

The function sets the permissions to 0700, removing all permissions for the group and others.

**Impact:**

This behavior could lead to unintended file access restrictions, potentially causing issues in multi-user environments.

**Possible Solution:**

Modify the function to first read the existing permissions of the file, then apply the new permissions selectively, preserving any unspecified permissions.

**Resolution:**

Resolution Date: August 11,2024
Resolved By: Sridhar,Srimounika
Resolution Description: modify the code to overcome error

**3.Bug Report**

Title: changeDirectory Function Incorrectly Handles ".." for Changing to Parent Directory
Reported By: Sridhar, Sri Mounika
Date: August 10, 2024
Severity: Medium
Priority: High
Status: Open

**Solution:**

The issue was fixed by updating the changeDirectory function to properly handle relative paths, including "..". The updated function now correctly interprets ".." and changes to the parent directory as intended.

**Resolution:**

Resolution Date: August 11,2024
Resolved By: Sridhar


**4.Bug Report**

Title: SearchFile does not work recursively
Reported By: Sridhar, Sri Mounika
Date Reported: August 10, 2024
Severity: Medium
Priority: High
Status: Open

**Description:**

The SearchFile function in the file explorer application is failing to search for files recursively within subdirectories. The function only searches within the current directory and does not traverse into subdirectories as expected.

**Steps to Reproduce:**

Launch the file explorer application.
Use the SearchFile function to search for a file name within a directory that contains subdirectories.
Observe that the search does not find files located in subdirectories.

**Expected Result:**

The SearchFile function should recursively search through all subdirectories within the specified directory and return all instances of the file matching the search criteria.

**Actual Result:**

The SearchFile function only searches in the top-level directory and does not descend into subdirectories. Files located within subdirectories are not found.

**Possible Solution:**

Modify the function to first read the existing permissions of the file, then apply the new permissions selectively, preserving any unspecified permissions.

**Resolution:**

Resolution Date: August 11,2024
Resolved By: Sridhar

