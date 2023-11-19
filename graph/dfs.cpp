#include <bits/stdc++.h>
using namespace std;

// dfs in tree
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> cur_c;
bool isLoopExists = false;

bool dfs(int vertex, int par)
{
    // take axn before entering vertex
    vis[vertex] = true;
    cur_c.push_back(vertex);
    for (int child : g[vertex])
    {
        cout << "par" << vertex << "child" << child << endl;
        if (vis[child] && child == par)
            continue;
        if (vis[child])
            return true;
        // take axn on the child before entering child node
        isLoopExists |= dfs(child, vertex);
        // take axn on child after exiting the child node
    }
    // take axn after entering the child node
    return isLoopExists;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        cur_c.clear();
        if (dfs(i, 0))
        {
            isLoopExists = true;
            break;
        };
        cc.push_back(cur_c);
        ct++;
    }
    cout << cc.size() << endl;
    for (auto c_cc : cc)
    {
        for (int vertex : c_cc)
        {
            cout << vertex << " " << endl;
            ;
        }
    }
}