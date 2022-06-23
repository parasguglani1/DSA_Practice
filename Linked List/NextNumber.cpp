#include <bits/stdc++.h>
#include "myLinkedlist.cpp"
using namespace std;

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

Node *reverse(Node *head)
{
    Node *previous = NULL;
    Node *next = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = previous;
        previous = curr;
        curr = next;
    }
    return previous;
}
Node *NextLargeNumber(Node *head)
{
    Node *reverseNumber = reverse(head);
    Node *curr = reverseNumber;
    Node *previous = NULL;
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
        Node *newNode = new Node(carry);
        previous->next = newNode;
    }
    return reverse(reverseNumber);
}

int main()
{
    Node *head = inputTillNegativeOne();
    head = NextLargeNumber(head);
    print(head);
}