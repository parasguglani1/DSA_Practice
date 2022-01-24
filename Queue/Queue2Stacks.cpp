//Implementing a queue using two stacks (implemented using linked list)
#include "Stacks.h"

template <typename T>
class Queue
{
    private:
    Stack<T> s1;
    Stack<T> s2;
    public:
    Queue(){}
    void enqueue(T);
    T dequeue();
    bool isEmpty();
    ~Queue()
    {
        s1.~Stack(); 
        s2.~Stack();
        cout<<"Queue object destructed\n";
    }
    template <typename U>
    friend ostream& operator <<(ostream&, Queue<U>&);
};

template <typename T>
bool Queue<T>::isEmpty()
{
    if(s1.isEmpty() && s2.isEmpty())
        return true;
    return false;
}

template <typename T>
void Queue<T>::enqueue(T toInsert)
{
    if(!s1.isFull())
        s1.push(toInsert);
    else
        cout<<"Cannot enqueue element because queue is full\n";
}

template <typename T>
T Queue<T>::dequeue()
{
    T var;
    if(isEmpty())
        cout<<"Cannot dequeue because queue is empty\n";
    else if(s2.isEmpty())
    {
        while(!s1.isEmpty())
            s2.push(s1.pop());
        var = s2.pop();
    }
    else //s2 is not empty
        var = s2.pop();
    return var;
}

template <typename T>
ostream& operator <<(ostream& out, Queue<T>& q)
{
    if(q.isEmpty())
        out<<"Cannot display elements because queue is empty\n";
    else
    {
        cout<<"Queue elements are:\n";
        while(!q.s1.isEmpty())
            q.s2.push(q.s1.pop());
        out<<q.s2;
    }
    return out;
}

int main()
{
    Queue<string> q;
    q.enqueue("Raghuram Rajan was fantastic");
    q.enqueue("What's wrong with our economy?");
    q.enqueue("Sab changa si");
    cout<<q;
    for(int i = 1; i <= 2; i++)
        cout<<q.dequeue()<<"\n";
    return 0;
}