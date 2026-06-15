#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <crtdbg.h>
#endif

void mayThrow(bool doThrow) {
    int* data = new int[100];
    if (doThrow)
        throw std::runtime_error("Boom!");
    delete[] data; // Only called if no exception
}

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    try {
        mayThrow(true);  // This leaks
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ g++ -g -o T14 Task14.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T14
// ==1639== Memcheck, a memory error detector
// ==1639== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==1639== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==1639== Command: ./T14
// ==1639== 
// Caught exception: Boom!
// ==1639== 
// ==1639== HEAP SUMMARY:
// ==1639==     in use at exit: 400 bytes in 1 blocks
// ==1639==   total heap usage: 5 allocs, 4 frees, 75,326 bytes allocated
// ==1639== 
// ==1639== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
// ==1639==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==1639==    by 0x40012A6: mayThrow(bool) (Task14.cpp:8)
// ==1639==    by 0x400133B: main (Task14.cpp:19)
// ==1639== 
// ==1639== LEAK SUMMARY:
// ==1639==    definitely lost: 400 bytes in 1 blocks
// ==1639==    indirectly lost: 0 bytes in 0 blocks
// ==1639==      possibly lost: 0 bytes in 0 blocks
// ==1639==    still reachable: 0 bytes in 0 blocks
// ==1639==         suppressed: 0 bytes in 0 blocks
// ==1639== 
// ==1639== For lists of detected and suppressed errors, rerun with: -s
// ==1639== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 