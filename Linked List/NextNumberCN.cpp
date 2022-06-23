#include <bits/stdc++.h>
// #include "myLinkedlist.cpp"
using namespace std;
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};
/**
 *  Next Number
 *  -   Given a large number represented in the form of a linked list.
 *      Write code to increment the number by 1 in-place(i.e. without
 *      using extra space).
 *
 *  Input format :
 *      Line 1 : Linked list elements (separated by space and terminated by -1)
 *  Output Format :
 *      Line 1: Updated linked list elements
 *
 *  Sample Input 1 :
 *      3 9 2 5 -1
 *  Sample Output 1 :
 *      3 9 2 6
 *
 *  Sample Input 2 :
 *      9 9 9 -1
 *  Sample Output 1 :
 *      1 0 0 0
 */

LinkedListNode<int> *inputTillNegativeOne()
{
    int data;
    cin >> data;
    LinkedListNode<int> *head = NULL;
    LinkedListNode<int> *tail = NULL;

    while (data != -1)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *previous = NULL;
    LinkedListNode<int> *next = NULL;
    LinkedListNode<int> *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = previous;
        previous = curr;
        curr = next;
    }
    return previous;
}
LinkedListNode<int> *addOneToList(LinkedListNode<int> *head)
{ /*
        Declare a local node pointer variable ‘end’
        which will hold the last node of the list i.e. ‘-1’
        and we will remove this node from the list for the time being.
    */
    LinkedListNode<int> *end = NULL;
    LinkedListNode<int> *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    end = temp->next;
    temp->next = NULL;
    LinkedListNode<int> *reverseNumber = reverse(head);
    LinkedListNode<int> *curr = reverseNumber;
    LinkedListNode<int> *previous = NULL;
    int carry = 1;
    while (curr != NULL && carry)
    {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;
        previous = curr;
        curr = curr->next;
    }
    if (carry > 0)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(carry);
        previous->next = newNode;
    }
    head = reverse(reverseNumber);
    temp = head;

    // Add ‘end’ at the of the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = end;

    // Return head
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LinkedListNode<int> *head = inputTillNegativeOne();
        head = addOneToList(head);
        print(head);
    }
}