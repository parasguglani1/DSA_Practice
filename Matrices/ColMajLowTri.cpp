//Column-major implementation of lower triangular matrix in C++
#include <iostream>
using namespace std;

class LowTri
{
    private:
        int* arr;
        int n; //max size
        int len; //filled
    public:
    LowTri(int n = 0)
    {
        if(n > 0)
            this->n = n;
        else
            this->n = 3; //default size
        arr = new int[this->n*(this->n+1)/2];
        len = 0;
    }
    ~LowTri()
    {
        delete []arr;
        n = len = 0;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void LowTri::set(int i, int j, int x)
{
    if(i >= j && i > 0 && j > 0 && i <= n && j <= n)
    {
        arr[n*(j-1) - (j-1)*(j-2)/2 + (i-j)] = x;
        len++;
    }
    else if(i < 1 || j < 1 || i > n || j > n)
        cout<<"Invalid indices, please enter positive numbers less than "<<n<<"\n";
}

int LowTri::get(int i, int j)
{
    if(len == 0)
    {
        printf("Matrix is empty\n");
        return INT_MIN;
    }
    if(i >= j && i > 0 && j > 0 && i <= n && j <= n)
        return arr[n*(j-1) - (j-1)*(j-2)/2 + (i-j)];
    else if(i < j)
        return 0;
    else
    {
        cout<<"Invalid indices, please enter positive numbers less than "<<n<<"\n";
        return INT_MIN;
    }
}

void LowTri::display()
{
    if(len == 0)
    {
        cout<<"Matrix is empty\n";
        return;
    }
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout<<get(i, j)<<" ";
        cout<<"\n";
    }
}

int main()
{
    int i, j, x, n;
    while(true)
    {
        cout<<"Enter the dimension of the square matrix: ";
        cin>>n;
        if(n > 0)
            break;
        cout<<"Invalid input, try with a positive number\n";
    }
    LowTri L(n);
    cout<<"Enter all matrix elements:\n";
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin>>x;
            L.set(i, j, x);
            if(i < j && x != 0)
                cout<<"Note: This is a lower triangular matrix and requisite elements will be zeroed out\n";
        }
    }

    cout<<"Enter indices to get a custom element: ";
    cin>>i>>j; x = L.get(i, j);
    if(i > 0 && i <= n && j > 0 && j <= n)
        cout<<"Element at "<<j<<"th column in the "<<i<<"th row is: "<<x<<"\n";

    cout<<"Matrix contents:\n";
    L.display();

    L.~LowTri();
    cout<<"Program terminated\n";
    return 0;
}
