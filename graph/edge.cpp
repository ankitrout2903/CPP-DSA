#include <bits/stdc++.h>
using namespace std;

// delete a node in a tree
const int N = 1e5 + 10;
vector<int> g[N];
int sub[N];
int val[N];
const int M = 1e9+7;

void dfs(int vertex, int par )
{
    sub[vertex] += val[vertex];
  for(int child:g[vertex]){
    if(child==par) continue;
    dfs(child,vertex);
    sub[vertex]+=sub[child];
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
    dfs(1,0);

    long long ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        int part1 = sub[i];
        int part2 = sub[1] - part1;
        ans = max(ans,(part1*1LL*part2)%M);
    }
    cout<<ans<<endl;

    
   

  
}