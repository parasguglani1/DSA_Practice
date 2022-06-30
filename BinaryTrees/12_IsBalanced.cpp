/*

Chapter Assignment
Problem Statement:  Balanced
Problem Level: MEDIUM
Problem Description:
Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
Input format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :
false

Sample Input 2 :
1 2 3 -1 -1 -1 -1

Sample Output 2 :
true


 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
// n*h approach
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left) - getHeight(root->right)) <= 1;
}

// pair class complexity n
pair<bool, int> checkBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = checkBalanced(root->left);
    pair<int, int> right = checkBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}
bool isBalanced2(BinaryTreeNode<int> *root)
{
    return checkBalanced(root).first;
}

// o(n) without pair class
bool flag = 1;
int check(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;

    int lh = check(root->left);
    int rh = check(root->right);

    if (abs(lh - rh) > 1)
        flag = 0;

    return 1 + max(lh, rh);
}
bool isBalanced3(BinaryTreeNode<int> *root)
{

    flag = 1;
    int k = check(root);

    return flag;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelorder(root);
    cout << (isBalanced(root) ? "true" : "false");
    return 0;
}