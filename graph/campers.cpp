#include <bits/stdc++.h>
using namespace std;
// disjoint set union
const int N = 1e5 + 10;
int par[N];
int siz[N];
multiset<int> sz;

void make(int v)
{
    par[v] = v;
    siz[v] = 1;
    sz.insert(1);
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void merge(int a , int b){
sz.erase(sz.find(siz[a]));
sz.erase(sz.find(siz[b]));

sz.insert(siz[a]+siz[b]);

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
        merge(a,b);
        siz[a] += siz[b];
    }
}

int main()
{
    int n ,q;
    cin>>n>>q;
    for(int i = 1 ; i <=n;++i){
        make(i);
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
        if(sz.size()==1){
            cout<<0<<endl;
        }else{
            int mn = *(sz.begin());
            int mx = *(--sz.end());
            cout<<mx-mn<<endl;
        }
    }

  
}