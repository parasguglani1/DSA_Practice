#include <stdio.h>

/* In C, a scalar variable is a unique element, while an array (vector) is a
collection of similar data type elements, and the memory allocation is contiguous */

int main(void)
{
    int A[5]; // Declaration without initialization, all garbage values
    int B[5] = {1, 2, 3, 4, 5}; // Initialized array
    int C[5] = {2, 4, 6}; // Values are: 2, 4, 6, 0, 0
    int D[5] = {0}; // All values are 0
    int E[] = {1, 2, 3, 4, 5}; // Array of size 6 is created
    printf("%d\n", B[2]);
    printf("%d\n", 2[B]); // Also acceptable
    printf("%d\n", *(B + 2)); // Using pointer arithmetic

    // Printing addresses
    for (int i = 0; i < 5; i++)
    {
        printf("%u\n", &B[i]);
        /* Output 6356692, 6356696, 6356700... demonstrates that each integer takes 4 bytes
        Could also have used %p (recommended) or %x (hexadecimal) */
    }
    return 0;
}
