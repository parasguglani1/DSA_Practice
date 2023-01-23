#include <iostream>

using namespace std;
/*
 * Array Basics
 *
 * int A[5];
 *
 * This is called a declaration of an array, you declare that you want to create an empty array
 * that is 5 spaces in length starting at index 0. The array is then stored in the main memory.
 *
 * int A[5] = {1, 2, 3, 4, 5};
 *
 * You can also declare an array this way. The left side is called the declaration, the right
 * side is called the initialization.
 *
 * The for loop is used to access all the elements of an array.
 *
 * for (int i = 0; i < 5; i++)
 * {
 *   cout << A[i] << endl;
 * }
 *
 * The above loop prints all elements in the array. i = 0 is the starting point of the loop, i
 * will start at index 0. i < 5 checks if the iterator is less than 5, and if that condition is
 * true then i++ increments the iterator by 1.
 */

int main()
{
    // Declaring an array
    int A[5];

    // Assigning values to it
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    // Declaring and Initializing the array
    int B[10] = {2, 4, 6, 8, 10};

    cout << sizeof(A) << '\n';
    cout << A[1] << '\n';
    printf("%d\n", A[2]);

    // If the array indexes are not defined then by default the values become 0
    cout << B[6] << '\n';
    cout << B[7] << '\n';

    // Garbage Values
    cout << A[3] << '\n';
    cout << A[4] << '\n';

    // for loop for displaying arrays
    for (int i = 0; i < 10; ++i)
        cout << B[i] << " ";

    cout << '\n';

    // for-each loop for displaying arrays
    for (int x : B)
        cout << x << " ";

    cout << "Size of array element at index 0: " << sizeof(A[0]) << " bytes" << endl;
    // Formula to get length of the array, 10
    cout << "Length of the array: " << sizeof(A) / sizeof(A[0]) << endl;

    cout << '\n';

    return 0;
}