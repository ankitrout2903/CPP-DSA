#include <bits/stdc++.h>
using namespace std;

int n, t;
int x[101];
int dp[105][10001];
int ans = 0;

int rec(int level, int left)
{
    // pruning
    if (left < 0)
        return 0;

    // base case
    if (level == n + 1)
    {
        if (left == 0)
            return 1;
        else
            return 0;
    }

    // cache check
    if (dp[level][left] != -1)
    {
        return dp[level][left];
    }

    // compute
    if (rec(level + 1, left) == 1)
    {
        ans = 1;
    }
    else if (rec(rec + 1, left - x[level]))
    {
        ans = 1;
    }

    // save an dreturn
    return dp[level][left] = ans;
}

void printSet(int level, int left)
{

    cout << "printer :" << level << " " << left << endl;
    // base case
    if (level == n + 1)
    {
        return;
    }

    if (rec(level + 1, left) == 1)
    {
        printSet(level + 1, left);
    }
    else if (rec(rec + 1, left - x[level]))
    {
        cout << x[level] << " ";
        printSet(level + 1, left - x[level]);
    }

    // find correct transition

    //
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    memset(dp, -1, sizeof(dp));

    int q;
    cin >> q;
    while (q--)
    {
        cin >> t;
        if (rec(1, t))
        {
            printSet(1, t);
            cout << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }
}