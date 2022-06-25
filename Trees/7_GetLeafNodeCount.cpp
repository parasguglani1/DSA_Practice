/*

Coding Problem
Problem Statement: Count leaf Nodes
Problem Level: EASY
Problem Description:
Given a generic tree, count and return the number of leaf nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output prints the count of leaf nodes present in the given tree.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
4
 */
#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

int getLeafCount(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->children.size())
        return 1;

    int count = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        count = count + getLeafCount(root->children[i]);
    }
    return count;
}

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    cout << getLeafCount(root) << endl;
    return 0;
}
