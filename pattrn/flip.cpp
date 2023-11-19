#include <iostream>
using namespace std;
int n;
int s = 1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            s = 1;
        }
        else
        {
            s = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << s;
            s = 1 - s;
        }
        cout << endl;
    }
    return 0;
}
