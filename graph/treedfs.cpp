#include <bits/stdc++.h>
using namespace std;

// dfs in tree
const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];
int height[N];


void dfs(int vertex, int par)
{
    // take axn before entering vertex
   
    for (int child : g[vertex])
    {
       
        // take axn on the child before entering child node
        if(child == par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
        // take axn on child after exiting the child node
    }
    // take axn after entering the child node
    
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
   dfs(1,0);
   for(int i = 1;i <=n;++i){
    cout<<depth[i]<<" "<<height[i]<<endl;
   }
}