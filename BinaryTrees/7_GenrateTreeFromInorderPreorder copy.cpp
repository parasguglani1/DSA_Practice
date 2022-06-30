/*

Coding Problem
Problem Statement: Construct Tree from preorder  inorder
Problem Level: MEDIUM
Problem Description:
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements.

Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

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
1 2 4 5 3 6 7
4 2 5 1 6 3 7

Sample Output 1:
1
2 3
4 5 6 7

Sample Input 2:
6
5 6 2 3 9 10
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

BinaryTreeNode<int> *buildTreefromInPreHelper(int *inOrder, int *preOrder, int inStart, int preStart, int inEnd, int preEnd)
{
    if (inStart > inEnd)
    {
        return NULL;
    }
    int rootData = preOrder[preStart];
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
    int lPreStart = preStart + 1;
    int lPreEnd = lPreStart + lInEnd - lInStart;
    int rInStart = rootIndex + 1;
    int rInEnd = inEnd;
    int rPreStart = lPreEnd + 1;
    int rPreEnd = preEnd;

    BinaryTreeNode<int> *leftSubTree = buildTreefromInPreHelper(inOrder, preOrder, lInStart, lPreStart, lInEnd, lPreEnd);
    BinaryTreeNode<int> *rightSubTree = buildTreefromInPreHelper(inOrder, preOrder, rInStart, rPreStart, rInEnd, rPreEnd);
    root->left = leftSubTree;
    root->right = rightSubTree;

    // root->left = buildTreefromInPreHelper(in, pre, lInStart, lPreStart, lInEnd, lPreEnd);
    // root->right = buildTreefromInPreHelper(in, pre, rInStart, rPreStart, rInEnd, rPreEnd);
    return root;
}
BinaryTreeNode<int> *buildTreefromInPre(int *in, int *pre, int size)
{
    return buildTreefromInPreHelper(in, pre, 0, 0, size - 1, size - 1);
}

// method2
BinaryTreeNode<int> *buildTreefromInPre2(int *inorder, int *preorder, int inStart, int inEnd)
{
    // Reference: https://algorithms.tutorialhorizon.com/make-a-binary-tree-from-given-inorder-and-preorder-traveral/
    static int preIndex = 0;

    if (inStart > inEnd)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preIndex++]);

    if (inStart == inEnd)
    {
        return root;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, root->data);
    root->left = buildTreefromInPre2(inorder, preorder, inStart, splitIndex - 1);
    root->right = buildTreefromInPre2(inorder, preorder, splitIndex + 1, inEnd);

    return root;
}
int main()
{
    int size;
    cin >> size;
    int pre[size];
    for (int i = 0; i < size; i++)
    {
        cin >> pre[i];
    }
    int in[size];
    for (int i = 0; i < size; i++)
    {
        cin >> in[i];
    }
    // BinaryTreeNode<int> *root = buildTreefromInPre(in, pre, size);
    // BinaryTreeNode<int> *root = builTreeRecApp2(pre, in, 0, size - 1);
    BinaryTreeNode<int> *root = buildTreefromInPre2(in, pre, 0, size - 1);

    printLevelATNewLine(root);
    // inOrder(root);
    // cout << "hello";

    return 0;
}