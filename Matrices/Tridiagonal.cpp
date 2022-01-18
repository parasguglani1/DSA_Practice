//Tridiagonal matrix implemented
#include <iostream>
using namespace std;

class TriDiag
{
    private:
    int* A;
    int n;
    int filled;
    public:
    TriDiag(int dimension = 0)
    {
        if(dimension > 1) 
            n = dimension;
        else
            n = 2; //minimum
        A = new int[3*n-2];
        filled = 0;
    }
    ~TriDiag()
    {
        delete []A;
    }
    void create();
    int get(int, int);
    void set(int, int, int);
    void display();
};

void TriDiag::create()
{
    if(filled == 0)
    {
        cout<<"Enter the tridiagonal matrix elements row-by-row:\n";
        int temp, index;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin>>temp; index = i-j;
                if(index >= -1 && index <= 1)
                {
                    if(index == 1)
                        A[i-2] = temp;
                    else if(index == 0)
                        A[(n-1)+(i-1)] = temp;
                    else if(index == -1)
                        A[(2*n-1)+(i-1)] = temp;
                    filled++;
                }
            }
        }
    }
    else
        cout<<"Matrix was filled before\n";
}

int TriDiag::get(int i, int j)
{
    if(filled == 0)
    {
        cout<<"Matrix is empty\n";
        return -1;
    }
    if(i > 0 && j > 0 && i <= n && j <= n)
    {
        int index = i-j;
        if(index >= -1 && index <= 1)
        {
            if(index == 1)
                return A[i-2];
            else if(index == 0)
                return A[(n-1)+(i-1)];
            else if(index == -1)
                return A[(2*n-1)+(i-1)];
        }
        else 
            return 0;
    }
    else
    {
        cout<<"Invalid indices\n";
        return -1;
    }
    return 0;
}

void TriDiag::set(int i, int j, int toSet)
{
    if(filled == 0)
    {
        cout<<"Matrix is empty\n";
        return;
    }
    if(i > 0 && j > 0 && i <= n && j <= n)
    {
        int index = i-j;
        if(index >= -1 && index <= 1)
        {
            if(index == 1)
                A[i-2] = toSet;
            else if(index == 0)
                A[(n-1)+(i-1)] = toSet;
            else if(index == -1)
                A[(2*n-1)+(i-1)] = toSet;
        }
        else
            cout<<"0 has been set at the inputted indices\n";
    }
    else
        cout<<"Invalid indices\n";
}

void TriDiag::display()
{
    if(filled != 0)
    {
        int index;
        cout<<"Matrix contents are:\n";
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                index = i-j;
                if(index >= -1 && index <= 1)
                {
                    if(index == 1)
                        cout<<A[i-2]<<" ";
                    else if(index == 0)
                        cout<<A[(n-1)+(i-1)]<<" ";
                    else if(index == -1)
                        cout<<A[(2*n-1)+(i-1)]<<" ";
                }
                else
                    cout<<"0 ";
            }
            cout<<"\n";
        }
    }
    else
        cout<<"Matrix is empty!\n";
}

int main()
{
    int dimension, ch, i, j, x = 0;
    while(true)
    {
        cout<<"Enter the upper triangular square matrix dimension: ";
        cin>>dimension;
        if(dimension > 0)
            break;
        cout<<"Invalid choice, retry with a positive input\n";
    }
    TriDiag A(dimension);
    while(true)
    {
        cout<<"Menu for tridiagonal matrix:\n";
        cout<<"1. Fill all the matrix elements anew\n2. Get an element from the matrix\n";
        cout<<"3. Replace an element in the matrix\n4. Display the matrix\n";
        cout<<"0. Exit the menu\nEnter your choice: "; cin>>ch;
        if(x == 0 && ch != 1)
        {
            cout<<"Your choice was changed to '1' since the matrix has not been initialized yet\n";
            ch = 1;
            x++; 
        }
        if(ch == 1)
        {
            A.create();
            x = 1;
        }
        else if(ch == 2)
        {
            while(true)
            {
                cout<<"Enter the (i, j) indices from which the element is to be retrieved: ";
                cin>>i>>j;
                if(i > 0 && j > 0 && i <= dimension && j <= dimension)
                    break;
                cout<<"Invalid indices, retry with a pair of inputs between 1 and "<<dimension<<"\n";
            }
            cout<<"Element at "<<j<<"th column in "<<i<<"th row is: "<<A.get(i, j)<<"\n";
        }
        else if(ch == 3)
        {
            while(true)
            {
                cout<<"Enter the (i, j) indices from which the element is to be changed: ";
                cin>>i>>j;
                if(i > 0 && j > 0 && i <= dimension && j <= dimension)
                    break;
                cout<<"Invalid indices, retry with a pair of inputs between 1 and "<<dimension<<"\n";
            }
            cout<<"Enter the new element to be set: "; cin>>x;
            A.set(i, j, x); 
            x = 1; //might have been set as zero
            cout<<"Element at "<<j<<"th column in "<<i<<"th row has been set as: "<<A.get(i, j)<<"\n";
        }
        else if(ch == 4)
            A.display();
        else if(ch < 0 || ch > 4)
            cout<<"Invalid choice, retry with numbers indicated in the menu\n";
        else if(ch == 0)
            break;
    }
    A.~TriDiag();
    cout<<"Program terminated\n";
    return 0;
}