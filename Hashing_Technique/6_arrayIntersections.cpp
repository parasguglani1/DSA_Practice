/*
Coding Problem
Problem Statement: Array Intersection
Problem Level: MEDIUM
Problem Description:
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).

<br>
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec

Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7
2
10 10
1
10

Sample Output 1 :
2 3 4
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
1 2 2

Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.
 */
#include <bits/stdc++.h>
using namespace std;
// better method
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp.count(arr2[i]) > 0 && mp[arr2[i]] > 0)
        {
            cout << arr2[i] << " ";
            mp[arr2[i]]--;
        }
    }
}
// my method
/* vector<int> getIntersection(int n, int *arr, int n2, int *arr2)
{
    vector<int> ans;
    unordered_map<int, int> freq1, freq2;
    for (int i = 0; i < n; i++)
    {
        freq1[arr[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        freq2[arr2[i]]++;
    }
    // find each ele in 2nd map and print min of there counts

    for (int i = 0; i < n; i++)
    {
        if (freq2.count(arr[i]) > 0 && freq1.count(arr[i]) > 0)
        {
            int count1 = freq1[arr[i]];
            int count2 = freq2[arr[i]];
            // cout << "for " << arr[i] << " count1 is " << count1 << " count2 is " << count2 << endl;
            for (int j = 0; j < min(count1, count2); j++)
            {
                // cout << "ele is" << arr[i] << endl;
                ans.push_back(arr[i]);
            }
            freq1.erase(arr[i]);
            freq2.erase(arr[i]);
        }
    }

    for (int i = 0; i < n2; i++)
    {
        if (freq2.count(arr2[i]) && freq1.count(arr2[i]))
        {
            int count1 = freq1[arr[i]];
            int count2 = freq2[arr[i]];
            for (int j = 0; j < min(count1, count2); j++)
            {
                ans.push_back(arr[i]);
            }
            freq1.erase(arr[i]);
            freq2.erase(arr[i]);
        }
    }
    return ans;
}
 */

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            // int ele;
            cin >> arr[i];
            // freq[ele]++;
        }
        int n2;
        cin >> n2;
        int arr2[n];

        for (int i = 0; i < n2; i++)
        {
            // int ele;
            cin >> arr2[i];
            // freq[ele]++;
        }

        // vector<int> ans = getIntersection(n, arr, n2, arr2);
        printIntersection(arr, arr2, n, n2);

        // for (int i = 0; i < ans.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
        cout << endl;
    }

    return 0;
}