/* Chapter TEST
Problem Statement: Check cousins
Problem Level: MEDIUM
Problem Description:
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
Do it in O(n).
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Line 2 : integer value of p 
Line 3 : Integer value of q

Output format :
true or false

Constraints :
1 <= N <= 10^5

Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4

Sample Output :
true

 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == NULL)
    {
        return false;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    bool foundP = false, foundQ = false;
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *f = pendingNodes.front();
        if (f == NULL)
        {
            if (foundP && foundQ)
            {
                return true;
            }
            else if ((foundP && !foundQ) || (foundQ && !foundP))
            {
                return false;
            }
            pendingNodes.pop();
            if (!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }
        else
        {
            pendingNodes.pop();
            if (f->data == p)
            {
                foundP = true;
            }
            else if (f->data == q)
            {
                foundQ = true;
            }
            if (f->left && f->right)
            {
                if (f->left->data == p && f->right->data == q)
                {
                    return false;
                }
                else if (f->left->data == q && f->right->data == p)
                {
                    return false;
                }
            }

            if (f->left != NULL)
            {
                pendingNodes.push(f->left);
            }
            if (f->right != NULL)
            {
                pendingNodes.push(f->right);
            }
        }
    }
    return false;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelATNewLine(root);
    // printLevelorder(root);
    int n1, n2;
    cin >> n1 >> n2;
    if (isCousin(root, n1, n2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}