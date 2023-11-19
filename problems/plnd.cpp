#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int dup = n;
    int rev = 0;
    while(n>0){
        int ld = n % 10;
        n = n / 10;
     rev = rev*10 + ld;
    }
    cout<<rev;
   
    if(rev == dup){
        cout<<"yes";
        
    }
    else{
        cout<<"no";
    }
    return 0;
}