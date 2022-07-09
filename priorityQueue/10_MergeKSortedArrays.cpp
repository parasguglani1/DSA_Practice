/* Chapter Assignment
Problem Statement: Merge K sorted arrays
Problem Level: MEDIUM
Problem Description:
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays

Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234
 */

#include <bits/stdc++.h>
using namespace std;
// n logn
// vector<int> mergeKSortedArrays(vector<vector<int> *> input)
// {

//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (int i = 0; i < input.size(); i++)
//     {
//         for (int j = 0; j < input[i]->size(); j++)
//         {
//             pq.push(input[i]->at(j));
//         }
//     }

//     vector<int> ans;

//     while (!pq.empty())
//     {
//         ans.push_back(pq.top());
//         pq.pop();
//     }

//     return ans;
// }

class Triplet
{

public:
    int element;
    int arrayIndex;
    int elemIndex;
};
class cmp
{
public:
    bool operator()(Triplet a, Triplet b)
    {
        return a.element > b.element;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<Triplet, vector<Triplet>, cmp> pq;
    for (int i = 0; i < k; i++)
    {
        // cout << arr[0][0]<<" ";
        // cout << arr[i][0] << " " << endl;
        Triplet a;
        a.arrayIndex = i;
        a.elemIndex = 0;
        a.element = arr[i][0];
        pq.push(a);
    }

    vector<int> output;
    // output.push_back(45);

    while (!pq.empty())
    {
        Triplet top = pq.top();
        int curr_index = top.elemIndex;
        int curr_array = top.arrayIndex;
        pq.pop();
        output.push_back(top.element);
        if (curr_index < arr[curr_array].size() - 1)
        {

            Triplet a;
            a.arrayIndex = curr_array;
            a.elemIndex = curr_index + 1;
            a.element = arr[curr_array][curr_index + 1];
            pq.push(a);
            // if (a.element == 0)
            // {
            //     cout << "here "<<a.arrayIndex << " " << a.elemIndex<<endl;
            // }
        }
    }

    return output;
}
int main()
{

    int k;
    cin >> k;
    vector<vector<int>> arr;
    arr.reserve(k);
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        // arr[i].reserve(n);
        for (int j = 0; j < n; j++)
        {
            int ele;
            cin >> ele;
            arr[i].push_back(ele);
        }
    }
    // for (int i = 0; i < k; i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> output = mergeKSortedArrays(arr, k);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    // delete[] input;

    return 0;
}