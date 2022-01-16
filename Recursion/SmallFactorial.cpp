//To calculate the factorial of a small number
#include <iostream>
#include <ctime>
using namespace std;
typedef long long ll;

ll fact(short n)
{
    if(n == 0)
        return 1;
    else 
        return fact(n-1)*n;
}

ll loopFact(short n)
{
    ll f = 1;
    while(n >= 1)
    {
        f *= n;
        n--;
    }
    return f;
}
//to compare the time taken by two approaches - equivalent for small inputs
void computeTime(short n, ll (*fptr)(short), string x)
{
    clock_t timeSpent = clock();
    cout<<fptr(n);
    timeSpent = clock() - timeSpent;
    cout<<" - "<<x<<" solution took "<<(float)timeSpent/CLOCKS_PER_SEC<<" seconds to execute\n";
}

int main()
{
    short num; 
    while(true)
    {
        cout<<"Enter a small whole number: ";
        cin>>num; 
        if(num >= 0 && num <= 20)
            break;
        cout<<"Invalid input, try again\n";
    }

    cout<<num<<"! (read as factorial of "<<num<<") is:\n";
    computeTime(num, fact, "recursive");
    computeTime(num, loopFact, "iterative");
    return 0; 
}