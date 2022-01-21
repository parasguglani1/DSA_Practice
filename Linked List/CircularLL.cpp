//Circular linked list in C++
#include <iostream>
using namespace std;

template <typename T>
class Circular
{
    private:
    class Node;
    Node* head;
    Node* tail;
    void Rdisplay(Node*, int);
    public:
    Circular()
    {
        head = tail = NULL;
    }
    Circular(T[], int);
    void insertEnd(T);
    void insertGen(T, int);
    void display();
    void recDisp();
    int countNodes();
    T* deleteNode(int);
    ~Circular();
};

template <typename T>
class Circular<T>::Node
{
    public:
    T data;
    Node* next;
};

template <typename T>
Circular<T>::Circular(T arr[], int n)
{
    head = tail = NULL;
    for(int i = 0; i < n; i++)
        insertEnd(arr[i]);
}

template <typename T>
void Circular<T>::insertEnd(T toInsert)
{//O(1) method
    Node* newNode = new Node;
    newNode->data = toInsert;
    if(!head)
    {
        head = tail = newNode;
        newNode->next = tail->next = head;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void Circular<T>::insertGen(T toInsert, int pos)
{
    if(pos < 0 || pos > countNodes())
    {
        cout<<"There are "<<countNodes()<<" nodes\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = toInsert;
    if(pos == 0)
    {
        if(!head)
        {
            head = tail = newNode;
            newNode->next = tail->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            head = newNode; //change the head
        }
    }
    else
    {
        if(pos == countNodes())
        {//O(1) if tail is to be changed
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node* ptr = head;
            for(int i = 1; i <= pos-1; i++)
                ptr = ptr->next;
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
}

template <typename T>
void Circular<T>::display()
{
    if(!head)
    {
        cout<<"List is empty\n";
        return;
    }
    cout<<"Circular linked list elements:\n";
    Node* ptr = head;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    } while (ptr != head);
    cout<<"\n";    
}

template <typename T>
void Circular<T>::Rdisplay(Node* ptr, int flag)
{
    if(ptr == head && flag == 1)
        return;
    cout<<ptr->data<<" ";
    Rdisplay(ptr->next, 1);
}

template <typename T>
void Circular<T>::recDisp()
{
    if(!head)
    {
        cout<<"List is empty\n";
        return;
    }
    cout<<"Circular linked list elements:\n";
    Rdisplay(head, 0);
    cout<<"\n";
}

template <typename T>
Circular<T>::~Circular()
{
    tail->next = NULL;
    Node* temp;
    while(head)
    {
        temp = head;
        //cout<<"Deleted "<<head->data<<"\n";
        head = head->next;
        delete temp;
    }
    cout<<"Object deleted\n";
}

template <typename T>
int Circular<T>::countNodes()
{
    if(!head)
        return 0;
    int len = 0;
    Node* t = head;
    while(t->next != head)
    {
        t = t->next;
        len++;
    }
    return ++len;    
}

template <typename T>
T* Circular<T>::deleteNode(int pos)
{
    if(pos < 1 || pos > countNodes())
    {
        cout<<"Invalid position for deletion\n";
        return NULL;
    }
    T* var = new T;
    if(pos == 1)
    {
        *var = head->data;
        if(countNodes() == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            tail->next = head->next;
            delete head;
            head = tail->next;
        }
    }
    else
    {
        Node* ptr = head, *q;
        for(int i = 1; i <= pos-2; i++)
            ptr = ptr->next;
        q = ptr->next; //to be deleted
        ptr->next = q->next;
        *var = q->data;
        delete q;
        if(q == tail) //gets deleted and must be reinitialized
            tail = ptr;
    }
    return var;
}

int main()
{
    int n, ind;
    while(true)
    {
        cout<<"Enter the number of elements: ";
        cin>>n;
        if(n > 0)
        {
            cout<<"Enter the elements: ";
            break;
        }
        cout<<"Invalid entry, retry with a positive input\n";
    }
    int arr[n]; Circular<int> list;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    for(int i = 0; i < n; i++)
        list.insertGen(arr[i], i);
    list.recDisp();
    while(true)
    {
        cout<<"Enter an index to delete an element: ";
        cin>>ind;
        if(ind >= 0 && ind <= list.countNodes())
        break;
        cout<<"Invalid index, retry with a number between 0 and "<<list.countNodes()<<"\n";
    }
    int* ans = list.deleteNode(ind);
    if(ans)
    {
        cout<<"Deleted element: "<<*ans<<"\n";
        delete ans;
    }
    list.display();
    return 0;
}