#include <bits/stdc++.h>
using namespace std;
// From improving searching in linked list there are two methods, first one is transposition and second one is move to header

// In Linked List, we avoid movement of data, thus tranposition is not suitable.
// We prefer movement of nodes, there we will use the second method to improve searching in linked list, i.e. move to head.
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void createLinkedlist(int A[], int n)
{
    int i;
    struct Node *t;
    struct Node *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

struct Node *searchElement(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(A) / sizeof(A[0]);
    createLinkedlist(A, n);
    cout << searchElement(first, 8);
    return 0;
}