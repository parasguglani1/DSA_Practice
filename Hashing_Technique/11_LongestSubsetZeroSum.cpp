/* Problem Statement: Longest subset zero sum
Problem Level: MEDIUM
Problem Description:
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.

Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1:
10
 95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output 1:
5

Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897
 */

#include <bits/stdc++.h>
using namespace std;
// simpler but need to verify
int longestSubsetZero(int *arr, int n)
{
    unordered_map<int, int> mp;
    int maxLength = 0;
    int length = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        // cout << " sum is " << sum << endl;
        if (sum == 0)
        {
            maxLength = max(maxLength, i + 1);
        }
        else if (mp.count(sum) == 0)
            mp[sum] = i;
        else
        {
            length = i - mp[sum];
            maxLength = max(maxLength, length);
        }
        // int key = arr[i];
        // int count2 = mp[key + k];
        // count += count2;
        // if (k != 0)
        // {
        //     int count3 = mp[key - k];
        //     count += count3;
        // }
        // mp[key]++;
    }
    return maxLength;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << longestSubsetZero(a, n) << endl;
    // }

    return 0;
}