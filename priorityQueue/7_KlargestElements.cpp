/* Coding Problem
Problem Statement: K largest elements
Problem Level: MEDIUM
Problem Description:
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k

Output Format :
k largest elements

Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6
4

Sample Output :
12
16
20
25

 */

#include <bits/stdc++.h>
using namespace std;
vector<int> klargest(int *input, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (input[i] > pq.top())
        {
            pq.pop();
            pq.push(input[i]);
        }
    }
    vector<int> output;
    while (!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
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
    int k;
    cin >> k;
    vector<int> output = klargest(input, size, k);
    sort(output.begin(), output.end());
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    delete[] input;

    return 0;
}