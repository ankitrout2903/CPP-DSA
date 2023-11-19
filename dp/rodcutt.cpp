#include <bits/stdc++.h>
using namespace std;

// dp[l,r,_]; form interval dp
int n;
int x[1001];
int dp[1001][1001];

int rec(int l,int r){
    //prunning

    //basecase
    if(l+1==r) return 0;

    //cache check
    if(dp[l][r]!=-1) return dp[l][r];

    //compute
    int ans = 1e9;
    for(int p=l+1;p<=r-1;p++){
        ans = min(ans,x[r]-x[l]+rec(l,p)+rec(p,r));
    }

    //save and return
    return dp[l][r]=ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    x[0]=0;
    memset(dp,-1,sizeof(dp));
    cout << rec(0,n) << endl;
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