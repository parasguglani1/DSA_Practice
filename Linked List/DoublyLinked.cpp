//Doubly-linked list in C++
//Improved speeds for insertion and deletion implemented using tail pointer
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
class Double
{
    private:
    Node<T>* head;
    Node<T>* tail;
    public:
    Double(){head = tail = NULL;}
    Double(T*, int);
    void insertEnd(T);
    void insertGen(T, int);
    int countNodes();
    T* deleteNode(int);
    void reverse();
    template <typename U>
    friend ostream& operator <<(ostream&, Double<U>&);
    ~Double();
};

template <typename T>
Double<T>::Double(T* arr, int n)
{
    head = tail = NULL;
    for(int i = 0; i < n; i++)
        insertEnd(arr[i]);
}

template <typename T>
void Double<T>::insertEnd(T toInsert)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = toInsert;
    if(head == NULL)
    {
        newNode->prev = newNode->next = NULL;
        head = tail = newNode;
    }
    else
    {
       newNode->next = tail->next; //NULL
       newNode->prev = tail; 
       tail->next = newNode;
       tail = newNode;
    }
}

template <typename T>
int Double<T>::countNodes()
{
    Node<T>* ptr = head; //can traverse backwards using tail as well
    int len = 0;
    while(ptr)
    {
        ptr = ptr->next;
        len++;
    }
    return len;
}

template <typename T>
void Double<T>::insertGen(T toInsert, int pos)
{
    int length = countNodes();
    if(pos < 0 || pos > length)
    {
        cout<<"Invalid insertion position\n";
        return;
    }
    Node<T>* newNode = new Node<T>;
    newNode->data = toInsert;
    if(pos == 0)
    {
        if(head)
        {
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            newNode->prev = newNode->next = NULL;
            head = tail = newNode;
        }
    }
    else
    {
        if(pos == length)
        {
            newNode->prev = tail;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node<T>* ptr;
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
T* Double<T>::deleteNode(int pos)
{
    int length = countNodes();
    if(pos < 1 || pos > length)
    {
        cout<<"Invalid deletion position\n";
        return NULL;
    }
    T* var = new T;
    Node<T>* ptr;
    if(pos == 1)
    {
        ptr = head;
        head = ptr->next;
        if(head)
            head->prev = NULL;
        else
            tail = head;
    }
    else
    {
        if(pos == length)
        {
            ptr = tail;
            tail = tail->prev;
            tail->next = NULL;
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
void Double<T>::reverse()
{
    if(!head)
    {
        cout<<"List is empty\n";
        return;
    }
    if(countNodes() != 1)
    {
        Node<T>* ptr = head, *temp;
        tail = head;
        while(ptr)
        {
            if(!ptr->next)
                head = ptr;
            
            temp = ptr->next;
            ptr->next = ptr->prev;
            ptr->prev = temp;
            ptr = ptr->prev; //moves to the next node
        }
    }
}

template <typename T>
Double<T>::~Double()
{
    Node<T>* ptr = head;
    while(ptr)
    {
        //cout<<ptr->data<<" ";
        ptr = ptr->next;
        delete head;
        head = ptr;
    }
    cout<<"Circular linked list destructed\n";
}

template <typename T>
ostream& operator <<(ostream& out, Double<T>& list)
{
    Node<T>* ptr = list.head;
    out<<"Doubly-linked list elements:\n";
    while(ptr)
    {
        out<<ptr->data<<" ";
        ptr = ptr->next;
    }
    out<<"\n"<<"Doubly-linked list elements in reverse:\n";
    ptr = list.tail;
    while(ptr)
    {
        out<<ptr->data<<" ";
        ptr = ptr->prev;
    }
    out<<"\n";
    return out;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    Double<int> list;
    for(int i = 0; i < 5; i++)
        list.insertGen(arr[i], i);
    list.reverse();
    list.insertEnd(60);
    list.deleteNode(1);
    cout<<list;
    cout<<"Program terminated\n";
    return 0;
}