//Implementing the combination function
#include <iostream>
using namespace std;
typedef long long ll;

ll fact(int n)
{
    if(n == 0)
        return 1;
    else 
        return fact(n-1)*n;
}

ll C(int n, int r)
{
    return fact(n)/(fact(n-r)*fact(r));
}

ll c(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    else 
        return c(n-1,r-1)+c(n-1,r);
}

int main()
{
    cout<<"Enter the value of n: "; int n, r;
    while(true)
    {
        cin>>n;
        if(n >= 0)
            break;
        cout<<"Invalid input, try with a whole number\n";
    }
    while(true)
    {
        cout<<"Enter r, less than equal to n: ";
        cin>>r;
        if(r >= 0 && r <= n)
            break;
        cout<<"Invalid input, try with a whole number\n";
    }

    cout<<n<<"C"<<r<<" = \n";
    if(n > 20)
        cout<<"Cannot calculate using factorial as it'd cause overflow\n";
    else 
        cout<<C(n,r)<<" - calculated using the formula\n";
    cout<<c(n,r)<<" - obtained using the Pascal's triangle\n";

    return 0;
}