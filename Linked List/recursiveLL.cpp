#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int getLength(Node *head)
{
    if (head)
    {
        return getLength(head->next) + 1;
    }
    return 0;
}
Node *deleted(int position, Node *head)
{
    if (!head)
    {
        return head;
    }
    if (position == 0)
    {
         
        Node*temp=head->next;
        delete head;
        return temp;
    }
    else
    {
        Node *temp = deleted(position - 1, head->next);
        head->next = temp;
        return head;
    }
}
Node *insert(int data, int position, Node *head)
{
    if (!head)
    {
        return head;
    }
    if (position == 0)
    {
        Node *newNode= new Node(data);
        newNode->next=head;
        // head->next=newNode;
        return newNode;
    }
    else
    {
        Node* temp= insert(data, position - 1, head->next);
        head->next= temp;
        return head;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;
    Node *head = NULL;
    Node *temp2 = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        if (head == NULL)
        {
            head = newNode;
            temp2 = head;
        }
        else
        {
            temp2->next = newNode;
            temp2 = temp2->next;
        }
    }
    int position = 4;
    int data = 69;

    // cout<<getLength(head)<<endl;
    head = insert(data, position, head);
    temp2 = head;
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
    head = deleted(position, head);
    temp2 = head;
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;

    return 0;
}