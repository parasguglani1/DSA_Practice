#include <stdio.h>
#include <stdlib.h>

/* You can find the missing number by calculating the sum of all elements up to the last one
as if none were missing and do the same with the actual array, the difference between them is
the missing element. Formula: [n(n+1)]/2 */
struct Array
{
    int A[11];
    int size;
    int length;
};

// SINGLE MISSING ELEMENT
int ideal_sum(struct Array arr)
{
    int n = arr.A[arr.length - 1];
    int sum = (n * (n + 1)) / 2;
    return sum;
}

int actual_sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

int missing_element(struct Array arr)
{
    return ideal_sum(arr) - actual_sum(arr);
}

int single_missing_element(struct Array arr) // O(n)
{
    int lower = arr.A[0];
    int diff = lower - 0;
    //int higher = arr.A[arr.length -1];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            return arr.A[i] - 1;
        }
    }
}

// MULTIPLE MISSING ELEMENTS
void multiple_missing_elements(struct Array arr) // O(n)
{
    int lower = arr.A[0];
    int diff = lower - 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (arr.A[i] - i != diff)
            {
                printf("Missing: %d\n", i + diff);
                diff++;
            }
        }
    }
}

int main(void)
{
    struct Array arr1 = {{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12}, 11, 11}; // 7 missing
    struct Array arr2 = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17}, 11, 11}; // 12 missing
    struct Array arr3 = {{6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19}, 11, 11}; // 10, 13, 14 missing

    // For arrays that start with 1
    printf("Ideal sum: %d\n", ideal_sum(arr1));
    printf("Actual sum: %d\n", actual_sum(arr1));
    printf("Missing: %d\n", missing_element(arr1));

    // Single element, for arrays that start with numbers other than 1
    printf("Missing: %d\n", single_missing_element(arr2));

    // Multiple elements, for arrays that start with numbers other than 1
    multiple_missing_elements(arr3);

    return 0;
}
