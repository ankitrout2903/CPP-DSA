#include <bits/stdc++.h>
using namespace std;

// iterative dp no  rec here

int dp[1001][1001];

void solve()
{
    int a, b;
    cin >> a >> b;
    //    memset(dp,-1,sizeof(dp));
    for (int x = 0; x <= a; x++)
    {
        for (int y = 0; y <= b; y++)
        {
            // base case
            if (x == 0 && &y == 0)
                dp[x][y] = 0;

            // cache check
            // if (dp[x][y] != -1)
            //     dp[x][y];

            // compute
            int ans = 0;
            for (int z = 0; z < x; z++)
            {
                if (dp[z][y] == 0)
                {
                    ans = 1;
                    break;
                }
            }
            for (int z = 0; z < y; z++)
            {
                if (dp[x][y] == 0)
                {
                    ans = 1;
                    break;
                }
            }
            for (int z = 1; z < min(x, y); z++)
            {
                if (dp[x - z][y - z] == 0)
                {
                    ans = 1;
                    break;
                }
            }

            // save and return
            dp[x][y] = ans;
        }
    }
    cout << rec(a, b) << endl;
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
