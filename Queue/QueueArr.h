//Queue implemented using an array with two pointers
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    private:
    T* Q;
    int front;
    int rear;
    int size;
    public:
    Queue()
    {
        Q = NULL;
        front = rear = -1;
        size = 10; //default size
    }
    Queue(int);
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
Queue<T>::Queue(int size):Queue()
{
    if(size > 0)
        this->size = size;
    Q = new T[this->size];
}

template <typename T>
bool Queue<T>::isEmpty()
{
    if(front == rear)
        return true;
    return false;
}

template <typename T>
bool Queue<T>::isFull()
{
    if(rear == size-1)
        return true;
    return false;
}

template <typename T>
void Queue<T>::enqueue(T toInsert)
{
    if(isFull())
    {
        cout<<"Cannot insert element since queue is full\n";
        return;
    }
    Q[++rear] = toInsert;
}

template <typename T>
T Queue<T>::dequeue()
{
    T var;
    if(isEmpty())
    {
        cout<<"Cannot delete element since queue is empty\n";
        return var;
    }
    return Q[++front];
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
    return Q[front+1];
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
    return Q[rear];
}

template <typename T>
Queue<T>::~Queue()
{
    front = rear = size = 0;
    delete []Q;
    cout<<"Queue object destructed\n";
}

template <typename T>
ostream& operator <<(ostream& out, Queue<T>& q)
{
    if(q.isEmpty())
        out<<"Cannot print elements since queue is empty\n";
    else
    {
        for(int i = q.front+1; i <= q.rear; i++)
            out<<q.Q[i]<<" ";
        out<<"\n";
    }
    return out;
}