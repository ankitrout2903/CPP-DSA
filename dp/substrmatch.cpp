#include <bits/stdc++.h>
using namespace std;

// dp[config_]; form interval dp
int n;
string t = "0100";
int dp[100100][5];

int rec(int level, int match)
{
    if (match == 4)
        return 0;

    if (level == n)
        return 1;

    if (dp[level][match] != -1)
        return dp[level][match];

    int ans = 0;
    if (match == 0)
    {
        ans = rec(level + 1, 0) + rec(level + 1, 1);
    }
    else if (match == 1)
    {
        ans = rec(level + 1, 1) + rec(level + 1, 0);
    }
    else if (match == 2)
    {
        ans = rec(level + 1, 3) + rec(level + 1, 0);
    }
    else if (match == 3)
    {
        ans = rec(level + 1, 4) + rec(level + 1, 2);
    }
}

void solve()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}

int main()
{
    ios_base::sync_with_studio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}
