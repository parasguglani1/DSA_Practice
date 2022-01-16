//To demonstrate a lucid indirect-recursion
//Various pseudo-tail/head recursions can be designed to change the order of outputs
#include <iostream>
using namespace std;

void funB(int);

void funA(int n)
{
    if(n > 0)
    {
        cout<<n<<" ";
        funB(n-1);
    }
}

void funB(int x)
{
    if(x > 1)
    {
        cout<<x<<" ";
        funA(x/2);
    }
}

int main()
{
    int num;
    while(true)
    {
        cout<<"Enter a non-negative input: ";
        cin>>num;
        if(num > 0)
            break;
        cout<<"Invalid input, try again\n";
    }
    funA(num);
    return 0;
}