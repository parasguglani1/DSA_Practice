//To demonstrate a simple example of nested recursion 
#include <iostream>
using namespace std;

int func(int x)
{
    //cout<<x<<" ";
    //Uncomment to observe intricacies
    if(x > 100)
        return x-10;
    else 
        return func(func(x+11));
}

int main()
{
    cout<<"Enter a number: ";
    int n; cin>>n;
    cout<<func(n);
    return 0;
}