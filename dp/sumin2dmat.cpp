#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1001][1001];
int dp[1001][1001];
bool done[1001][1001];

int rec(int r, int c)
{
    // prunning
    if (r < 0 || c < 0)
        return -1e9;

    // base case
    if (r == 0 && c == 0)
    {
        return arr[0][0];
    }

    // cache check
    if (done[r][c])
    {
        return dp[r][c];
    }

    // compute
    int ans = -1e9;
    if (r != 0)
    {
        ans = max(ans, rec(r - 1, c) + arr[r][c]);
    }
    if (c != 0)
    {
        ans = max(ans, rec(r, c - 1) + arr[r][c]);
    }
    // int ans = max(rec(r - 1, c) + arr[r][c], rec(r, c - 1) + arr[r][c]);

    // save and return
    done[r][c] = 1;
    return dp[r][c] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            done[i][j] = 0;
        }
    }
    cout << rec(n - 1, m - 1) << endl;
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