//To demonstrate computing positive integral powers using recursion
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

template <typename T>
T power(T base, int posIndex)
{
    if(posIndex == 0)
        return 1;
    else 
        return base*power(base, posIndex-1);
}

template <typename T>
T iterPower(T base, int posIndex)
{
    T ans = 1;
    while(posIndex > 0)
    {
        ans *= base;
        posIndex--;
    }
    return ans;
}

template <typename Type>
Type fastPower(Type base, int posIndex)
{
    if(posIndex == 0)
        return 1;
    else if(posIndex%2 == 0)
        return fastPower(base*base, posIndex/2);
    else 
        return fastPower(base*base, posIndex/2)*base;
}

void genPower(double b, int i, double (*fptr)(double, int), string s)
{
    clock_t duration = clock();
    cout<<setprecision(9)<<fptr(b, i)<<" - "<<s<<" solution";
    duration = clock() - duration;
    cout<<" took "<<(float)duration/CLOCKS_PER_SEC<<" seconds\n";
}

int main()
{
    double base; int index;
    cout<<"Enter a real number: "; cin>>base;
    while(true)
    {
        cout<<"Enter a whole number: "; cin>>index;
        if(index >= 0)
            break;
        cout<<"Invalid input, try again\n";
    }

    cout<<fixed<<base<<" raised to the power of "<<index<<" = \n";
    genPower(base, index, power, "recursive");
    genPower(base, index, iterPower, "iterative");
    genPower(base, index, fastPower, "half-index recursive");
    return 0;
}

