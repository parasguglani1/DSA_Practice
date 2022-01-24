//Priority queue where lower the number, higher is its priority
#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node* next;
};

template <typename T>
class Priority
{
    private:
    Node<T>* front;
    public:
    Priority()
    {
        front = NULL;
    }
    void insert(T);
    T pop();
    ~Priority();
    template <typename U>
    friend ostream& operator <<(ostream&, Priority<U>&);
};

template <typename T>
void Priority<T>::insert(T toInsert)
{
    Node<T>* newNode = new Node<T>;
    if(!newNode)
    {
        cout<<"Priority queue is full\n";
        return;
    }
    newNode->data = toInsert;
    newNode->next = NULL;
    if(front == NULL)
        front = newNode;
    else
    {
        Node<T>* ptr = front;
        if(newNode->data <= front->data)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            while(ptr->next && ptr->next->data <= newNode->data)
                ptr = ptr->next;
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
}

template <typename T>
T Priority<T>::pop()
{
    T var;
    if(!front)
        cout<<"Priority queue is empty\n";
    else
    {
        Node<T>* ptr = front;
        front = front->next;
        var = ptr->data;
        delete ptr;
    }
    return var;
}

template <typename T>
Priority<T>::~Priority()
{
    Node<T>* ptr = front;
    while(front)
    {
        front = front->next;
        delete ptr;
        ptr = front;
    }
    cout<<"Priority queue destructed\n";
}

template <typename T>
ostream& operator <<(ostream& out, Priority<T>& p)
{
    if(!p.front)
        out<<"Priority queue is empty\n";
    else
    {
        Node<T>* ptr = p.front;
        while(ptr)
        {
            out<<ptr->data<<" ";
            ptr = ptr->next;
        }
        out<<"\n";
    }
    return out;
}

int main()
{
    Priority<char> p;
    for(int i = 122; i >= 112; i-=2)
        p.insert(i);
    for(int i = 65; i <= 75; i+=2)
        p.insert(i);
    cout<<p;
    for(int i = 1; i <= 5; i++)
        p.pop();
    cout<<p;
    return 0;
}