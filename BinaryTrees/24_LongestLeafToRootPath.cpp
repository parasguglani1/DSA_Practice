/* 
Problem Statement: Longest Leaf to root path
Problem Level: MEDIUM
Problem Description:
Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 1 : Binary Tree 1 (separated by space)

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :
9
3
6
5

 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
vector<int> *longestPath(BinaryTreeNode<int> *root)
{
    vector<int> *res = new vector<int>();
    if (root == NULL)
    {
        return res;
    }
    if (root->left == NULL && root->right == NULL)
    {
        res->push_back(root->data);
        return res;
    }
    vector<int> *left = longestPath(root->left);
    vector<int> *right = longestPath(root->right);
    if (left->size() > right->size())
    {
        left->push_back(root->data);
        return left;
    }
    else
    {
        right->push_back(root->data);
        return right;
    }
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelATNewLine(root);
    // printLevelorder(root);
    vector<int> *output = longestPath(root);
    vector<int>::iterator i = output->begin();
    while (i != output->end())
    {
        cout << *i << endl;
        i++;
    }

    return 0;
}