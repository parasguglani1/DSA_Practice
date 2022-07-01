#include <bits/stdc++.h>
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

Node *inputTillNegativeOne()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
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
Node *appendLastNToFirst(Node *head, int N)
{
    Node *temp = head;
    Node *second = head;
    int count = 0;
    int total = 0;

    while (temp)
    {
        second = temp;
        temp = temp->next;
        total++;
    }
    // cout << total << endl;
    second->next = head;
    int stop = total - N - 1;
    // cout << stop << endl;
    // cout << second->data << endl;
    temp = head;
    int i = 0;
    while (i < stop)
    {
        temp = temp->next;
        i++;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}

void removeDuplicateFromLL(Node *head)
{
    Node *tail = NULL;
    Node *temp = NULL;
    temp = head;
    Node *temp2 = NULL;
    while (temp && temp->next)
    {
        // cout << "hello 1" << endl;
        // cout << temp->data;
        // cout << endl;
        // cout << temp->next->data;
        // break;

        if ((temp->data) == (temp->next->data))
        {
            temp2 = temp->next;
            temp->next = temp->next->next;
            // cout << "hello2";
            // break;

            delete temp2;
        }
        else
        {
            temp = temp->next;
        }
    }
}
Node *removeDuplicatesR(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *ans = removeDuplicatesR(head->next);
    if (head->data == ans->data)
    {
        return ans;
    }
    head->next = ans;
    return head;
}

int getLength(Node *head)

{

    Node *temp = head;
    int size = 0;
    temp = head;

    while (temp)
    {
        // cout << temp->data << " ";
        temp = temp->next;
        size++;
    }
    return size;
}
int RgetLength(Node *head)
{
    if (head)
    {
        return RgetLength(head->next) + 1;
    }
    return 0;
}

Node *getmidPoint(Node *head)
{
    int size = getLength(head);

    Node *temp = head;
    int mid;
    if (size % 2 == 0)
    {
        mid = size / 2;
    }
    else
    {
        mid = size / 2 + 1;
    }

    int i = 1;
    while (temp && i < mid)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}
void printReverseR(Node *head)
{
    if (head == NULL)
    {
        cout << "";
        return;
    }
    printReverseR(head->next);
    cout << head->data << " ";
}

Node *reverseIterative(Node *head)
{
    Node *temp = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;
    // head=NULL;

    first = head;
    if (head)
    {
        second = head->next;
    }
    if (second)
    {
        third = head->next->next;
    }
    if (first)
        first->next = NULL;
    int count = 0;
    while (third)
    {
        // cout << first->data << " ";
        // cout << second->data << " ";
        // cout << third->data << " ";
        // cout << endl;
        // 1 2 3 4 5
        second->next = first;
        if (!count)
        {
            first->next = NULL;
            count++;
        }
        first = second;
        second = third;
        third = third->next;
        // cout << first->data << " ";
        // cout << second->data << " ";
        // cout << third->data << " ";
        // break;
        // cout << endl;
    }
    if (second)
    {
        second->next = first;
        head = second;
        return head;
    }
    // single node case
    return first;
}

// shorter
Node *reverseLinkedListIterative(Node *head)
{
    Node *previous = NULL;
    Node *next = NULL;
    Node *current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
//====Approach 1 - Recursion - O(n^2)=======
Node *rReverseN2(Node *head)
{
    if (head && head->next)
    {
        Node *smallAns = rReverseN2(head->next);
        Node *temp = smallAns;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;
        head->next = NULL;
        return smallAns;
    }

    return head;
}

//====Approach 2 - Recursion Using Pair Class - O(n)=======
// pair<Node*,Node*>
// first is head second is tail
pair<Node *, Node *> rReverse(Node *head)
{
    if (head && head->next)
    {
        pair<Node *, Node *>
            smallAns = rReverse(head->next);
        smallAns.second->next = head;
        head->next = NULL;
        // Node *temp = smallAns;
        // while (temp->next)
        // {
        //     temp = temp->next;
        // }
        // temp->next = head;
        // head->next = NULL;
        // return smallAns;
        pair<Node *, Node *> ans;
        ans.first = smallAns.first;
        ans.second = head;
        return ans;
    }
    pair<Node *, Node *> ans;
    ans.first = head;
    ans.second = head;

    return ans;
}
//====Approach 3 - Recursion - O(n)=======
Node *rReverse2(Node *head)
{
    return rReverse(head).first;
}

Node *rReverseN(Node *head)
{
    if (head && head->next)
    {
        Node *smallAns = rReverseN(head->next);
        Node *tail = head->next;

        tail->next = head;
        head->next = NULL;
        return smallAns;
    }

    return head;
}
bool isEqual(Node *head1, Node *head2)
{
    Node *temp = head1;
    Node *temp2 = head2;
    bool flag = true;
    while (temp && temp2)
    {
        if (!temp || !temp2)
        {
            flag = true;
            break;
        }
        if (temp->data != temp2->data)
        {
            // cout << temp->data << " " << temp2->data;
            flag = false;
            break;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    return flag;
}
bool ispalindrome(Node *head)
{
    Node *temp = head;
    Node *mid = getmidPoint(head);
    // break from middle
    Node *head2 = NULL;
    if (temp)
    {
        head2 = temp->next;
        temp->next = NULL;
    }
    // reverse second list
    head2 = reverseIterative(head2);
    // compare linked lists
    bool flag = isEqual(head, head2);

    return flag;
}
Node *mergeUsingExtraSpace(Node *head1, Node *head2)
{
    Node *tail = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *head3 = NULL;

    // temp = head;

    Node *newNode = new Node;

    if (temp1->data <= temp2->data)
    {
        newNode->data = temp1->data;

        temp1 = temp1->next;
    }
    else
    {
        newNode->data = temp2->data;
        temp2 = temp2->next;
    }
    head3 = newNode;
    tail = newNode;

    while (temp1 && temp2)
    {

        Node *newNode = new Node;
        if (temp1->data <= temp2->data)
        {
            newNode->data = temp1->data;
            temp1 = temp1->next;
        }
        else
        {
            newNode->data = temp2->data;
            temp2 = temp2->next;
        }
        tail->next = newNode;
        tail = newNode;
    }
    while (temp1)
    {

        Node *newNode = new Node;
        newNode->data = temp1->data;
        temp1 = temp1->next;
        tail->next = newNode;
        tail = newNode;
    }
    while (temp2)
    {

        Node *newNode = new Node;
        newNode->data = temp2->data;
        temp2 = temp2->next;
        tail->next = newNode;
        tail = newNode;
    }
    return head3;
}

Node *mergeWithoutExtraSpace(Node *head1, Node *head2)
{
    Node *tail = NULL;
    Node *current1 = head1;
    Node *current2 = head2;
    if (current1->data < current2->data)
    {
        head1 = current1;
        tail = current1;
        current1 = current1->next;
    }
    else
    {
        head1 = current2;
        tail = current2;
        current2 = current2->next;
    }
    while (current1 && current2)
    {
        if (current1->data < current2->data)
        {
            tail->next = current1;
            current1 = current1->next;
        }
        else
        {
            tail->next = current2;
            current2 = current2->next;
        }
        tail = tail->next;
    }
    if (current1)
    {
        tail->next = current1;
        // current1 = current1->next;
    }
    if (current2)
    {
        tail->next = current2;
        // current2 = current2->next;
    }
    return head1;
}

// similar code
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *result = new Node(0);
    Node *curr = result;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if (head1 != NULL)
    {
        curr->next = head1;
    }
    else
    {
        curr->next = head2;
    }
    Node *newHead = result->next;
    delete result;
    return newHead;
}

int searchInLL(Node *head, int key)
{
    Node *temp = head;
    int index = 0;
    bool flag = false;
    while (temp)
    {
        if (temp->data == key)
        {

            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
int searchInLLR(Node *head, int key)
{
    if (!head)
    {
        return -1;
    }
    if (head->data == key)
    {
        return 0;
    }
    int index = searchInLLR(head->next, key);
    if (index == -1)
        return -1;
    return index + 1;
}

// delete pos node
Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    if (head == NULL)
        return NULL;
    if (pos == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    int i = 0;
    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL && temp->next != NULL)
    {
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    return head;
}

Node *Rdelete(int position, Node *head)
{
    if (!head)
    {
        return head;
    }
    if (position == 0)
    {

        Node *temp = head->next;
        delete head;
        return temp;
    }
    else
    {
        Node *temp = Rdelete(position - 1, head->next);
        head->next = temp;
        return head;
    }
}
Node *Rinsert(int data, int position, Node *head)
{
    if (!head)
    {
        return head;
    }
    if (position == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    else
    {
        Node *temp = Rinsert(data, position - 1, head->next);
        head->next = temp;
        return head;
    }
}
// using two pointers
Node *getMiddleTwoPointer(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *previous = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return previous;
}

Node *mergesort(Node *head1)
{
    if (head1 && head1->next)
    {
        Node *head2 = NULL;
        Node *mid = getMiddleTwoPointer(head1);
        if (mid)
        {
            head2 = mid->next;
            mid->next = NULL;
        }
        head1 = mergesort(head1);
        head2 = mergesort(head2);
        head1 = mergeWithoutExtraSpace(head1, head2);
        // head1 = head1->next;
        return head1;
    }
    return head1;
}

void printIthNode(Node *head, int i)
{
    Node *temp = head;
    int idx = 0;
    while (temp != NULL && idx < i)
    {
        temp = temp->next;
        idx++;
    }
    if (temp != NULL)
    {
        cout << temp->data << endl;
    }
}
