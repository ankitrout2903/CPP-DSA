#include <bits/stdc++.h>
using namespace std;
// disjoint set union
const int N = 1e5 + 10;
int par[N];
int siz[N];

void make(int v)
{
    par[v] = v;
    siz[v] = 1;
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
        {
            swap(a, b);
        }
        par[b] = a;
        siz[a] += siz[b];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> edges;
    for (int i = 0; i <= m; ++i)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i = 1; i <n ; ++i) make(i);
    int cost = 0;
    for(auto &edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        cost +=wt;
        cout<<u<<" "<<v<<endl;

    }
    cout<<cost<<endl;

    
}