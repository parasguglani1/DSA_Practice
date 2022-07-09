/*
Chapter Assignment
Problem Statement: Running median
Problem Level: HARD
Problem Description:
You are given a stream of N integers. For every i-th integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer N, denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.

Output Format :
Print the running median for every integer added to the running list on a new line.

Input Constraints
1 <= N <= 10^5
1 <= Ai <= 10^5

Time Limit: 1sec

Sample Input 1 :
6
6 2 1 3 7 5

Sample Output 1 :
6
4
2
2
3
4

Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1

Sample Output 2 :
5
4
4
3
3
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> runningMedia(int *input, int n)
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> output;

    for (int i = 0; i < n; i++)
    {
        if (maxheap.empty() && minheap.empty())
        {
            maxheap.push(input[i]);
            // output.push_back(input[i]);
        }
        else if (input[i] < maxheap.top())
        {
            maxheap.push(input[i]);
            if (maxheap.size() - minheap.size() > 1)
            {
                int del = maxheap.top();
                maxheap.pop();
                minheap.push(del);
            }
        }
        else
        {
            minheap.push(input[i]);
            if (minheap.size() - maxheap.size() > 1)
            {
                int del = minheap.top();
                minheap.pop();
                maxheap.push(del);
            }
        }
        if (minheap.size() == maxheap.size())
        {
            // cout << "11";
            output.push_back((maxheap.top() + minheap.top()) / 2);
        }
        else if (minheap.size() > maxheap.size())
        {
            // cout << "22";
            output.push_back(minheap.top());
        }
        else
            // cout << "33";
            output.push_back(maxheap.top());
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
    vector<int> output = runningMedia(input, size);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    delete[] input;

    return 0;
}