/*To demonstrate Taylor series using recursion using:
1. Iterative and recursive versions of the MacLaurin expansion
2. Using Horner's rule for decreasing number of multiplications
*/
#include <iostream>
#include <ctime>
using namespace std;

//1+ x/1 + x*x/2! + x*x*x/3! + ... 21 terms
double iterExp(double x, int n = 20)
{
    double p = 1, f = 1; //x^0 and 0!
    double ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += p/f;
        p *= x;
        f *= i;
    }
    return ans;
}

//1+ x/1 + x*x/2! + x*x*x/3! + ... 21 terms
double exp(double x, int n = 20)
{
    static double p = 1; //x^0
    static double f = 1; //0!
    double r;
    if(n == 0)
        return 1;
    else 
    {
        r = exp(x, n-1);
        p *= x;
        f *= n;
        return r+(double)p/f;
    }
}

//1+x(1 + x/2*(1+x/3*(1+x/4(...20 terms))))
double iterHorners(double x, int n = 20)
{
    double sum = 0;
    for(;n > 0; n--)
    {
        sum = 1+(x/n)*sum;
    }
    return sum;
}

//1+x(1 + x/2*(1+x/3*(1+x/4(...20 terms))))
double expHornersAlt(double x, int n = 20, int k = 1)
{
    if(k > n)
        return 1;
    else
        return (1+(x/k)*expHornersAlt(x, 20, k+1));
}

//1+x(1 + x/2*(1+x/3*(1+x/4(...20 terms))))
double expHorners(double x, int n = 20)
{
    static double sum = 0;
    if(n == 0)
        return sum;
    else 
    {
        sum = 1+(x/n)*sum;
        return expHorners(x, n-1);
    }
}

//handler and facilitator for comparison
void computeTime(double index, double (*fptr)(double, int), string x)
{
    clock_t timeSpent = clock();
    cout<<fixed<<fptr(index, 20);
    timeSpent = clock() - timeSpent;
    cout<<" - "<<x<<" solution took "<<(float)timeSpent/CLOCKS_PER_SEC<<" seconds to execute\n";
}

//only for altHorners' - expHornersAlt(double, int, int)
void computeTime(double index, double (*fptr)(double, int, int), string x)
{ 
    clock_t timeSpent = clock();
    cout<<fixed<<fptr(index, 20, 1);
    timeSpent = clock() - timeSpent;
    cout<<" - "<<x<<" solution took "<<(float)timeSpent/CLOCKS_PER_SEC<<" seconds to execute\n";
}

int main()
{
    cout<<"Enter a real number: ";
    double index; cin>>index;

    cout<<"Napier's constant raised to the power "<<index<<":\n";
    computeTime(index, iterExp, "simple iterative");
    computeTime(index, exp, "naive recursive");
    computeTime(index, iterHorners, "Horners' iterative");
    computeTime(index, expHorners, "Horners' recursive");
    computeTime(index, expHornersAlt, "alternative Horners' recursive");

    return 0;
}
