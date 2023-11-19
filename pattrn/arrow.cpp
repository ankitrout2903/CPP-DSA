#include<iostream>
using namespace std;
int n=1;
int main(){
     
        for(int i = 0;i<n;i++){
            
            for(int j = 0;j<i;j++){
                cout<<"* ";
            }
            cout<<endl;
        }
        for(int i = 0;i<n;i++){
           
            for(int j= 0;j<n-i;j++){
                cout<<"* ";
            }
           cout<<endl;
        }
        // code here
    }

