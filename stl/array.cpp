#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int hashArr[N];

int main() {
    int n;
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        hashArr[a[i]]++;
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int x;
        cin >> x;
        cout << hashArr[x] << endl;
    }
    
    return 0;
}
