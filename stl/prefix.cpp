#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int pf[N];
int main(){
    int n ;
    cin>>n;
    for(int i = 1 ;i<=n;++i){
      cin>>a[i];
      pf[i] = pf[i-1]+a[i];
      //prefix sum array
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pf[r]-pf[l-1]<<endl;
    }
}