#include <bits/stdc++.h>
using namespace std;

bool check(string s, int low, int high)
{
    if (high - low < 1)
        return true;
    if (s[high] != s[low])
        return false;
    check(s, low + 1, high - 1);
}

int main()
{
    string s;
    cin >> s;
    if (check(s, 0, s.size() - 1))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    return 0;
}
