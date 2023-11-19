#include <bits/stdc++.h>
using namespace std;

int n, m;
string a, b;
int dp[1001][1001];

int rec(int i, int j, int k)
{
    // return the lcs of a[i....n-1] and b[j.....m-1]..c[k...x-1]

    // ppruning

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    // basecase
    if (i >= n || j >= m)
        return 0;

    // compute
    int ans = 0;
    ans = max(ans, rec(i, j + 1, k));
    ans = max(ans, rec(i + 1, j, k));
    ans = max(ans, rec(i + 1, j, k + 1));
    if (a[i] == b[j] && b[j] == c[k])
    {
        ans = max(ans, 1 + rec(i + 1, j + 1, k + 1));
    }

    // save and return
    return dp[i][j][k] = ans;
}

void solve()
{
    cin >> n >> m >> x;
    cin >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
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