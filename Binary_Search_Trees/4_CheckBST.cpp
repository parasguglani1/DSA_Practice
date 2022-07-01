#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

void preOrderPrint(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

/**
Coding Problem
Problem Statement: Check BST
Problem Level: MEDIUM
Problem Description:
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
Duplicate elements should be in right subtree.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place

Output format :
true or false

Constraints :
1 <= N <= 10^5

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :
false
 */

// Approach 1 - O(n*h) i.e. O(nlogn) if tree balanced , O(n^2) if tree height is O(n)
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool ans = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return ans;
}

// Approach 2 - O(n) - one pass solution
class HelperBST
{
public:
    int min;
    int max;
    bool isBST;
};
HelperBST isBST2Helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        HelperBST ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        return ans;
    }
    HelperBST left = isBST2Helper(root->left);
    HelperBST right = isBST2Helper(root->right);
    HelperBST ans;
    ans.min = min(root->data, min(left.min, right.min));
    ans.max = max(root->data, max(left.max, right.max));
    ans.isBST = (root->data > left.max) && (root->data <= right.min) && left.isBST && right.isBST;
    return ans;
}
bool isBST2(BinaryTreeNode<int> *root)
{
    HelperBST ans = isBST2Helper(root);
    return ans.isBST;
}

// Approach 3 - O(n)
bool isBST3Helper(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool left = isBST3Helper(root->left, min, root->data - 1);
    bool right = isBST3Helper(root->right, root->data, max);
    return left && right;
}
bool isBST3(BinaryTreeNode<int> *root)
{
    bool ans = isBST3Helper(root);
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    cout << (isBST(root) ? "true" : "false");
    cout << (isBST2(root) ? "true" : "false");
    cout << (isBST3(root) ? "true" : "false");

    return 0;
}