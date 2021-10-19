#include <bits/stdc++.h>
using namespace std;
// time complexity - O(4alpha) = constant
// space complexity - O(2N)
class DSU
{
private:
    vector<int>parent,size,rank;
public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }
    int findpar(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }
    void unionSize(int a,int b)
    {
        int pa = findpar(a);
        int pb = findpar(b);
        if(pa == pb)
        {
            return;
        }
        else if(size[pa]<size[pb])
        {
            parent[pa] = pb;
            size[pb]+=size[pa];
        }
        else if(size[pa]>size[pb])
        {
            parent[pb] = pa;
            size[pa]+=size[pb];
        }
        else
        {
            parent[pb] = pa;
            size[pa]+=size[pb];
        }
    }
    void unionRank(int a,int b)
    {
        int pa = findpar(a);
        int pb = findpar(b);
        if(pa == pb)
        {
            return;
        }
        else if(rank[pa]<rank[pb])
        {
            parent[pa] = pb;
        }
        else if(rank[pa]>rank[pb])
        {
            parent[pb] = pa;
        }
        else if(rank[pa] == rank[pb])
        {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
    
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        dsu.unionSize(u, v);
    }
    if (dsu.findpar(2) != dsu.findpar(3))
    {
        cout << "They dont have the same parent node and hence they belong to different components";
    }
    else
    {
        cout << "They have the same parent node and hence they belong to the same component";
    }
    return 0;
}
