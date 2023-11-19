#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int a[100010];
int b[100010];
int dp[1001][100100];

int rec(int level, int num)
{
    if (level < 1)
        return 1e9;
    if (level == 1 &&num = 0)
        return 0;
    else if (level == 1)
        return 1e9;

    if (dp[level][num] != -1)
        return dp[level][num];

    int ans = rec(level - 1, num) + b[level - 1];
    if (num >= 0)
        for (int j = 1; j <= k; j++)
        {
            ans = min(ans, rec(level - j, num - 1) + a[level - j] + a[level]);
        }

    return dp[level][num] = ans;
}

struct monotone_deque
{
    deque<int> dq;
    void insert(int x)
    {
        while (!dq.empty() && dq.back() > x)
        {
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void remove(int x)
    {
        if (!dq.empty() && dq.front() == x)
        {
            dq.pop_front();
        }
    }
    void getmin()
    {
        if (!dq.empty())
        {
            return dq.front();
        }
        else
        {
            return 0;
        }
    }
};

void input()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> b[i];
    }
}
void solve()
{
    input();
    dp[1] = 0;
    monotone_deque dq;
    for (int level = 2; level <= n; level++)
    {
        dp[level] = dp[level - 1] + b[level - 1];
        dq.insert(dp[level - 1] + a[level - 1]);
        if (level - k - 1 >= 1)
            dq.remove(dp[level - k - 1] + a[level - k - 1]);

        dp[level] = min(dp[level], dq.getmin() + a[level]);
    }

    cout << dp[n] << endl;
}

void solve2()
{
    input();
    for (int j = 0; j <= m; j++)
    {
        monotone_deque dq;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 & j == 0)
            {
                dp[j&1][i] = 0;
            }
            else if (i == 1)
            {
                return dp[j&1][i] = 1e9;
            }
            else
            {

                dp[j&1][i] = dp[j&1][i - 1] + b[i - 1];
                if (j > 0)
                    dq.insert(dp[j - 1][level - 1] + a[level - 1]);
                if (level - k - 1 >= 1)
                    dq.remove(dp[level - k - 1] + a[level - k - 1]);
                dp[j][i] = min(dp[j&1][i], dq.getmin() + a[level]);
            }
        }
    }
}