#include <bits/stdc++.h>
using namespace std;

vector<int> getLps(string pat)
{
    int m = pat.size();

    vector<int> lps(m);

    int prev = 0;
    int ind = 1;
    while (ind < m)
    {

        if (pat[ind] == pat[prev])
        {
            prev++;
            lps[ind] = prev;
            ind++;
        }

        else if (prev == 0)
        {
            lps[ind] = 0;
            ind++;
        }

        else
        {
            prev = lps[prev - 1];
        }
    }
    return lps;
}

void solve(string str, string pat)
{
    vector<int> lps = getLps(pat);

    int n = str.size();
    int m = pat.size();
    int patIdx = 0;
    int strIdx = 0;

    while (strIdx < n)
    {
        if (str[strIdx] == pat[patIdx])
        {
            patIdx++;
            strIdx++;
        }
        if (patIdx == m)
        {

            cout << strIdx - m << ' ';

            patIdx = lps[patIdx - 1];
        }
        else if (strIdx < n)
        {
            if (str[strIdx] != pat[patIdx])
            {
                if (patIdx != 0)

                    patIdx = lps[patIdx - 1];
                else

                    strIdx++;
            }
        }
    }
    cout << endl;
}

int main()
{
    string str = "parasisincseparas";
    string pat = "paras";
    solve(str, pat);
}
