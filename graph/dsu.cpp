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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        make(i);
    }
    int u, v;
    while (k--)
    {
        cin >> u >> v;
        Union(u, v);
    }
    int con = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (find(v) == v)
            con++;
    }
}