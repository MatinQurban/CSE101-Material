## README for Stack Recursion section test: allAnagrams question ##

C. Seshadhri, Jan 2020, Oct 2020, Niloofar Montazeri Oct 2025

*****

### Instructions ###


You can click on the file stackrecursion_qns.pdf for a description of the function.

The folder StackRecursion contains the setup for your code. The main code files are:

1) list.cpp, list.h, node.cpp, node.h: These are linked list codes (similar to the first test) that provide basic functionality for an object type List.
2) stackrecursion.cpp: This file has "main", where all the I/O happens and your function is called. Your function declaration is already provided, and you only need to write your implementation in the provided place.

You are free to declare and implement other functions, if you feel the need. You **can NOT use recursion**, and must write a stack based implementation. You can use the inbuilt stack that C++ provides. You can use any data structures you want, **but the output must be in the List provided in the code**.

**IMPORTANT: only modify stackrecursion.cpp** files. While you can modify the linkedlist files, it's not a good idea.  (There is no need to.) Do not change any other files. It might affect the grading system. 

#### How to run your code ####

USAGE (in LinkedList older):
1) Run "make", to get executable "stackrecursion".
2) Run "./stackrecursion <INPUT FILE> <OUTPUT FILE>"
    
    Run "make clean" to delete executable and object files. A good practice to do this after changing code.

The "main" function in stackrecursion.cpp has the setup for I/O, and you do not need to modify it. It will take care of reading and writing to the input/output files.  Later in the README, you can see how the input (in <INPUT FILE>) and output (in <OUTPUT FILE>) is structured.

The files simple-input.txt, simple-output.txt are example input and output files. In a correct code, the output should exactly match this output. These files will help you test and debug your code. These files are also provided in the Test/ subdirectory, in case you delete these files.

#### How to test (and grade) your code

Open a fresh terminal, which will put you in the directory ~/workspace. Keep this terminal open.

Run "./autograde.sh".

This will run a grading script, which will generate a lot of output in the console. The final line will be your score. Your score will either be 0, 50, or 100 (full) points, depending on how many test cases you pass. **If your code does not get simple-input.txt correct, you do not get any points.**

**Log file:** After running this script, there will be file StackRecursion.log in the directory StackRecursion. Open this file in any text editor, and **it will be give you some explanation of where your code failed**.

The StackRecursion folder will contain some files called "*input.txt" (where * is the standard Unix wildcard, not the asterisk symbol).
Your code is generating the incorrect output on one of these files. The log file should also tell you which line is generating the wrong output.
The script will generate some other files as well that store your output for those inputs. These might help you see where the error is. 

You can submit your code, by going to Education tab and click on "Mark as Completed". The score you get is what the grading script above returned.
(So you know exactly what you got.)

#### How to reset, if something gets screwed up

In the workspace folder, run "./reset.sh"
**This will delete the existing StackRecursion/ folder, and repopulate the files. This will reset everything to as it was before you started coding.**


----------------------------------------------------

### Input/output ###

The following explains the input/output format.

I/O:

For the anagram question: the first line of the input file is read into a string, which is sent to the allAnagrams function. 
For the language and stretch questions: the first line of the input file is read into a string and the second line is read into an int.
Both of these are passed to the language/stretch functions.

All other lines are ignored. Note that main calls the function (allAnagrams, language, or stretch) exactly once on the input string.

The output list is then sorted lexicographically, and then printed out to <OUTPUT FILE>. Each string in the list is printed on a separate line. Note that the empty string may also be printed out (depending on the problem), leading to a blank line.

Feel free to generate your own test input files in the above format, and generate output in your own output files.

A student need not read any further. The explanation below is for instructors of the course.

----------------------------------------------------

### Some useful string functions ###

Given a string str, here are some (C++ string) functions that you may find useful.
You can use any string functions you want, even if they are not listed here.

`str.length()`: This returns the length of the string as an int.
`str.at(i)`: For index (int) i, this returns the character at the ith index in the string.
`str.erase(i,1)`: For index (int) i, this deletes the ith character in the string.
(In general, str.erase(i,k) deletes k characters from str, starting from the ith character.)

----------------------------------------------------

### How the grading works

The script autograde.sh is basically calling RoboGrader with right setting. 
There is another script, grading_script.sh in the secure folder (so students cannot access it) that runs an identical copy of the script, and sends the score to the Codio system.
