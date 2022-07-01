/* @csalgo

Coding Problem
Problem Statement: BST to LL
Problem Level: EASY
Problem Description:
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:
The first and only line of output prints the elements of sorted linked list.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output 1:
2 5 6 7 8 10
*/

#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
pair<Node *, Node *> BSTToLL(BinaryTreeNode<int> *root)
{
    pair<Node *, Node *> ans{NULL, NULL};
    if (!root)
        return ans;
    Node *root2 = new Node(root->data);

    pair<Node *, Node *> left, right;

    if (root->left)
    {
        left = BSTToLL(root->left);

        // left.second = BSTToLL(root->left).second;
        left.second->next = root2;
        ans.first = left.first;
    }
    else
    {
        ans.first = root2;
    }
    if (root->right)
    {
        right = BSTToLL(root->right);
        // right.first = BSTToLL(root->right).first;
        root2->next = right.first;
        ans.second = right.second;
    }
    else
    {
        ans.second = root2;
    }
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    Node *head = BSTToLL(root).first;
    print(head);
    // printLevelATNewLine(root);

    return 0;
}