This project is made for finding the most efficient data structure and 
searching algorithm for directory managing system.


There are 5 commands to managing directories


# == initialization == #
function format : void init()
spec : 
1. This function erase all existing directories and 
   leave only root directory that the name is "/", if there exist some directories.
2. Current directory is set as "/" 


# == make new directory == #
function format : void mkdir(char keyword[])
spec :
1. The keyword's max length is 13 including '\0'
2. Make a new directory that has the keyword as name in Current directory
3. If there is a directory that has same name with keyword, this command do nothing 


# == remove directories == #
function format : int rmdir(char keyword[])
spec : 
1. The keyword's max length is 13 including '\0'
2. the format of keyword is "string" + "*"  
3. String can be empty
4. Remove all directories that have same string in keyword before "*" and their descendants
5. Return the number of removed directories


# == change directory == #
function format : void cd(char keyword[])
spec :
1. The keyword's max length is 13 including '\0'
2. The format of keyword is "string" + "\t"
3. String can be empty
4. Change current directory to the directory that has same keyword with "string"
5. If there are several directories that hae same keyword with "string", 
   the prior directory is selected
6. Dictionary order is used as base for priority


# == find directories == #
function format : int find(char keyword[])
spec :
1. The keyword's max length is 13 including '\0'
2. The format of keyword is "string" + "*"
3. String can be empty
4. Find all directories that have same string in keyword before "*" in current directory and all descendants of directories in current directory
5. Return the number of removed directories



