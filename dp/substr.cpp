#include <bits/stdc++.h>
using namespace std;

// dp[config_]; form interval dp
int n;
string t = "0100";
int dp[100100][5];

int rec(int level, int match)
{
    //prunning
    if(match ==4){
        return 0;
    }

    //base case
    if(level == n){
        return 1;
    }

    //cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }

    //compute
    int ans = rec(level+1,match+1) + rec(level+1,match);
    

    //save and return
    return dp[level][match] = ans;

}

void solve()
{
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << rec(0, 0) << endl;
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
