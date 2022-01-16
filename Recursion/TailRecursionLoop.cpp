//Tail recursion and loop equivalent
#include <iostream>
using namespace std;

void revPrint(int n)
{
    if(n > 0)
    {
        cout<<n<<" ";
        revPrint(n-1);
    }
    else
        cout<<"\nRecursive function terminated\n";
}

void iterPrint(int n)
{
    while(n > 0)
        cout<<n--<<" ";
    cout<<"\nIterative function terminated\n";
}

int main()
{
    cout<<"Enter a positive number: ";
    unsigned int n;
    while(true)
    {
        cin>>n;
        if(n <= 0)
            cout<<"Invalid input, try again\n";
        else 
            break;
    }

    revPrint(n);
    iterPrint(n);

    return 0;
}