## README for Tree section test: width function ##

C. Seshadhri, Feb 2020

*****

### Instructions ###

The folder BST contains a standard implementation of a binary search tree (BST), with a wrapper to run it.
It has many basic functions implemented. Your job is to implement the width function.
You can click on the file tree_qns.pdf for a description of the test functions.

In the BST directory, you will see the following files.
Makefile, bst.cpp, bst.h, treewrapper.cpp 

The file bst.h already has a declaration for your function, and bst.cpp has a place for the implementation.
(Look at the very end of bst.cpp.)
You are free to define other helper functions, if you need. (Just remember to declare any BST functions in the header file.)

IMPORTANT: only modify bst.cpp and bst.h. Do not change the other files. It might affect the grading system.

USAGE (in BST folder):
1) Run "make", to get executable "treewrapper".
2) Run "./treewrapper <INPUT FILE> <OUTPUT FILE>"
   
   Run "make clean" to delete executable and object files. A good practice to do this after changing code.


Later in the README, you can see how the input (in <INPUT FILE>) should be structured.

----------------------------------------------------

### Input/output ###

The following explains the input/output format.

I/O:

The input file should have a series of operations in each line. Each line is of the form:

i <INT>: insert <INT> into BST
f <INT>: find if <INT> is in BST
d <INT>: delete <INT> from BST
w: print the width of the BST
pin: print tree in order
ppre: print tree pre-order
ppost: print tree post-order

The output file has output corresponding to the following operations:

find: output file has "found/didn't find <INT>"
width: output file has the width
print operations: output file has tree printed in corresponding order

Each such operation leads a new line of printing.
All the printing is done in the <OUTPUT FILE> provided as a command line argument. 

Additionally, every command processed is printed to the console. 

----------------------------------------------------
