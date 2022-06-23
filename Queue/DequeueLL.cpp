//Implementing a doubly-ended queue using linked lists
#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node* prev;
    Node* next;
};

template <typename T>
class DEqueue
{
    private:
    Node<T>* front;
    Node<T>* rear;
    public:
    DEqueue()
    {
        front = rear = NULL;
    }
    void insertFront(T);
    void insertRear(T);
    T deleteFront();
    T deleteRear();
    ~DEqueue();
    template <typename U>
    friend ostream& operator <<(ostream&, DEqueue<U>&);
};

template <typename T>
void DEqueue<T>::insertFront(T toInsert)
{
    Node<T>* newNode = new Node<T>;
    if(!newNode)
    {
        cout<<"Doubly-ended queue is full\n";
        return;
    }
    newNode->data = toInsert;
    newNode->next = newNode->prev = NULL;
    if(!front)
        front = rear = newNode;
    else
    {
        front->prev = newNode;
        newNode->next = front;
        front = front->prev;
    }
}

template <typename T>
void DEqueue<T>::insertRear(T toInsert)
{
    Node<T>* newNode = new Node<T>;
    if(!newNode)
    {
        cout<<"Doubly-ended queue is full\n";
        return;
    }
    newNode->data = toInsert;
    newNode->next = newNode->prev = NULL;
    if(!front)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = rear->next;
    }
}

template <typename T>
T DEqueue<T>::deleteFront()
{
    T var;
    if(!front)
    {
        cout<<"Doubly-ended queue is empty\n";
        return var;
    }
    Node<T>* ptr = front;
    front = front->next;
    front->prev = NULL;
    var = ptr->data;
    delete ptr;
    return var;
}

template <typename T>
T DEqueue<T>::deleteRear()
{
    T var;
    if(!front)
    {
        cout<<"Doubly-ended queue is empty\n";
        return var;
    }
    Node<T>* ptr = rear;
    rear = rear->prev;
    rear->next = NULL;
    var = ptr->data;
    delete ptr;
    return var;
}

template <typename T>
ostream& operator <<(ostream& out, DEqueue<T>& d)
{
    if(!d.front)
    {
        out<<"Doubly-ended queue is empty\n";
        return out;
    }
    out<<"Doubly ended queue elements:\n";
    Node<T>* ptr = d.front;
    while(ptr)
    {
        out<<ptr->data<<" ";
        ptr = ptr->next;
    }
    out<<"\nDoubly ended queue elements in reverse:\n";
    ptr = d.rear;
    while(ptr)
    {
        out<<ptr->data<<" ";
        ptr = ptr->prev;
    }
    out<<"\n";
    return out;
}

template <typename T>
DEqueue<T>::~DEqueue()
{
    Node<T>* ptr = front;
    while(front)
    {
        front = front->next;
        delete ptr;
        ptr = front;
    }
    cout<<"Doubly ended queue destructed\n";
}

int main()
{
    DEqueue<int> d;
    d.insertFront(40);
    d.insertFront(30);
    d.deleteFront();
    d.insertFront(20);
    d.deleteRear();
    d.insertFront(10);
    d.insertRear(50);
    d.insertRear(60);
    cout<<d;
    return 0;
}