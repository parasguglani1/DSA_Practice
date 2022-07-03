/* Chapter Assignment
Problem Statement: Largest BST
Problem Level: HARD
Problem Description:
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format:
The first and only line of output contains the height of the largest BST.

Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
2 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

class HelperBST
{
public:
    int min;
    int max;
    bool isBST;
    int height;
};
HelperBST maxHeightBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        HelperBST ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        ans.height = 0;
        return ans;
    }
    HelperBST left = maxHeightBST(root->left);
    HelperBST right = maxHeightBST(root->right);
    HelperBST ans;
    ans.min = min(root->data, min(left.min, right.min));
    ans.max = max(root->data, max(left.max, right.max));
    ans.isBST = (root->data > left.max) && (root->data <= right.min) && left.isBST && right.isBST;
    if (ans.isBST)
    {
        ans.height = max(left.height, right.height) + 1;
    }
    else
    {
        ans.height = max(left.height, right.height);
    }
    return ans;
}
int isBST2(BinaryTreeNode<int> *root)
{
    HelperBST ans = maxHeightBST(root);
    return ans.height;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    cout << isBST2(root) << endl;

    // printLevelATNewLine(root);
    delete root;

    return 0;
}