/*

Chapter Assignment
Problem Statement: Next larger
Problem Level: MEDIUM
Problem Description:
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
The following line contains an integer, that denotes the value of n.

Output format :
The first and only line of output contains data of the node, whose data is just greater than n.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
20

Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 2:
30

*/

#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

TreeNode<int> *nextLarger(TreeNode<int> *root, int n)
{
    if (!root)
        return 0;
    TreeNode<int> *ans;
    if (root->data > n)
        ans = root;
    else
        ans = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = nextLarger(root->children[i], n);
        if (!ans)
        {
            ans = smallAns;
        }
        if (smallAns && ans->data > smallAns->data)
        {
            ans = root->children[i];
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = nextLarger(root, n);
    if (ans)
    {
        cout << ans->data;
    }
    else
        cout << 0;
    // printLevelWise(root);

    return 0;
}