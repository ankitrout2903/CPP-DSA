#include <bits/stdc++.h>
using namespace std;

int n;
int t[1001];
int s[1001];
int x, k;
int dp[101][101][101];

int rec(int level, int time_taken, int item_taken)
{
    // prunning

    // base case
    if (level == n)
    {
        return 0;
    }
    // cache check
    if (dp[level][time_taken][item_taken] != -1)
    {
        return dp[level][time_taken][item_taken];
    }

    // trantition || compute
    int ans = rec(level + 1, time_taken, item_taken);
    if (time_taken + t[level] <= x && item_taken + 1 <= k)
    {
        ans = min(ans, s[level] + rec(level + 1, time_taken + t[level], item_taken + 1));
    }
    // save and return
    return dp[level][time_taken][item_taken] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> s[i];
    }
    cin >> x >> k;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
}