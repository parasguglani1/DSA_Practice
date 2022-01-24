#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    private:
    T* stack;
    int top;
    int size;
    public:
    Stack()
    {
        stack = NULL;
        top = size = 0;
    }
    Stack(int);
    void push(T);
    T pop();
    T peek(int);
    T stackTop();
    bool isEmpty();
    bool isFull();
    int getTop();
    ~Stack();
};

template <typename T>
Stack<T>::Stack(int maxSize)
{
    if(maxSize > 0)
        size = maxSize;
    else
    {
        size = 10;
        cout<<"Default size set due to invalid entry\n";
    }
    stack = new T[size];
    top = -1;
}

template <typename T>
void Stack<T>::push(T toInsert)
{
    if(top == size) //cannot use isFull() otherwise we would fill only size-1 elements
    {
        cout<<"Cannot insert element due to overflow\n";
        return;
    }
    stack[++top] = toInsert;
}

template <typename T>
T Stack<T>::pop()
{
    T var;
    if(isEmpty())
    {
        cout<<"Cannot pop due to underflow\n";
        return var; //some junk
    }
    return stack[top--];
}

template <typename T>
T Stack<T>::peek(int index)
{
    T var;
    if(index == 1)
        return stackTop();
    if(top - index + 1 >= 0)
        return stack[top - index + 1];
    else
        return var; //some junk
}

template <typename T>
T Stack<T>::stackTop()
{
    T var;
    if(!isEmpty())
        return stack[top];
    return var; //some junk
}

template <typename T>
bool Stack<T>::isFull()
{
    if(top == size-1)
        return true;
    return false;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

template <typename T>
int Stack<T>::getTop()
{
    return top;
}

template <typename T>
Stack<T>::~Stack()
{
    size = top = 0;
    /*
    cout<<"Stack contents at the end: ";
    while(top > -1)
        cout<<stack[top--]<<" ";*/
    delete []stack;
    cout<<"Stack object destroyed\n";
}

int initializer()
{
    int var;
    while(true)
    {
        cout<<"Enter the maximum size of the stack: ";
        cin>>var;
        if(var > 0)
            break;
        cout<<"Invalid input, retry with a positive number\n";
    }
    return var;
}