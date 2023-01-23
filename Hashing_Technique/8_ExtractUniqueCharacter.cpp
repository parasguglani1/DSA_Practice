// Extract Unique characters
// Send Feedback
// Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
// Input format :
// String S
// Output format :
// Output String
// Constraints :
// 0 <= Length of S <= 10^8
// Sample Input 1 :
// ababacd
// Sample Output 1 :
// abcd
// Sample Input 2 :
// abcde
// Sample Output 2 :
// abcde
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define ff first
#define ss second
#define int long long
using ll = long long;
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define PI 3.1415926535897932384626
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define all(x) (x).begin(), (x).end()
#define sortall(x) sort(all(x))
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, k, n) for (int i = k; i < n; ++i)
#define REPR(i, k, n) for (int i = k; i > n; --i)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
char getChar(int i)
{
    return (char)i + 97;
}

// vector of bools
char *uniqueChar(char *str)
{
    int k = 0;
    vector<bool> h(130, false);
    for (int i = 0; str[i] != '\0'; i++)
    {
        int idx = str[i];
        if (!h[idx])
            str[k++] = str[i];
        h[idx] = true;
    }
    str[k] = '\0';
    return str;
}

// using map method 2
char *uniqueChar(char *s)
{
    unordered_map<char, int> m1;

    char out[10000000];
    int j = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        m1[s[i]]++;
        if (m1[s[i]] == 1)
        {
            out[j] = s[i];
            j++;
        }
    }
    out[j] = '\0';
    return out;
}
// map
string uniqueChar(string str)
{
    unordered_map<char, bool> mp;
    string res = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (mp.find(str[i]) == mp.end())
        {
            mp[str[i]] = true;
            res += str[i];
        }
    }
    return res;
}
// using set
string uniqueChar(string str)
{
    string answer;
    unordered_set<char> charSet;

    for (char ch : str)
    {
        if (charSet.find(ch) == charSet.end())
        {
            answer.push_back(ch);
            charSet.insert(ch);
        }
    }

    return answer;
}

void pgsolve()
{
    string str;
    cin >> str;
    int n = str.size();
    map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        m[str[i]]++;
    }
    rep(i, 26)
    {
        char cur = getChar(i);
        if (m[cur] >= 1)
        {
            cout << cur;
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto start1 = high_resolution_clock::now();

#ifdef __GNUC__
    freopen("error.txt", "w", stderr);
#endif

    pgsolve();

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef __GNUC__
    cerr << "\n Time: " << duration.count() / 1000 << " ms" << endl;
#endif
    return 0;
}