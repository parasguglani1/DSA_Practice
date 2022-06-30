#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll solve(string &s, ll i, ll j, ll k, vector<vector<vector<ll>>> &dp)
{
    if (k == 0)
        return 1;
    if (i > j)
        return 0;

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    if (k == 1)
    {
        return dp[i][j][k] = j - i + 1;
    }

    ll ans = 0;

    if (i < j && s[i] == s[j])
    {
        ans = solve(s, i + 1, j - 1, k - 2, dp);
    }

    ans += solve(s, i + 1, j, k, dp) + solve(s, i, j - 1, k, dp) - solve(s, i + 1, j - 1, k, dp);

    return (dp[i][j][k] = ans) % mod;
}

int main()
{
    string s;
    cin >> s;

    ll k = 5;
    ll n = s.length();

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(k + 1, -1)));

    ll ans = solve(s, 0, n - 1, k, dp);

    cout << ans << endl;
    return 0;
}
