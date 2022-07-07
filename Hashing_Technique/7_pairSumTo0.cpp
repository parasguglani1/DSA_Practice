/* Coding Problem
Problem Statement: Pair sum to 0
Problem Level: MEDIUM
Problem Description:
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0.

Constraints :
0 <= N <= 10^4
Time Limit: 1 sec

Sample Input 1:
5
2 1 -2 2 3

Sample Output 1:
2
 */

#include <bits/stdc++.h>
using namespace std;
// simpler but need to verify
int pairSum(int *arr, int n)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int rem = 0 - arr[i];
        if (mp.count(rem) > 0)
        {
            count += mp[rem];
        }
        mp[arr[i]]++;
    }
    return count;
}
/* int countPairs(int *arr, int n)
{
    int count = 0;
    unordered_map<int, int> freq1, freq2;
    for (int i = 0; i < n; i++)
    {
        freq1[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq1.count(0 - arr[i]) > 0 && arr[i] != 0)
        {
            int ele = arr[i];
            int count1 = freq1[ele];
            int count2 = freq1[0 - ele];
            count += count1 * count2;
            freq1.erase(arr[i]);
        }
    }
    if (freq1.count(0) > 0)
    {
        int zeros = freq1[0];
        int pairs = zeros * (zeros - 1) / 2;
        count+=pairs;
    }

    return count;
} */
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        // cout << countPairs(a, n) << endl;
        cout << pairSum(a, n) << endl;
    }

    return 0;
}
