#include<iostream>
using namespace std;
int t;
int main(){
cin>>t;
while(t--){
    int m , n;
    cin>>m>>n;
    if(m>n){
        m = m-1;
        n = n+1;
    }
    else if(m<n){
        m = m+3;
        n = n-1;
    }
   
    else if (m == n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
return 0;
}