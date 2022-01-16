//Iterative equivalent of a head recursion
#include <iostream>
using namespace std;

void fwdPrint(int x)
{
    if(x > 0)
    {
        fwdPrint(x-1);
        cout<<x<<" ";
    }
    /*else 
        cout<<"\nRecursive function terminated\n";
        This one does not work the way one'd expect, since it's executed 
        even before the first output
    */
}

void iterPrint(int x)
{
    int num = x;
    while(--num >= 0)
        cout<<x - num<<" ";
    cout<<"\nIterative function terminated\n";
}

int main()
{
    cout<<"Enter a positive number: ";
    int n; 
    while(true)
    {
        cin>>n;
        if(n > 0)
            break;
        cout<<"Invalid input, try again\n";
    }

    fwdPrint(n);
    cout<<"\nRecursive function terminated\n";

    iterPrint(n);
    return 0;
}