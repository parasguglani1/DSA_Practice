/* Problem Statement: Remove Leaf nodes
Problem Level: EASY
Problem Description:
Remove all leaf nodes from a given Binary Tree. Leaf nodes are those nodes, which don't have any children.
Note : Root will also be a leaf node if it doesn't have left and right child. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Elements are printed level wise, each level in new line (separated by space).

Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output :
8
3 10
6 14 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

void removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    if (root->left && !root->left->left && !root->left->right)
    {
        delete root->left;
        root->left = NULL;
    }
    if (root->right && !root->right->left && !root->right->right)
    {
        delete root->right;
        root->right = NULL;
    }
    removeLeafNodes(root->left);
    removeLeafNodes(root->right);
}
// 2nd method
/* BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    BinaryTreeNode<int> *leftSubTree = removeLeafNodes(root->left);
    BinaryTreeNode<int> *rightSubTree = removeLeafNodes(root->right);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
} */

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    removeLeafNodes(root);
    printLevelATNewLine(root);

    return 0;
}