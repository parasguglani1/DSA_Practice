#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

// take input : 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int> *root = takeInputRecursive();
    printRecursive(root);
    // cout << root->data << endl;
    // root->left = node1;
    // root->right = node2;

    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    return 0;
}