#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {

    // Declaring and initializing a 2D array (3x4) inside the stack
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 5, 7, 9}};

    // Creating a 2D array (3x4) with pointers
    int *P[3]; // Declaring an array of pointers (inside the stack)

    P[0] = new int[4]; // Creates an array of size 4 whose address is stored at A[0]
    P[1] = new int[4];
    P[2] = new int[4];
    // This way, the pointers point to the beginning of each row inside heap memory

    P[1][2] = 15; // Accessing is possible like this

    // Another method, using double pointers to create a 3x4 array
    int **Q; // Created inside stack, will point to an array in heap

    Q = new int*[3]; // Now an array of pointers is created in heap and Q points at it

    Q[0] = new int[4]; // Assigning rows to the array of pointers
    Q[1] = new int[4];
    Q[2] = new int[4];
    // Now the entire array is inside heap, only the double pointer is inside the stack

    int counter = 1;
    // It's possible to access all of these arrays like this:
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            Q[i][j] = counter++; // Initializing them from 1 to 12
            cout << Q[i][j] << " "; // Printing rows x columns
        }
        cout << endl;
    }

    // In C:
    int *B[3]; // Rows created inside the stack

    B[0] = (int *)malloc(4*sizeof(int)); // Columns created inside heap
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));

    // Array inside heap only:
    int **C; // Double pointer inside the stack

    C = (int **)malloc(3*sizeof(int *)); // Rows inside heap

    C[0] = (int *)malloc(4*sizeof(int)); // Columns inside heap
    C[1] = (int *)malloc(4*sizeof(int));
    C[2] = (int *)malloc(4*sizeof(int));

    return 0;
}
