#include <iostream>
using namespace std;
int n;
int dp[100100]

int rec(int level)
{ // level -> i am at return no of ways to n
    // for all choices{
    //      check if valid{
    //          move(choice)
    //      }

    // pruning
    if (level > n)
        return 0;

    // base case
    if (level == n)
    {
        return 1;
    }

    // if(dp[level!=-1]){
        
    // }
    int ans = 0;

    // loop over choice
    for (int step = 1; step <= 3; step++)
    {
        if (level + step <= n) // check if valid
        {
            int ways = rec(level + step);
            ans += ways;
        }
    }

    //
    dp[level] = ans;
    return ans;
    
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    rec(1);
    cin >> n;
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