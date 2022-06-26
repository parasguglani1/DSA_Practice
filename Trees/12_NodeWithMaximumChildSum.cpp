/* Chapter Assignment
Problem Statement: Node with maximum child sum
Problem Level: MEDIUM
Problem Description:
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

Sample Output 1 :
1

 */
#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << nodeWithMaxChildSum(root).first->data << endl;
    // printLevelWise(root);

    return 0;
}