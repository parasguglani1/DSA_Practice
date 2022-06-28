/* Chapter Assignment
Problem Statement: Second Largest Element In Tree
Problem Level: MEDIUM
Problem Description:
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1 :
40

*/

#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

// first is maximum second is secondMax
pair<TreeNode<int> *, TreeNode<int> *> secondLargestPair(TreeNode<int> *root)
{

    pair<TreeNode<int> *, TreeNode<int> *> ans{NULL, NULL};
    ans.first = NULL;
    ans.second = NULL;
    if (!root)
    {
        return ans;
    }
    ans.first = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, TreeNode<int> *> smallAns = secondLargestPair(root->children[i]);

        if (ans.first->data > smallAns.first->data)
        {
            if (ans.second == NULL || ans.second->data < smallAns.first->data)
            {
                ans.second = smallAns.first;
            }
        }
        else if (ans.first->data < smallAns.first->data)
        {
            if (smallAns.second == NULL)
            {
                ans.second = ans.first;
                ans.first = smallAns.first;
            }
            else
            {
                TreeNode<int> *temp;
                temp = ans.first;
                ans.first = smallAns.first;
                if (smallAns.second->data < temp->data)
                {
                    ans.second = temp;
                }
                else
                {
                    ans.second = smallAns.second;
                }
            }
        }
    }
    return ans;
}

TreeNode<int> *secondLargest(TreeNode<int> *root)
{
    TreeNode<int> *ans = secondLargestPair(root).second;

    return ans;
}

// 2nd method
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if (root == NULL || root->children.size() == 0)
    {
        return NULL;
    }
    TreeNode<int> *largest = root;
    TreeNode<int> *second = NULL;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        if (f != NULL && largest != NULL && f->data > largest->data)
        {
            second = largest;
            largest = f;
        }
        else if (f != NULL && second != NULL && f->data > second->data && f->data != largest->data)
        {
            second = f;
        }
        for (int i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }
    return second;
}
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = secondLargest(root);
    if (ans)
        cout << ans->data;
    // printLevelWise(root);

    return 0;
}