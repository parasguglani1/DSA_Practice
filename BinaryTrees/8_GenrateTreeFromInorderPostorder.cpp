/*

Coding Problem
Problem Statement: Construct Tree from postorder  inorder
Problem Level: MEDIUM
Problem Description:
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements.

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line.
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
7
4 5 2 6 7 3 1
4 2 5 1 6 3 7

Sample Output 1:
1
2 3
4 5 6 7

Sample Input 2:
6
2 9 3 6 10 5
2 6 3 9 5 10

Sample Output 2:
5
6 10
2 3
9

 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
int searchInorder(int inArray[], int inStart, int inEnd, int data)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inArray[i] == data)
        {
            return i;
        }
    }
    return -1;
}

BinaryTreeNode<int> *buildTreefromInpostHelper(int *inOrder, int *postOrder, int inStart, int postStart, int inEnd, int postEnd)
{
    if (inStart > inEnd)
    {
        return NULL;
    }
    int rootData = postOrder[postEnd];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lInStart = inStart;
    int lInEnd = rootIndex - 1;
    int lpostStart = postStart;
    int lpostEnd = lpostStart + lInEnd - lInStart;
    int rInStart = rootIndex + 1;
    int rInEnd = inEnd;
    int rpostStart = lpostEnd + 1;
    int rpostEnd = postEnd - 1;

    BinaryTreeNode<int> *leftSubTree = buildTreefromInpostHelper(inOrder, postOrder, lInStart, lpostStart, lInEnd, lpostEnd);
    BinaryTreeNode<int> *rightSubTree = buildTreefromInpostHelper(inOrder, postOrder, rInStart, rpostStart, rInEnd, rpostEnd);
    root->left = leftSubTree;
    root->right = rightSubTree;

    return root;
}
BinaryTreeNode<int> *buildTreefromInpost(int *in, int *post, int size)
{
    return buildTreefromInpostHelper(in, post, 0, 0, size - 1, size - 1);
}

// method2
BinaryTreeNode<int> *buildTreefromInpost2(int *inorder, int *postorder, int inStart, int inEnd)
{
    static int postIndex = 0;

    if (inStart > inEnd)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postIndex++]);

    if (inStart == inEnd)
    {
        return root;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, root->data);
    root->left = buildTreefromInpost2(inorder, postorder, inStart, splitIndex - 1);
    root->right = buildTreefromInpost2(inorder, postorder, splitIndex + 1, inEnd);

    return root;
}
int main()
{
    int size;
    cin >> size;
    int post[size];
    for (int i = 0; i < size; i++)
    {
        cin >> post[i];
    }
    int in[size];
    for (int i = 0; i < size; i++)
    {
        cin >> in[i];
    }
    BinaryTreeNode<int> *root = buildTreefromInpost(in, post, size);
    // BinaryTreeNode<int> *root = buildTreefromInpost2(in, post, 0, size - 1);

    printLevelATNewLine(root);
    // inOrder(root);
    // cout << "hello";

    return 0;
}