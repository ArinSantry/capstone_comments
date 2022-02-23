# capstone_comments
Part of the C++ Autograder capstone - this file parses through a .cpp file's comments and writes them into a .txt

 comments.py
 Arin Santry
 Capstone group: S.W.A.T
   Arin Santry, Stacey Walters, Tylar Dazey, Wyatt Guethlein

 This program will read an inputted C++ code file and parse out the comments
 count the number of comments
 count the number of characters in comments
 count total number of lines and total number of characters
 proportion of comments (number comments / number lines)
 proportion of comment characters (comment characters / total characters)
 write comments and their line numbers into a specified output text file
 the input file to be tested must be in the same folder as this program, or the path must be specified in the command line argument

How to run:
In the command line/shell, navigate to the folder containing comments.py. Make sure that there is a .cpp file that you want to parse.
Command: python command.py inputFilePath outputFilePath
Output file will be created if it does not already exist. If you want to override a file, use that path as the output.

Output file format:
    
---

(line number) | (line with comment)

...

Number of lines: x
Number of characters: y

Number of comments: a+b
Number of in-line comments: a
Number of block comments: b
Number of characters in comments: c

Proportion of comments in code (comments lines / total lines): (a+b)/x
Proportion of characters in comments (comment characters / total characters): c/y
