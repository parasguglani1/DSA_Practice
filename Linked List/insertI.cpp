#include <bits/stdc++.h>
using namespace std;
#include "myLinkedlist.cpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;
    Node *head = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    // insert at ith position
    int i = 5;
    temp = head;
    for (int j = 0; j < i - 1; j++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(69);
    newNode->next = temp->next;
    temp->next = newNode;

    // display
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    // delete at ith position
    i = 7;
    temp = head;
    for (int j = 0; j < i - 2; j++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    Node *n1 = new Node(10);
    Node n2(20);

    // since n2 is normal object - we can use . to access members.
    n2.next = head;
    // since n1 is pointer - we need to use lambda
    n1->next = &n2;

    return 0;
}