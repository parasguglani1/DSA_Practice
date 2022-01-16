#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Since the memory occupied by an array must be contiguous, the array can't increase in
size, therefore, a new array must be created and the elements must be shifted to the new one */

int main(void)
{
    int *p = new int[5]; // Creates an array in heap that is size 5
    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 1; // Assigning values
    }
    // The content is 1,2,3,4,5

    // Suppose you want to increase the size of the array p is pointing to:
    int *n = new int[10]; // Create a new array in heap with the desired size

    for (int i = 0; i < 5; i++)
    {
        n[i] = p[i]; // Copy the smaller array into the larger one
    }
    // The content is 1,2,3,4,5,0,0,0,0,0

    delete []p; // Deallocate the memory you no longer need
    p = n; // Make p point to the new array
    n = NULL; // n will no longer point to the second array

    return 0;
}
