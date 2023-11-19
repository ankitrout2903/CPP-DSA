#include <iostream>
using namespace std;
int main()
{
    int n = 5;

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0) cout << endl;
        
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < s; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        s += 2;
    }
    

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < s; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout<<endl;
        s -= 2;
    }

    return 0;
}