/*

Coding Problem
Problem Statement: Preorder Binary Tree
Problem Level: EASY
Problem Description:
For a given Binary Tree of integers, print the pre-order traversal.
Input Format:
The first and the only line of input will contain the nodes data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints the pre-order traversal of the given binary tree.

Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Ouptut 1:
pre - 5 6 2 3 9 10
inorder- 2 6 3 9 5 10
post - 2 9 3 6 10 5
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Ouptut 2:
pre - 1 2 4 5 3 6 7
inorder- 4 2 5 1 6 3 7
post - 4 5 2 6 7 3 1
 */
//
#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

void preOrder(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelorder(root);
    // preOrder(root);
    // cout << endl;
    inOrder(root);
    // cout << endl;
    // postOrder(root);

    return 0;
}