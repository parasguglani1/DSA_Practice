/*
Coding Problem
Problem Statement: Is node present?
Problem Level: EASY
Problem Description:
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints 'true' or 'false'.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7

Sample Output 1:
true

Sample Input 2:
2 3 4 -1 -1 -1 -1
10

Sample Output 2:
false
 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (!root)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool ifPresentLeft = isNodePresent(root->left, x);
    bool ifPresentRight = isNodePresent(root->right, x);
    return ifPresentLeft || ifPresentRight;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    int x;
    cin >> x;

    if (isNodePresent(root, x))
        cout << "true";
    else
        cout << "false";
    return 0;
}