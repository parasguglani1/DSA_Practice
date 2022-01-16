#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void)
{
    // Static array: size decided at compile time, though memory is allocated during runtime
    int A[5]; // Created in the stack, inside the activation record of main

    /* In C, the size mentioned must be a constant value, not a variable, while in C++
    you can create an array of any size at runtime and it will be created inside the stack only */

    // In C++ the size may be decided at runtime
    int n;
    cin >> n;
    int B[n]; // Variable-length array (not supported until C++11)

    // Dynamic array: creating an array inside heap (must have a pointer to access it)
    int *p;
    p = (int *)malloc(5 * sizeof(int)); // C
    int *q;
    q = new int[5]; // C++

    A[0] = 1; // Accessing arrays in stack

    *q = 1; // Accessing in heap by using a pointer
    q[0] = 1; // Also possible

    printf("%d\n", q[0]);
    printf("%d\n", *q);

    // After you no longer need the array, delete memory to avoid memory leak
    free(p); // C
    delete []q; // C++

    /* Once the size of a stack array is decided, it cannot be changed.
    In heap, the same array cannot be resized, but there's an alternative */
}
