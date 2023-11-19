#include <iostream>
using namespace std;
// n queen problem count number of ways

int n;

int queen[20]; // queen[i] tells me where is my queen in row i

bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int prow = i;
        int pcol = queen[i];

        if (pcol == col || abs(col - pcol) == abs(row - prow))
        {
            return 0;
        }
    }
}

int rec(int level)
{ // rec-> nub of ways to populate {level ... n-1} rows for a valid config

    // level ->row in which we place queen

    // pruning

    // base case
    if (level == n)
        return 1;

    // compute
    int ans = 0;
    // we loop over all choice
    for (int col = 0; col < n; col++)
    { // check if option is valid
        if (check(level, col))
        {
            // place queen
            queen[level] = col;
            // explore
            rec(level + 1);
            // revert back
            queen[level] = -1;
        }
    }

    // return
    return ans;
}

void solve()
{
    cin >> n;
    memset(queen, -1, sizeof(queen));
    cout << rec(0) << endl;
}

int main()
{
    ios_base::sync_with_studio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}