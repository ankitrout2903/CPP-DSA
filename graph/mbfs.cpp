#include <bits/stdc++.h>
using namespace std;

// multi-source bfs
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int val[N][N];
int lev[N][N];
int vis[N][N];
int n, m;

vector<pair<int, int>> movements = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}};

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j];
}

int bfs()
{
    int mx = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            mx = max(mx, val[i][j]);
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (val[i][j] == mx)
            {
                q.push({i, j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();

        for (auto movement : movements)
        {
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if (!isValid(child_x, child_y))
                continue;
            if (vis[child_x][child_y])
                continue;
            q.push({child_x, child_y});
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            vis[child_x][child_y] = 1;
            ans = max(ans, lev[child_x][child_y]);
        }
    }
    return ans;
}

void reset()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            lev[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        reset();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> val[i][j];
                lev[i][j] = INF;
                vis[i][j] = 0;
            }
        }
        cout << bfs() << endl;
    }
}
