//Solving for the nth term of the fibonacci series
#include <iostream>
#include <ctime>
using namespace std;

long long altMFibo(int n)
{//memoization-like iteration with in-house array
    long long arr[n+1];
    arr[0] = 0; arr[1] = 1;
    for(int i = 2; i <= n; i++)
        arr[i] = arr[i-1] + arr[i-2];
    return arr[n];
}

long long arr[1000]; //auxilliary for Mfibo(int)
long long Mfibo(int n)
{
    if(n <= 1)
        arr[n] = n;
    else 
    {
        //memoization
        if(arr[n-1] == -1)
            arr[n-1] = Mfibo(n-1);
        if(arr[n-2] == -1)
            arr[n-2] = Mfibo(n-2);
        arr[n] = arr[n-1] + arr[n-2];    
    }
    return arr[n];
}

long long rFibo(int n)
{//simple recursion
    if(n <= 1)
        return n;
    else 
        return rFibo(n-1) + rFibo(n-2);
}

long long iterFibo(int n)
{//iteration
    if(n <= 1)
        return n;
    long long a = 0, b = 1, c;
    for(int i = 2; i <= n; i++)
    {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

void computeTime(int index, long long (*fptr)(int), string x)
{//facilitator and comparer
    clock_t timeSpent = clock();
    cout<<fptr(index);
    timeSpent = clock() - timeSpent;
    cout<<" - "<<x<<" solution took "<<(float)timeSpent/CLOCKS_PER_SEC<<" seconds to execute\n";
}

int main()
{
    int n;
    while(true)
    {
        cout<<"Enter a positive number: ";
        cin>>n; 
        if(n > 0)
            break;
        cout<<"Invalid input, try again\n";
    }

    cout<<n<<"th term of Fibonacci series is:\n";
    computeTime(n, rFibo, "naive recursive");
    computeTime(n, iterFibo, "iterative");
    //filling the global array
    for(int i = 0; i <= n; i++)
    arr[i] = -1;
    computeTime(n, Mfibo, "memoized recursive");
    computeTime(n, altMFibo, "alternate memoized");

    return 0;
}