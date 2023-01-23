// To compute sum of first N natural numbers
#include <iostream>
#include <ctime>
using namespace std;
typedef long long ll;

// retained the n == 0 function to match real definition
ll sumN(ll n)
{
    if (n == 0)
        return 0;
    else
        return n + sumN(n - 1);
}

// iterative summation - space efficient
ll loopSum(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += n;
        n--;
    }
    return ans;
}
// one-liner Gauss' formula
ll sumFormula(ll n)
{
    return n * (n + 1) / 2;
}
// to compare time taken by the various methods
void computeTime(ll x, ll (*ptr)(ll), string s)
{
    time_t start = clock();
    cout << ptr(x);
    start = clock() - start;
    cout << " - " << s << " solution took " << (float)start / CLOCKS_PER_SEC << " seconds for execution\n";
}

int main()
{
    ll n;
    while (true)
    {
        cout << "Enter a natural number: ";
        cin >> n;
        if (n > 0)
            break;
        cout << "Invalid input, try again\n";
    }

    cout << "The sum of first " << n << " natural numbers is:\n";
    computeTime(n, sumN, "recursive");           // the name acts as a function pointer - sumN
    computeTime(n, loopSum, "iterative");        // even using parentheses isn't permitted - sumN()
    computeTime(n, sumFormula, "formula-based"); // having passed parameter makes it ll type - sumN(n)
    return 0;
}