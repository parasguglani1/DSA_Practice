/*

Coding Problem
Problem Statement: Height Of Tree
Problem Level: EASY
Problem Description:
For a given Binary Tree of integers, find and return the height of the tree.
Example:
                        10
                      /      \
                    20      30
                   /    \
                 40    50

Height of the given tree is 3.

Height is defined as the total number of nodes along the longest path from the root to any of the leaf node.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The first and the only line of output prints the height of the given binary tree.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
0 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
10 20 30 40 50 -1 -1 -1 -1 -1 -1

Sample Output 1:
3

Sample Input 2:
3 -1 -1

Sample Output 2:
1

 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
int getHeight(BinaryTreeNode<int> *root)
{
  if (!root)
  {
    return 0;
  }

  int height1 = getHeight(root->left);
  int height2 = getHeight(root->right);
  return max(height1, height2) + 1;
}

int main()
{
  BinaryTreeNode<int> *root = taktInputLevelorder();
  // printLevelorder(root);
  cout << getHeight(root);
  return 0;
}