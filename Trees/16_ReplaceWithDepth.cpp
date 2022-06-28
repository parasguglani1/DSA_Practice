/*
Chapter Assignment
Problem Statement: Replace with depth
Problem Level: MEDIUM
Problem Description:
You are given a generic tree. You have to replace each node with its depth value. You just have to update the data of each node, there is no need to return or print anything.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format:
The updated tree is printed level wise. Each level is printed in a new line. Please refer to sample output 1 for more details.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1:
0
1 1 1
2 2
*/
#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

void replaceWithDepth(TreeNode<int> *root, int x)
{
    if (!root)
        return;
    root->data = x;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepth(root->children[i], x + 1);
        cout << endl;
    }
}
// 2nd method using queue
void replaceWithDepthValue(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    int i = 0;
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        while (f != NULL)
        {
            f->data = i;
            q.pop();
            for (int i = 0; i < f->children.size(); i++)
            {
                q.push(f->children[i]);
            }
            f = q.front();
            if (f == NULL)
            {
                q.push(NULL);
            }
        }
        q.pop();
        i++;
    }
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    replaceWithDepth(root, 0);
    printLevelATNewLine(root);
    return 0;
}