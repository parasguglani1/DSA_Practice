#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

/* Chapter Assignment
Problem Statement: Pair sum BInary Tree
Problem Level: MEDIUM
Problem Description:
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S

Output Format :
Each pair in different line (pair elements separated by space)

Constraints :
1 <= N <= 1000

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15

Sample Output 1:
5 10
6 9
 */

//(n2) complexity
/* 
bool searchAndReplace(BinaryTreeNode<int> *root, int x)
{
    if (!root)
    {
        return false;
    }
    if (root->data == x)
    {
        // cout << root->data << endl;
        root->data = -1;
        // cout << root->data << endl;
        return true;
    }   
    bool ifPresentLeft = searchAndReplace(root->left, x);
    bool ifPresentRight = searchAndReplace(root->right, x);
    return ifPresentLeft || ifPresentRight;
}
void pairSum(BinaryTreeNode<int> *curNode, BinaryTreeNode<int> *root, int sum)
{
    if (!curNode)
    {
        return;
    }
    int find = sum - curNode->data;
    if (searchAndReplace(root, find))
    {
        cout << curNode->data << " " << find << endl;
        // curNode->data = -1;
    }
    pairSum(curNode->left, root, sum);
    pairSum(curNode->right, root, sum);
} */

vector<int> *preOrderTraversal(BinaryTreeNode<int> *root)
{
    vector<int> *ans = new vector<int>();
    if (root == NULL)
    {
        return ans;
    }
    ans->push_back(root->data);
    vector<int> *left = preOrderTraversal(root->left);
    vector<int> *right = preOrderTraversal(root->right);
    for (int i = 0; i < left->size(); i++)
    {
        ans->push_back(left->at(i));
    }
    for (int i = 0; i < right->size(); i++)
    {
        ans->push_back(right->at(i));
    }
    return ans;
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> *arr = preOrderTraversal(root);
    sort(arr->begin(), arr->end());
    int start = 0, end = arr->size() - 1;
    while (start < end)
    {
        if (arr->at(start) + arr->at(end) == sum)
        {
            cout << arr->at(start) << " " << arr->at(end) << endl;
            start++;
            end--;
        }
        else if (arr->at(start) + arr->at(end) < sum)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    int sum;
    cin >> sum;
    // pairSum(root, root, sum);
    pairSum(root, sum);
    // printLevelATNewLine(root);
    delete root;

    return 0;
}