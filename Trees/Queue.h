//Queue implemented using an array with two pointers
#include <iostream>
using namespace std;

template <typename T>
class QNode
{
    public:
    T data;
    QNode* next;
};

template <typename T>
class Queue
{
    private:
    QNode<T>* front;
    QNode<T>* rear;
    public:
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(T);
    T dequeue();
    bool isFull();
    bool isEmpty();
    T atFront();
    T atRear();
    ~Queue();
    template <typename U>
    friend ostream& operator <<(ostream&, Queue<U>&);
};

template <typename T>
bool Queue<T>::isEmpty()
{
    //front == rear won't work after emptying the list, so use front == NULL for checking emptiness
    if(!front) 
        return true;
    return false;
}

template <typename T>
bool Queue<T>::isFull()
{
    bool b = false;
    QNode<T>* newNode = new QNode<T>;
    if(!newNode)
        b = true;
    delete newNode;
    return b;
}

template <typename T>
void Queue<T>::enqueue(T toInsert)
{
    if(isFull())
    {
        cout<<"Cannot insert element since queue is full\n";
        return;
    }
    QNode<T>* newNode = new QNode<T>;
    newNode->data = toInsert;
    newNode->next = NULL;
    if(!front)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

template <typename T>
T Queue<T>::dequeue()
{
    T var;
    if(isEmpty())
        cout<<"Cannot delete element since queue is empty\n";
    else
    {
        QNode<T>* ptr = front;
        front = front->next;
        var = ptr->data;
        delete ptr;
    }
    return var;
}

template <typename T>
T Queue<T>::atFront()
{
    T var;
    if(isEmpty())
    {
        cout<<"Cannot return element since queue is empty\n";
        return var;
    }
    return front->data;
}

template <typename T>
T Queue<T>::atRear()
{
    T var;
    if(isEmpty())
    {
        cout<<"Cannot return element since queue is empty\n";
        return var;
    }
    return rear->data;
}

template <typename T>
Queue<T>::~Queue()
{
    QNode<T>* ptr = front;
    while(front)
    {
        front = front->next;
        delete ptr;
        ptr = front;
    }
    //cout<<"Queue object destructed\n";
}

template <typename T>
ostream& operator <<(ostream& out, Queue<T>& q)
{
    if(q.isEmpty())
        out<<"Cannot print elements since queue is empty\n";
    else
    {
        QNode<T>* ptr = q.front;
        while(ptr)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        out<<"\n";
    }
    return out;
}