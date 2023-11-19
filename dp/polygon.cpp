#include <bits/stdc++.h>
using namespace std;

// iterative dp no  rec here

pair<double, double> p[101];
int n;
int dp[1001][1001];

double sq(double x)
{
    return x * x;
}

double cost(int x, int y)
{
    double dist = sqrt(sq(p[x].first - p[y].first) + sq(p[x].second - p[y].second));
    return sin(dist);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    int dp[n + 1][n + 1];
    for (int len = 3; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (len == 3)
                return 0;

            int ans = 1e9;
            for (int x = l + 1; x <= r - 1; x++)
            {
                if (x == l + 1)
                    ans = max(ans, cost(l + 1, r) + dp[l + 1][r]);
                else if (x == r - 1)
                    ans = max(ans, cost(l, r - 1) + dp[l][r - 1]);
                else
                    ans = max(ans, cost(l, x) + cost(r, x) + dp[l][x] + dp[x][r]);
            }
            dp[l][r] = ans;
        }
    }
    cout << dp[1][n];
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
