#include <iostream>
using namespace std;

bool canHaveSameProblems(int N, int M) {
    if (N == M) {
        // Both have the same number of problems initially
        return true;
    } else if (N > M) {
        // Alice has more problems initially
        int diff = N - M;
        if (diff >0) {
            N = N - 1;
            M = M + 1;
       
            
        }
    } else {
        // Bob has more problems initially
        int diff = M - N;
        if (diff > 0) {
            M = M - 1;
            N = N + 3;
          
        }
    }
    // If none of the conditions are met, it is not possible
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        if (canHaveSameProblems(N, M)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}