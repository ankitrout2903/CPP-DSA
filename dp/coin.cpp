#include <bits/stdc++.h>
using namespace std;

// iterative dp no  rec here

int dp[1001][1001];

void solve()
{
    int n, m;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int dp[n + 1][m + 1];
    for (int l = n; l >= 0; l--)
    {
        for (int s = 0; s <= m; s++)
        {
            if (l == n)
            {
                if (s == 0)
                {
                    dp[l][s] = 1;
                }
                else
                {
                    dp[l][s] = 0;
                }
            }
            // general
            int ans = 0;
            dp[l][s] = 0;
            if (dp[l + 1][s])
            {
                ans = 1;
            }

            if (s >= x[l] && dp[l][s - x[l]])
            {
                ans = 1;
            }
            dp[l][s] = ans;
        }
    }
    cout<<dp[0][m]<<endl;
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
