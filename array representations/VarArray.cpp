//To implement a variable-sized array
#include <iostream>
using namespace std;

template <class T>
class varArr
{
    private:
    T* p;
    T* q;
    int size;
    public:
    varArr(int size = 1)
    {
        Size(size);
        p = new T[size];
    }
    bool Size(int);
    void changeSize(int);
    friend ostream& operator <<(ostream& out, varArr& v)
    {
        for(int i = 0; i < v.size; i++)
            out<<*(v.p+i)<<" ";
        out<<"\n";
        return out;
    }
    friend istream& operator >>(istream& in, varArr& v)
    {
        for(int i = 0; i < v.size; i++)
            in>>*(v.p+i);
        return in;
    }
    ~varArr();
};

template <class T>
bool varArr<T>::Size(int size)
{
    if(size < 1)
        return false;
    else
    {
        this->size = size;
        return true;
    }
}

template <class T>
void varArr<T>::changeSize(int newSize)
{
    q = new T[newSize];
    if(newSize >= size)
    {
        for(int i = 0; i < size; i++)
            q[i] = p[i];
        if(newSize > size)
        {
            cout<<"Enter "<<newSize - size<<" more elements: \n";
            for(int i = size; i < newSize; i++)
                cin>>q[i];
        }
    }
    else
    {
        cout<<"Extra elements deleted\n";
        for(int i = 0; i < newSize; i++)
            q[i] = p[i];
    }
    delete []p;
    p = q;
    q = nullptr;
    Size(newSize);    
}

template <class T>
varArr<T>::~varArr()
{
    delete []p;
    //cout<<"Array destructed\n";
}

template <class T>
void inputSize(int& size, string s, varArr<T>& v)
{
    while(true)
    {
        cout<<"Enter the "<<s<<"size of the array: ";
        cin>>size;
        if(size >= 1)
            break;
        cout<<"Invalid entry, try with a positive number\n";
    }
    if(s == "new")
        v.changeSize(size);
}

int main()
{
    int size; varArr<int> temp(1); //for the call only
    inputSize(size, "", temp);
    varArr<string> v(size); 

    cout<<"Enter the array elements:\n";
    cin>>v;

    cout<<"Array elements are:\n"<<v;

    inputSize(size, "new ", v);

    cout<<"Array elements are:\n"<<v;
    v.~varArr(); temp.~varArr();

    cout<<"Program terminated\n";
    return 0;
}
