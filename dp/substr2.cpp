#include <bits/stdc++.h>
using namespace std;

// dp[config_]; form interval dp
int n;
string t = "0100";
int dp[100100][8];

int rec(int level, int lastthree)
{

    // base case
    if (level == n)
        return 1;

    // cache check
    if (dp[level][lastthree] != -1)
    {
        return dp[level][lastthree];
    }

    // compute
    int ans = 0;
    if (level >= 3 && lastthree == 2)
    {
        // 0100
        // dont allow
        ans = rec(level + 1, 5);
    }
    else
    {
        // add a  zero
        ans = rec(level + 1, (lastthree << 1 | 0 & 7));
        ans += rec(level + 1, (lastthree << 1 | 1 & 7));
    }

    // save and return
    return dp[level][lastthree] = ans;
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
