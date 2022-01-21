//CIrcular doubly-linked list in C++
//With efficient insertion and deletion with usage of pointer to tail
#include <iostream>
using namespace std;

template <typename T>
class CircularDouble
{
    private:
    class Node;
    Node* head;
    Node* tail;
    public:
    CircularDouble(){head = tail = NULL;}
    CircularDouble(T*, int);
    void insert(T, int);
    void display();
    T* deleteNode(int);
    int countNodes();
    ~CircularDouble();
};

template <typename T>
class CircularDouble<T>::Node
{
    public:
    T data;
    Node* prev;
    Node* next;
};

template <typename T>
int CircularDouble<T>::countNodes()
{
    if(!head)
        return 0;
    int len = 0;
    Node* ptr = head;
    do 
    {
        ptr = ptr->next;
        len++;
    }while(ptr != head);
    return len;
}

template <typename T>
void CircularDouble<T>::insert(T toInsert, int pos)
{
    int length = countNodes();
    if(pos < 0 || pos > length)
    {
        cout<<"Invalid inserrtion index\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = toInsert;
    if(pos == 0)
    {
        if(head == NULL)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            newNode->prev = tail;
            head->prev = newNode;
            head = newNode;
        }
    }
    else
    {
        if(pos == length)
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
        else
        {
            Node* ptr;
            if(pos <= length/2)
            {
                ptr = head;
                for(int i = 1; i <= pos-1; i++)
                    ptr = ptr->next;
                newNode->next = ptr->next;
                newNode->prev = ptr;
                ptr->next->prev = newNode;
                ptr->next = newNode;
            }
            else
            {
                ptr = tail;
                for(int i = 1; i <= length-pos-1; i++)
                    ptr = ptr->prev;
                newNode->next = ptr;
                newNode->prev = ptr->prev;
                ptr->prev->next = newNode;
                ptr->prev = newNode;
            }
        }
    }
}

template <typename T>
void CircularDouble<T>::display()
{
    if(!head)
    {
        cout<<"List is empty\n";
        return;
    }
    cout<<"Circular doubly-linked list elements:\n";
    Node* ptr = head;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }while(ptr != head);
    cout<<"\nCircular doubly-linked list elements in reverse:\n";
    ptr = tail;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->prev;
    }while(ptr != tail);
    cout<<"\n";
}

template <typename T>
CircularDouble<T>::CircularDouble(T* arr, int n):CircularDouble()
{
    for(int i = 0; i < n; i++)
        insert(arr[i], i);
}

template <typename T>
T* CircularDouble<T>::deleteNode(int pos)
{
    int length = countNodes();
    if(pos < 1 || pos > length)
    {
        cout<<"Invalid deletion position\n";
        return NULL;
    }
    T* var = new T;
    Node* ptr;
    if(pos == 1)
    {
        ptr = head;
        if(length != 1)
        {
            head = ptr->next;
            head->prev = tail;
            tail->next = head;
        }
        else
            head = tail = NULL;
    }
    else
    {
        if(pos == length)
        {
            ptr = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        else
        {
            if(pos <= length/2)
            {
                ptr = head;
                for(int i = 1; i <= pos-1; i++)
                    ptr = ptr->next;
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            else
            {
                ptr = tail;
                for(int i = 1; i <= length-pos; i++)
                    ptr = ptr->prev;
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
        }
    }
    *var = ptr->data;
    delete ptr;
    return var;
}

template <typename T>
CircularDouble<T>::~CircularDouble()
{
    tail->next = head->prev = NULL;
    Node* ptr = head;
    while(ptr)
    {
        //cout<<ptr->data<<" ";
        head = head->next;
        delete ptr;
        ptr = head;
    }
    cout<<"Circular doubly-linked list destructed\n";
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    CircularDouble<int> list(arr, 5);
    list.insert(35, 3);
    int* del = list.deleteNode(3);
    if(del)
    {
        cout<<"Deleted node with element "<<*del<<"\n";
        delete del;
    }
    cout<<"Number of nodes: "<<list.countNodes()<<"\n";
    list.display();
    return 0;
}