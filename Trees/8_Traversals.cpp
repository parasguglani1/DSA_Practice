/*
Coding Problem
Problem Statement: Post-order Traversal
Problem Level: EASY
Problem Description:
Given a generic tree, print the post-order traversal of given tree.
The post-order traversal is: visit child nodes first and then root node.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains the elements printed in post-order traversal. The elements in the output must be separated by a single space.

Constraints:
Time Limit: 1 sec
post order
Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0

Sample Output 1:
post order
400 50 20 30 40 10

pre order
input 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
output 1 2 5 6 3 7 8 9 4
 */

#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    preOrderTraversal(root);
    return 0;
}
