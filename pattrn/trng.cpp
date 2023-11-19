#include<iostream>
using namespace std;

int n=5;
int main() {
    for(int i = 0; i<n;i++){
            //sp
            for(int j = 0; j<n-i -1; j++){
                cout<<" ";
            }
            //str
            for(int j = 0; j<2*i +1;j++){
                cout<<"*";
            }
            
           cout<<endl;
        }
	for(int i = 0; i<n ; i++){
	        //sp
	        for(int j =0; j<i;j++){
	            cout<<" ";
	        }
	        
	        // str
	        for(int j = 0;j<2*n - (2*i +1);j++){
	            cout<<"*";
	        }
	        
	        //sp
	        //  for(int j =0; j<i;j++){
	        //     cout<<" ";
	        // }
	        cout<<endl;
	    }
	    // code here
	}