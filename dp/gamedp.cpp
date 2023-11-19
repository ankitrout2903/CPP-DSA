#include <bits/stdc++.h>
using namespace std;

// dp[config_]; form interval dp
int n;
int dp[100100];

int rec(int x)
{
    // prunning

    // basecase
    if (x == 0)
        return 0;

    // cache check
    if (dp[x] != -1)
        return dp[x];

    // compute
    int ans = 0;
    for (int m = 0; (1 << m) <= x; m++)
    {
        if (rec(x - (1 << m) == 0))
        {
            ans = 1;
        }
    }

    // save and return
    return dp[x] = ans;
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= 10; i++)
    {
        // cout << i << " " << refc(i) << endl;
        if(n%3) cout<<"win"<<endl;
        else cout<<"loose"<<endl;
    }
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
