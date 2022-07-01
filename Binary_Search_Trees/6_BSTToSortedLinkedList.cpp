#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"
#include "myLinkedlist.cpp"
using namespace std;

void preOrderPrint(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

/**
 *  BST to Sorted LL
 *  -   Given a BST, convert it into a sorted linked list. You have to
 *      return the head of LL.
 *
 *  Input format:
 *      The first and only line of input contains data of the nodes of the
 *      tree in level order form. The data of the nodes of the tree is separated
 *      by space. If any node does not have left or right child, take -1 in its
 *      place. Since -1 is used as an indication whether the left or right nodes
 *      exist, therefore, it will not be a part of the data of any node.
 *  Output Format:
 *      The first and only line of output prints the elements of sorted linked list.
 *
 *  Constraints:
 *
 *  Time Limit: 1 second
 *
 *  Sample Input 1:
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *  Sample Output 1:
 *      2 5 6 7 8 10
 */
class Pair
{
public:
    Node *head;
    Node *tail;

    Pair()
    {
        this->head = NULL;
        this->tail = NULL;
    }
};
Pair constructLL(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    if (root->left == NULL && root->right == NULL)
    {
        Node *node = new Node(root->data);
        Pair ans;
        ans.head = node;
        ans.tail = node;
        return ans;
    }
    Pair left = constructLL(root->left);
    Pair right = constructLL(root->right);
    Node *node = new Node(root->data);
    Pair ans;
    if (left.tail == NULL)
    {
        ans.head = node;
    }
    else
    {
        left.tail->next = node;
        ans.head = left.head;
    }
    node->next = right.head;
    if (right.head == NULL)
    {
        ans.tail = node;
    }
    else
    {
        ans.tail = right.tail;
    }
    return ans;
}
Node *constructLinkedList(BinaryTreeNode<int> *root)
{
    Pair ans = constructLL(root);
    return ans.head;
}

int main()
{
    BinaryTreeNode<int> *root = taktInputLevelorder();
    Node *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}