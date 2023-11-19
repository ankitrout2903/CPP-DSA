#include <bits/stdc++.h>
using namespace std;

// iterative dp no  rec here



void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i <n;i++){
        cin>>arr[i];
    }
    
    long long  ans = -1e9;
    long long  last = -1e9;
    
    for(int i = 0 ; i < n; i++){
        if(i==0){
            last=arr[i];
        } else {
            last= max(last,arr[i]);
        }
        ans = max(ans,last);
    }
    cout<<ans<<endl;
    
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
