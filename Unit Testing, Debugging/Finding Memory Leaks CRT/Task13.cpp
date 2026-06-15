#include <iostream>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    for (int i = 0; i < 100; ++i) {
        int* arr = new int[1000];
        // No delete[] arr;  // Intentional leak!
    }
    return 0;
}

// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ g++ -g -o T13 Task13.cpp
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ valgrind --leak-check=full ./T13
// ==1571== Memcheck, a memory error detector
// ==1571== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
// ==1571== Using Valgrind-3.26.0 and LibVEX; rerun with -h for copyright info
// ==1571== Command: ./T13
// ==1571== 
// ==1571== 
// ==1571== HEAP SUMMARY:
// ==1571==     in use at exit: 400,000 bytes in 100 blocks
// ==1571==   total heap usage: 101 allocs, 1 frees, 473,728 bytes allocated
// ==1571== 
// ==1571== 400,000 bytes in 100 blocks are definitely lost in loss record 1 of 1
// ==1571==    at 0x48525F3: operator new[](unsigned long) (vg_replace_malloc.c:730)
// ==1571==    by 0x4001167: main (Task13.cpp:11)
// ==1571== 
// ==1571== LEAK SUMMARY:
// ==1571==    definitely lost: 400,000 bytes in 100 blocks
// ==1571==    indirectly lost: 0 bytes in 0 blocks
// ==1571==      possibly lost: 0 bytes in 0 blocks
// ==1571==    still reachable: 0 bytes in 0 blocks
// ==1571==         suppressed: 0 bytes in 0 blocks
// ==1571== 
// ==1571== For lists of detected and suppressed errors, rerun with: -s
// ==1571== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
// arnavkumar@EPINHYDW182F:/mnt/c/Users/ArnavKumar/OneDrive - EPAM/Work/Unit Testing, Debugging/Finding Memory Leaks CRT$ 