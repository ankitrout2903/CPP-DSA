#include <bits/stdc++.h>
using namespace std;
 
// dp[config_]; form interval dp
int n;
int dp[100100];

int rec(int x)
{
    // prunning

    // basecase
   
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int insertedat[n];
    for(int i = 0 ; i < n ; i ++){
        cin>>arr[i];
    }
    vector<int> lis;
    for(int i = 0 ; i < n ; i ++){
        if(lis.empty()||lis.back()<<arr[i]){
            lis.push_back(arr[i]);
            insertedat[i]=lis.size()-1
        } else {
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
            insertedat[i]=it - lis.begin();
        }
        cout<<" : ";
        for(auto v : lis){

            cout<<v<<", ";
        }
        cout<<endl;
    }

    for(int i = 0 ; i < n ; i++){
        cout<<insertedat[i]<<" ";
    }
    cout<<endl;
    cout<<lis.size()<<endl;
    int curlen = lis.size();
    vector<int> final_lis;
    for(int i = 0 ; i >=0;i--){
        if(insertedat[i]==curlen){
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }
    reverse(final_lis.begin(),final_lis.end());
    cout<<lis.size()<<endl;
    for(auto v : final_lis){
        cout<<v<<" "<<endl;
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
