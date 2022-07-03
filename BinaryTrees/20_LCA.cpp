/* Chapter Assignment
Problem Statement: LCA of Binary Tree
Problem Level: MEDIUM
Problem Description:
Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.
Input format :
Line 1 :  Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two integers, Node 1 and Node 2 (separated by space)

Output Format :
LCA

Constraints :
1 <= N <= 1000

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10

Sample Output 1:
10

Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6

Sample Output 2:
5

Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78

Sample Output 3:
-1
 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

BinaryTreeNode<int> *getLCA(BinaryTreeNode<int> *root, int node1, int node2)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == node1 || root->data == node2)
    {
        return root;
    }
    BinaryTreeNode<int> *leftAns = getLCA(root->left, node1, node2);
    BinaryTreeNode<int> *rightAns = getLCA(root->right, node1, node2);
    if (!leftAns && !rightAns)
    {
        return NULL;
    }
    if (leftAns && rightAns)
    {
        return root;
    }
    if (leftAns)
        return leftAns;
    if (rightAns)
        return rightAns;
    return NULL;
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    int node1, node2;
    cin >> node1 >> node2;
    BinaryTreeNode<int> *ans = getLCA(root, node1, node2);
    if (!ans)
        cout << "-1";
    else
    {
        cout << ans->data;
    }
    // printLevelATNewLine(root);
    delete root;

    return 0;
}