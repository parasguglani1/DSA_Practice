/*

Chapter Assignment
Problem Statement: ZigZag tree
Problem Level: HARD
Problem Description:
Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Elements are printed level wise, each level in new line (separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :
5
10 6
2 3
9

*/

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

void printZigZag(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> st1, st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            BinaryTreeNode<int> *Node = st1.top();
            st1.pop();
            cout << Node->data << " ";
            if (Node->left)
                st2.push(Node->left);
            if (Node->right)
                st2.push(Node->right);
        }
        cout << endl;
        while (!st2.empty())
        {
            BinaryTreeNode<int> *Node = st2.top();
            st2.pop();
            cout << Node->data << " ";
            if (Node->right)
                st1.push(Node->right);
            if (Node->left)
                st1.push(Node->left);
        }
        cout << endl;
    }
}
// 1 2 3 4 5 6 7 - 1 - 1 8 - 1 - 1 9 - 1 - 1 - 1 - 1 10 - 1 -1 -1

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelATNewLine(root);
    printZigZag(root);
    // printLevelorder(root);
    return 0;
}