#include <bits/stdc++.h>
using namespace std;
// time complexity - O(4alpha) = constant
// space complexity - O(2N)
int r[100000];
int parent[100000];

void makeset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        r[i] = 0;
        parent[i] = i;
    }
}

int findpar(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findpar(parent[node]);
}

void union_(int u, int v)
{
    u = findpar(u);
    v = findpar(v);
    if (r[u] < v)
    {
        parent[u] = v;
    }

    else if (r[u] > v)
    {
        parent[v] = u;
    }

    else
    {
        parent[u] = v;
        r[v]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    makeset(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        union_(u, v);
    }
    if (findpar(2) != findpar(3))
    {
        cout << "They dont have the same parent node and hence they belong to different components";
    }
    else
    {
        cout << "They have the same parent node and hence they belong to the same component";
    }
    return 0;
}