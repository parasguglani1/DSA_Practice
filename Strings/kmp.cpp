#include <bits/stdc++.h>
using namespace std;

vector<int> getLps(string pat)
{
    int m = pat.size();

    // Vector to store the LPS array.
    vector<int> lps(m);

    /*
    Prev is the last longest proper prefix
    which is also a suffix
    */
    int prev = 0;
    int ind = 1;
    while (ind < m)
    {

        // If both are equal
        if (pat[ind] == pat[prev])
        {
            prev++;
            lps[ind] = prev;
            ind++;
        }

        /*
        If the current elements are unequal
        And LPS is 0
        */
        else if (prev == 0)
        {
            lps[ind] = 0;
            ind++;
        }

        /*
        If the current elements are unequal
        But LPS is not 0
        */
        else
        {
            prev = lps[prev - 1];
        }
    }
    return lps;
}

/*
Function to find
All occurrences of the pattern in the string
*/
void solve(string str, string pat)
{
    vector<int> lps = getLps(pat);

    // Initializing variables
    int n = str.size();
    int m = pat.size();
    int patIdx = 0;
    int strIdx = 0;

    while (strIdx < n)
    {

        // If both the elements match
        if (str[strIdx] == pat[patIdx])
        {
            patIdx++;
            strIdx++;
        }
        if (patIdx == m)
        {

            /*
            This means that the entire pattern has matched
            Printing all occurrences of the pattern in the string
            */
            cout << strIdx - m << ' ';

            // Updating patIdx to the last element matched.
            patIdx = lps[patIdx - 1];
        }
        else if (strIdx < n)
        {
            if (str[strIdx] != pat[patIdx])
            {
                if (patIdx != 0)

                    // Updating lps to the last element matched
                    patIdx = lps[patIdx - 1];
                else

                    // If no element matched, we move to next index
                    strIdx++;
            }
        }
    }
    cout << endl;
}

// Driver Code
int main()
{
    string str = "parasisincseparas";
    string pat = "paras";
    solve(str, pat);
}
