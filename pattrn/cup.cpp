#include<iostream>
using namespace std;
int n;
int s;
int main(){
    cin>>n;
    s = 2*(n-1);
    for (int i = 1; i <= n; i++)
    {
        //nm
        for(int j = 1; j<=i;j++){
            cout<<j;
        }


        //spc
        for(int j = 1;j<=s;j++){
              cout<<" ";
        }

        //num
        for(int j = i; j>=1;j--){
            cout<<j;

        }
        cout<<endl;
        s -= 2;
    }
    return 0;
    

}