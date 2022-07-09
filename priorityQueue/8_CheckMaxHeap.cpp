/* Chapter Assignment
Problem Statement: Check Max-Heap
Problem Level: EASY
Problem Description:
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.

Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec

Sample Input 1:
8
42 20 18 6 14 11 9 4

Sample Output 1:
true */

#include <bits/stdc++.h>
using namespace std;

// bool checkMaxHeap(int arr[], int n)
// {

//     for (int child = 1; child < n; child++)
//     {
//         int parent = (child - 1) / 2;
//         if (arr[parent] < arr[child])
//             return false;
//     }
// }

bool checkMaxHeap(int *input, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((2 * i+1 )< n && input[i] < input[2 * i+1])
        {
            // cout<<i<<endl;
            
            return false;
        }
        if (2 * i + 2 < n && input[i] < input[2 * i + 2])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int size;
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }
    bool output = checkMaxHeap(input, size);
    if (output)
        cout << "true";
    else
    {
        cout << "false";
    }
    delete[] input;

    return 0;
}