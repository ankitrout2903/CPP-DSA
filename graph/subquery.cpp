#include <bits/stdc++.h>
using namespace std;

// dfs in tree
const int N = 1e5 + 10;
vector<int> g[N];
int subtree[N];
int even_ct[N];
int val[N];

void dfs(int vertex, int par)
{
    // take axn before entering vertex
 
   if(vertex%2==0) even_ct[vertex]++;
   subtree[vertex]+=vertex;
    for (int child : g[vertex])
    {
       
        // take axn on the child before entering child node
        if(child == par) continue;
        dfs(child,vertex);
        subtree[vertex] += subtree[child];
        even_ct[vertex]+=even_ct[child];
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
  int q;
  while(q--){
    int v;
    cin>>v;
    cout<<subtree<<" "<<even_ct<<endl;

  }
}