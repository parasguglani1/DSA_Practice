/*
Chapter Assignment
Problem Statement: Pair sum in a BST
Problem Level: MEDIUM
Problem Description:
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.

Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.

Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12

Sample Output 1:
2 10
5 7

 */

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;
//n2 complexity 
/* bool searchAndReplaceBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        root->data = -1;
        return true;
    }
    if (k < root->data)
    {
        return searchAndReplaceBST(root->left, k);
    }
    else
    {
        return searchAndReplaceBST(root->right, k);
    }
}

void pairSum(BinaryTreeNode<int> *curNode, BinaryTreeNode<int> *root, int sum)
{
    if (!curNode)
    {
        return;
    }
    int find = sum - curNode->data;
    curNode->data = -1;
    if (find < root->data)
    {
        if (searchAndReplaceBST(root->left, find))
        {
            cout << sum - find << " " << find << endl;
            // curNode->data = -1;
        }
    }
    else
    {
        if (searchAndReplaceBST(root->right, find))
        {
            cout << sum - find << " " << find << endl;
            // curNode->data = -1;
        }
    }
    curNode->data = sum - find;

    pairSum(curNode->left, root, sum);
    pairSum(curNode->right, root, sum);
} */

void inOrderTraversal(BinaryTreeNode<int> *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    vector<int> arr;
    inOrderTraversal(root, arr);
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == s)
        {
            cout << arr[l] << " " << arr[r] << endl;
            l++;
            r--;
        }
        else if (arr[l] + arr[r] < s)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
}
// Approach 2 : time O(n) , space O(logn)
void printNodesSumToSLogN(BinaryTreeNode<int> *root, int s)
{
    if (root == NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    BinaryTreeNode<int> *curr1 = root;
    BinaryTreeNode<int> *curr2 = root;
    int val1 = 0, val2 = 0;
    bool done1 = false, done2 = false;
    while (1)
    {
        while (done1 == false)
        {
            if (curr1 != NULL)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            else
            {
                if (s1.empty())
                {
                    done1 = true;
                }
                else
                {
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->data;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }
        while (done2 == false)
        {
            if (curr2 != NULL)
            {
                s2.push(curr2);
                curr2 = curr2->right;
            }
            else
            {
                if (s2.empty())
                {
                    done2 = true;
                }
                else
                {
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->data;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }
        if (val1 != val2 && (val1 + val2) == s)
        {
            cout << val1 << " " << val2 << endl;
            return;
        }
        else if (val1 + val2 < s)
        {
            done1 = false;
        }
        else if (val1 + val2 > s)
        {
            done2 = false;
        }
        if (val1 >= val2)
        {
            return;
        }
    }
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    int sum;
    cin >> sum;
    // pairSum(root, root, sum);
    // printLevelATNewLine(root);

    // printNodesSumToS(root, sum);
    printNodesSumToSLogN(root, sum);
    delete root;

    return 0;
}