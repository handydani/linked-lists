========================================================================
    PROBLEM DESCRIPTION : pa2.cpp
========================================================================

Write the C++ programs that emulate the operating system’s responsibility of allocating memory to certain programs. This will be a very
simple page-based view of memory management. On startup, your program will have some 32 pages of contiguous, unused memory. Each page will
be 4 KB long. 

It should then allow the users (i.e., your TAs) to “run” programs that require chunks of this memory for some period of time. It should
also allow the users to “kill” programs (i.e., “Ctrl-c” or “kill -9” in most OSs) that are in progress. The pages used by programs that are
killed can then be re-used for future programs. 

The purpose of this project is two-fold. First, you need to get practice with linked lists and pointers. Secondly, you should examine 
critically the results of different algorithms of allocating memory on the “fragmentation” of the memory

/////////////////////////////////////////////////////////////////////////////
