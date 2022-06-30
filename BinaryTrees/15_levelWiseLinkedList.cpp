/*
Chapter Assignment
Problem Statement: Level wise linkedlist
Problem Level: MEDIUM
Problem Description:
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
Each level linked list is printed in new line (elements are separated by space).

Constraints:
Time Limit: 1 second

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
5
6 10
2 3
9
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
vector<Node *> levelWiseLinkedList(BinaryTreeNode<int> *root)
{
    // insert null whenever new level is inserted
    vector<Node *> v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    Node *head1 = NULL;
    Node *tail1 = NULL;
    // v.push_back(head1);
    // head1 = NULL;
    // tail1 = NULL;
    while (!q.empty())
    {

        BinaryTreeNode<int> *first = q.front();
        q.pop();

        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }

            // cout << endl;
            q.push(NULL);
            head1 = NULL;
            tail1 = NULL;
            continue;
        }
        // Node *head2 = new Node(first->data);
        // if (head1 == NULL)
        // {
        //     head1 = head2;
        //     tail1 = head2;
        // }

        if (!head1)
        {
            Node *Node2 = new Node(first->data);
            head1 = Node2;
            tail1 = Node2;
            v.push_back(head1);
        }
        else
        {
            Node *Node2 = new Node(first->data);
            tail1->next = Node2;
            tail1 = tail1->next;
        }
        // cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
    return v;
}
int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    // printLevelATNewLine(root);
    // cout << endl;
    vector<Node *> v = levelWiseLinkedList(root);
    for (int i = 0; i < v.size(); i++)
    {
        // if (v[i])
        // cout << v[i]->data;
        print(v[i]);
        // cout << endl;
    }

    return 0;
}