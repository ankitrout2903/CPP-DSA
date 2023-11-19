#include <bits/stdc++.h>
using namespace std;

// dfs in tree
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

void dfs(int v, int par = 0)
{
    for (int child : g[v])
    {
        if (child == par)
            continue;
        depth[child] = depth[v] + 1;
        dfs(child, v);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    int mx_d = -1;
    int mx_dn;
    for (int i; i <= n; ++i)
    {
        if (mx_d < depth[i])
        {
            mx_d = depth[i];
            mx_dn = i;
        }
        depth[i] = 0;
    }
    dfs(mx_dn);
    int mx_d = -1;
    for (int i; i <= n; ++i)
    {
        if (mx_d < depth[i])
        {
            mx_d = depth[i];
        }
    }

    cout << mx_d << endl;
}