//Implementing stacks using a linked list
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
class Stack
{
    private:
    Node<T>* top;
    int len;
    public:
    Stack()
    {
        top = NULL;
        len = 0;
    }
    void push(T);
    T pop();
    T peek(int);
    T stackTop();
    bool isEmpty();
    bool isFull();
    int getLength(){return len;}
    ~Stack();
    template <typename U>
    friend ostream& operator <<(ostream&, Stack<U>&);
};

template <typename T>
void Stack<T>::push(T toInsert)
{
    if(isFull())
    {
        cout<<"Cannot insert, Stack Overflow\n";
        return;
    }
    Node<T>* newNode = new Node<T>;
    newNode->data = toInsert;
    newNode->next = top;
    top = newNode;
    len++;
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
    Node<T>* ptr = top;
    top = top->next;
    T toRet = ptr->data;
    delete ptr;
    len--;
    return toRet;
}

template <typename T>
T Stack<T>::peek(int index)
{
    T var;
    if(index == 1)
        return stackTop();
    if(index > 0)
    {
        Node<T>* ptr = top;
        for(int i = 1; i <= index-1 && ptr; i++)
            ptr = ptr->next;
        if(ptr)
            return ptr->data;
        else
        {
            cout<<"Invalidly large index\n";
            return var; //some junk
        }
    }
    else
    {
        cout<<"Invalidly small index\n";
        return var; //some junk
    }
}

template <typename T>
T Stack<T>::stackTop()
{
    T var;
    if(!isEmpty())
        return top->data;
    return var; //some junk
}

template <typename T>
bool Stack<T>::isFull()
{
    bool b;
    Node<T>* t = new Node<T>;
    if(t == NULL)
        b = true;
    else 
        b = false;
    delete t;
    return b;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if(top == NULL)
        return true;
    return false;
}

template <typename T>
Stack<T>::~Stack()
{
    Node<T>* ptr;
    while(top)
    {
        ptr = top;
        top = top->next;
        delete ptr;
    }
    //cout<<"Stack object destructed\n";
}

template <typename T>
ostream& operator <<(ostream& out, Stack<T>& st)
{
    Node<T>* ptr = st.top;
    while(ptr)
    {
        out<<ptr->data<<" ";
        ptr = ptr->next;
    }
    return out;
}