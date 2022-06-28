/*
Chapter Assignment
Problem Statement: Structurally identical
Problem Level: MEDIUM
Problem Description:
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.

Input format :
The first line of input contains data of the nodes of the first tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
The following line of input contains data of the nodes of the second tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format :
The first and only line of output contains true, if the given trees are structurally identical and false, otherwise.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
true

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 3 2 30 40 2 40 50 0 0 0 0

Sample Output 2:
false
*/
#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;
bool isSame(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if (root1 == NULL ^ root2 == NULL)
    {
        return false;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    bool isIdentical = true;
    for (int i = 0; i < root1->children.size(); i++)
    {
        if (!isSame(root1->children[i], root2->children[i]))
        {
            isIdentical &= false;
        }
    }

    if (root1->data != root2->data)
    {
        isIdentical &= false;
    }
    return isIdentical;
}

int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    TreeNode<int> *root2 = takeInputLevelWise();

    bool isidentical = isSame(root1, root2);
    if (isidentical)
        cout << "true";
    else
        cout << "false";
    // printLevelWise(root);

    return 0;
}