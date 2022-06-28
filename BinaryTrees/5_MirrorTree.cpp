/*

Coding Problem
Problem Statement: Mirror Binary tree
Problem Level: EASY
Problem Description:
For a given Binary Tree of type integer, update it with its corresponding mirror image.
Example:

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints the mirrored tree in a level-wise order.
Each level will be printed on a new line. Elements printed at each level will be separated by a single line.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
1
3 2
7 6 5 4

Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 2:
5
6 10
3 2
9
 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
void mirrorTree(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    BinaryTreeNode<int> *temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelorder(root);
    // cout << endl;
    mirrorTree(root);
    printLevelATNewLine(root);
    return 0;
}
