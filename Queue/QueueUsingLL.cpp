#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data);
};

Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
}
class QueueUsingLL
{
private:
    Node *head;
    Node *tail;
    int size = 0;

public:
    QueueUsingLL();
    void enqueue(int data);
    int dequeue();
    int getSize();
    bool isEmpty();
    int front();
};

QueueUsingLL::QueueUsingLL()
{
    Node *head = NULL;
    Node *tail = NULL;
}

void QueueUsingLL::enqueue(int data)
{
    Node *newnode = new Node(data);
    size++;

    if (!head)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = tail->next;
}

bool QueueUsingLL::isEmpty()
{
    return !size;
}
int QueueUsingLL::dequeue()
{
    if (isEmpty())
    {
        cout << "queue is empty";
        return -1;
    }
    size--;
    Node *temp = head;
    int removed = temp->data;
    head = head->next;
    delete temp;
    temp = NULL;
    return removed;
}
int QueueUsingLL::getSize()
{
    return size;
}

int QueueUsingLL::front()
{
    return head->data;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "hello world" << endl;
    QueueUsingLL Q;
    Q.enqueue(10);
    // cout << Q.front() << endl;

    Q.enqueue(20);
    // cout << Q.front() << endl;
    Q.enqueue(30);
    // cout << Q.front() << endl;

    Q.enqueue(40);
    cout << Q.getSize() << endl;
    cout << Q.front() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.front() << endl;
    cout << Q.dequeue() << endl;

    cout << Q.front() << endl;

    cout << Q.dequeue();
    cout << Q.dequeue();
    cout << Q.isEmpty();
    return 0;
}