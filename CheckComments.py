# CheckComments.py
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
import math
from os.path import exists

# there will be 2 arguments from the command line: input and output
# python CheckComments.py inputFileName.cpp outputFileName.txt
if len(sys.argv) != 3:
    sys.exit("Incorrect number of arguments, enter command in this format: \n python CheckComments.py inputFileName.cpp outputFileName.txt")
    
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
proportion = 0.0
numchar = 0
numcommentchar = 0
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
    
def truncate(number, decimals=0):
    """
    Returns a value truncated to a specific number of decimal places.
    """
    if not isinstance(decimals, int):
        raise TypeError("decimal places must be an integer.")
    elif decimals < 0:
        raise ValueError("decimal places has to be 0 or more.")
    elif decimals == 0:
        return math.trunc(number)

    factor = 10.0 ** decimals
    return math.trunc(number * factor) / factor

isblock = False

inline = re.compile(r"//")
startline = re.compile(r"/\*")
endline = re.compile(r"\*/")

# read all the lines in the file, look for single line comments
for line in testfile:
    for char in line: # count the number of characters in the file
        numchar += 1
    linenum += 1
    line = line.strip() # get rid of any leading indents
    if inline.findall(line): # find inline comments
        results.write(str(linenum)  + " | " + line + "\n")
        for char in line: # count the number of characters that are comments
            numcommentchar += 1
        numcomments += 1
        numinline += 1
    if startline.findall(line): # find the beginning of block comments
        areBalanced(line) # put first line into the areBalanced function
        isblock = True
    if endline.findall(line): # find the end of block comments
        if areBalanced(line): # put the last line into the areBalanced function
            numcomments += 1
            numblock += 1
            isblock = False
    if startline.findall(line) or endline.findall(line) or isblock:
        # write the first and last lines, and all lines in between them into the txt file
        results.write(str(linenum) + " | " + line + "\n")
        for char in line:
            numcommentchar += 1

results.write("\n\n------------------------------------\n\n")

results.write("Number of lines: " + str(linenum) + "\n")
results.write("Number of characters: " + str(numchar) + "\n")
results.write("\nNumber of comments: " + str(numcomments) + "\n")
results.write("Number of in-line comments: " + str(numinline) + "\n")
results.write("Number of block comments: " + str(numblock) + "\n")
results.write("Number of characters in comments: " + str(numcommentchar) + "\n")
numcomments = float(numcomments)
linenum = float(linenum)
numchar = float(numchar)
numcommentchar = float(numcommentchar)
proportion = numcomments / linenum * 100 
proportion = truncate(proportion, 2)
propchar = numcommentchar / numchar * 100
propchar = truncate(propchar, 2)
results.write("\nProportion of comments in code (comments lines / total lines): " + str(proportion) + "%\n")
results.write("Proportion of characters in comments (comment characters / total characters): " + str(propchar) + "%")
    
testfile.close()
results.close()

print("Results are ready in " + outputarg)