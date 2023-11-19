#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        //spc
        for(int j = 0;j<n-i-1;j++)
        cout<<" ";

        //char
        char ch = 'A';
        int br = (2*i +1) / 2;

        for(int j = 1; j<= 2*i+1;j++){
            cout<<ch;
            if(j<=br){
                ch++;
            }
            else{
                ch--;
            }
        }

        //spc
        cout<<endl;

    }
    
    

}