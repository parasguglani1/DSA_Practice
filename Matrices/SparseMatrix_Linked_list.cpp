//Sparse matrices using linked lists
#include <iostream>
using namespace std;

class Node
{
    public:
    int col;
    int data;
    struct Node* next;
};

class Sparse
{
    private:
    Node** arr;
    int rows;
    int cols;
    public:
    Sparse()
    {
        arr = NULL;
        rows = cols = 0;
    }
    Sparse(int, int);
    void create();
    Sparse* operator +(Sparse&);
    friend ostream& operator <<(ostream&, Sparse&);
    ~Sparse();
};

Sparse::Sparse(int m, int n):Sparse()
{
    if(m > 0)
        cols = n;
    if(n > 0)
        rows = m;
    arr = new Node*[rows];
    for(int i = 0; i < rows; i++)
        arr[i] = NULL;
    create();
}

void Sparse::create()
{
    int ele;
    cout<<"Enter the matrix elements:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin>>ele;
            if(ele != 0)
            {
                if(!arr[i])
                {
                    arr[i] = new Node;
                    arr[i]->col = j;
                    arr[i]->data = ele;
                    arr[i]->next = NULL;
                }
                else
                {
                    Node* ptr = arr[i];
                    while(ptr->next)
                        ptr = ptr->next;
                    Node* newNode = new Node;
                    newNode->col = j;
                    newNode->data = ele;
                    newNode->next = NULL;
                    ptr->next = newNode;
                }
            }
        }
    }
}

ostream& operator <<(ostream& out, Sparse& sp)
{
    out<<"Sparse matrix elements are:\n";
    for(int i = 0; i < sp.rows; i++)
    {
        Node* ptr = sp.arr[i];
        for(int j = 0; j < sp.cols; j++)
        {
            if(ptr && ptr->col == j)
            {
                out<<ptr->data<<" ";
                ptr = ptr->next;
            }
            else
                out<<0<<" ";
        }
        out<<"\n";
    }
    return out;
}

Sparse* Sparse::operator +(Sparse& s)
{
    if(s.rows != this->rows || s.cols != this->cols)
    {
        cout<<"Matrices are incompatible for addition\n";
        return NULL;
    }
    Node* ptr1, *ptr2, *ptr3;
    Sparse* ans = new Sparse;
    ans->rows = this->rows; ans->cols = this->cols;
    ans->arr = new Node*[ans->rows];
    for(int i = 0; i < ans->rows; i++)
        ans->arr[i] = NULL;
    
    for(int i = 0; i < ans->rows; i++)
    {
        ptr1 = this->arr[i]; ptr2 = s.arr[i]; ptr3 = ans->arr[i];
        while(ptr1 && ptr2)
        {
            if(!ptr3)
            {
                ans->arr[i] = new Node;
                ptr3 = ans->arr[i];
            }
            else
            {
                ptr3->next = new Node;
                ptr3 = ptr3->next;
            }

            if(ptr1->col < ptr2->col)
            {
                ptr3->col = ptr1->col;
                ptr3->data = ptr1->data;
                ptr3->next = NULL;
                ptr1 = ptr1->next;
            }
            else if(ptr2->col < ptr1->col)
            {
                ptr3->col = ptr2->col;
                ptr3->data = ptr2->data;
                ptr3->next = NULL;
                ptr2 = ptr2->next;
            }
            else
            {
                ptr3->col = ptr1->col;
                ptr3->data = ptr1->data + ptr2->data;
                ptr3->next = NULL;
                ptr1 = ptr1->next; ptr2 = ptr2->next;
            }
        }

        while(ptr1)
        {
            if(!ans->arr[i])
            {
                ans->arr[i] = new Node;
                ptr3 = ans->arr[i];
            }
            else
            {
                ptr3->next = new Node;
                ptr3 = ptr3->next;
            }
            ptr3->col = ptr1->col;
            ptr3->data = ptr1->data;
            ptr3->next = NULL;
            ptr1 = ptr1->next;
        }
        while(ptr2)
        {
            if(!ptr3)
            {
                ans->arr[i] = new Node;
                ptr3 = ans->arr[i];
            }
            else
            {
                ptr3->next = new Node;
                ptr3 = ptr3->next;
            }
            ptr3->col = ptr2->col;
            ptr3->data = ptr2->data;
            ptr3->next = NULL;
            ptr2 = ptr2->next;
        }
    }
    return ans;
}

Sparse::~Sparse()
{
    Node* ptr, *temp;
    for(int i = 0; i < rows; i++)
    {
        ptr = arr[i];
        while(ptr)
        {
            temp = ptr;
            ptr = ptr->next;
            //cout<<temp->data<<" ";
            delete temp;
        }
        arr[i] = NULL;
        //cout<<"\n";
    }
    delete []arr;
    cout<<"Sparse matrix object destructed\n";
}

int inputter(string s)
{
    int x;
    while(true)
    {
        cout<<"Enter the number of "<<s<<": ";
        cin>>x;
        if(x > 0)
            break;
        cout<<"Invalid input, retry with a positive input\n";
    }
    return x;
}

int main()
{
    int m1 = inputter("rows");
    int n1 = inputter("columns");
    Sparse matrix1(m1, n1);
    cout<<matrix1;

    int m2 = inputter("rows");
    int n2 = inputter("columns");
    Sparse matrix2(m2, n2);
    cout<<matrix2;

    Sparse* matrix3 = matrix1 + matrix2;
    if(matrix3)
    {
        cout<<*matrix3;
        delete matrix3;
    }
    
    return 0;
}