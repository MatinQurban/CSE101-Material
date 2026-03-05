## README for BinHeap section test: extractMax function ##

C. Seshadhri, Feb 2020 -Niloofar M. Oct2025

*****

### Instructions ###

The folder BinHeap contains a standard implementation of a binary maxheap, with a wrapper to run it.
Your job is to implement the extractMax function. You can click on the file binheap_qns.pdf for a description of the function.

In the BinHeap directory, you will see the following files.
Makefile, binheap.cpp, binheap.h, heapwrapper.cpp, simple-input.txt, simple-output.txt 

The file binheap.h already has a header declaration for your function. You are provided a place in binheap.cpp to write up your implementation.
You are free to declare and implement other functions, if you feel the need. (Make sure declare in the header file, to ensure compilation.)

IMPORTANT: only modify binheap.h and binheap.cpp. Do not change any other files. It might affect the grading system. 

USAGE (in BinHeap older):
1) Run "make", to get executable "heapwrapper".
2) Run "./heapwrapper <INPUT FILE> <OUTPUT FILE>"
   
   Run "make clean" to delete executable and object files. A good practice to do this after changing code.


Later in the README, you can see how the input (in <INPUT FILE>) is structured.

The files simple-input.txt, simple-output.txt are example input and output files. In a correct code, the output should exactly match this output.
These files will help you test and debug your code.

#### How to test (and grade) you code

Open a fresh terminal, which will put you in the directory ~/workspace. Keep this terminal open.

Run "./autograde.sh".

This will run a grading script, which will generate a lot of output in the console. The final line will be your score.
Your score will be something from 0 to 100 (full) points, depending on how many test cases you pass.
If your code does not get simple-input.txt correct, you do not get any points.

After running this script, there will be file BinHeap.log in the directory BinHeap.
Open this file in any text editor, and it will be give you some explanation of where your code failed.

----------------------------------------------------

### Input/output ###

The following explains the input/output format.

I/O:

The input file should have a series of operations in each line. Each line is of the form:

i <INT>: insert <INT> into heap
max: print maximum in heap
em: extract (delete) maximum from heap
p: print heap, as an array in order

All the printing is done in the <OUTPUT FILE> provided as a command line argument. Only the print
command leads to any printing in the output file.

Additionally, every command processed is printed to the console. Every printing is also done in the console.

A student need not read any further. The explanation below is for instructors of the course.

----------------------------------------------------

### How the grading works

The script autograde.sh is basically calling RoboGrader with right setting. 
There is another script, grading_script.sh in the secure folder (so students cannot access it) that runs an identical
copy of the script, and sends the score to the Codio system.
