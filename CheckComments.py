# comments.py
# Arin Santry
# Capstone group: S.W.A.T
#   Arin Santry, Stacey Walters, Tylar Dazey, Wyatt Guethlein

# This program will read an inputted C++ code file and parse out the comments
# count the number of comments
# proportion of comments (number comments/number lines)
# write comments and their line numbers into a specified output text file
# the input file to be tested must be in the same folder as this program, or the path must be specified in the command line argument

import re
import string
import sys
from os.path import exists

# there will be 2 arguments from the command line: input and output
# python comments.py inputFileName.cpp outputFileName.txt
if len(sys.argv) != 3:
    sys.exit("Incorrect number of arguments, enter command in this format: \n python comments.py inputFileName.cpp outputFileName.txt")
    
# use regex to make sure that the arguments are of the correct file type
cpp = re.compile(r".cpp$")
txt = re.compile(r".txt$")

inputarg = sys.argv[1]
outputarg = sys.argv[2]

if not cpp.findall(inputarg):
    sys.exit("Error: input file must be a .cpp")
if not txt.findall(outputarg):
    sys.exit("Error: output file must be a .txt")
    
inputexists = exists(inputarg)

if not inputexists:
    sys.exit("Error: Input file " + inputarg + " does not exist")

# as a double-check for the user
print("\ninput file: " + inputarg)
print("\noutput file: " + outputarg)

# will change hard-coded file name to an input argument (command line)
testfile = open(inputarg, "r")
results = open(outputarg, "w")

# write header to results file
results.write("\t\t COMMENTS \n\n")
results.write("------------------------------------\n\n")

# initialize all the things!
linenum = 0
numcomments = 0
numinline = 0
numblock = 0
multilineStack = [] # imitating a stack using a list

# taking this from the old "balanced pair" assignment from DSA2
def arePair(opening, closing):
    if opening == "/*" and closing == "*/":
        return True

def areBalanced(string):
    openComment = re.compile(r"/\*")
    closeComment = re.compile(r"\*/") # stupid special characters making things look gross
    if openComment.findall(string):
        multilineStack.append("/*")
    elif closeComment.findall(string):
        if len(multilineStack) == 0 or not arePair(multilineStack[-1], "*/"):
            return False
        else:
            multilineStack.pop()
    if len(multilineStack) == 0:
        return True
    else:
        return False

# read all the lines in the file, look for single line comments
for line in testfile:
    linenum += 1
    lineCopy = line
    line = line.strip() # get rid of any leading indents
    inline = re.compile(r"//")
    startline = re.compile(r"/\*")
    midline = re.compile(r"^\*")
    endline = re.compile(r"\*/")
    if inline.findall(line):
        results.write(str(linenum)  + " | " + line + "\n")
        numcomments += 1
        numinline += 1
    if startline.findall(line) or endline.findall(line):
        if areBalanced(line):
            numcomments += 1
            numblock += 1
    if startline.findall(line) or midline.findall(line) or endline.findall(line):
        results.write(str(linenum) + " | " + line + "\n")


results.write("\nNumber of comments: " + str(numcomments) + "\n")
results.write("Number of in-line comments: " + str(numinline) + "\n")
results.write("Number of block comments: " + str(numblock) + "\n")
proportion = numcomments / linenum * 100 # percentage
results.write("Proportion of comments in code: " + str(proportion) + "%")
    
testfile.close()
results.close()