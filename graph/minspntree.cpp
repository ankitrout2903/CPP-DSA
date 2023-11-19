#include <bits/stdc++.h>
using namespace std;
// disjoint set union
const int N = 2e3 + 10;
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
    int n;
    cin >> n;
    vector<pair<int,int>> ct(n+1);
    for(int i = 1; i<=n;++i){
        cin>>ct[i].first>>ct[i].second;
    }

    vector<int> c(n+1),k(n+1);
     for(int i = 1; i<=n;++i){
        cin>>c[i];
    }
     for(int i = 1; i<=n;++i){
        cin>>k[i];
    }

    vector<pair<int,pair<int,int>>> edges;

    for(int i = 1;i<=n;++i){
        edges.push_back({c[i],{0,i}});
    }

    for(int i = 1 ; i <=n;++i){
        for(int j = i+1;j<=n;++j){
            int dist = abs(ct[i].first-ct[j].first)+ abs(ct[i].second-ct[j].second);
            long long cost = dist * 1LL * (k[i]+k[j]);
            edges.push_back({cost,{i,j}});
        }
    }
   
    sort(edges.begin(),edges.end());
    for(int i = 1; i <n ; ++i) make(i);
    long long tcost = 0;
    vector<int> ps;
    vector<pair<int,int>> cn;
    for(auto &edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        tcost +=wt;
        if(u==0 || v==0){
            ps.push_back(max(u,v));
        cout<<u<<" "<<v<<endl;

    }else{
        cn.push_back({u,v});
    }
    }
    cout<<tcost<<endl;
    cout<<ps.size()<<endl;
    for(int st : ps){
        cout<<st<<" ";
    }
    cout<<endl;

    cout<<cn.size()<<endl;
    for(auto &cns : cn){
        cout<<cns.first<<" "<<cns.second<<endl;
    }


    
}