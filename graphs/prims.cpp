// for minimum spanning tree 
#include <bits/stdc++.h>
using namespace std;
// time complexity - O(NlogN)
// space complexity - O(N) + O(N) + O(N) + O(N) + O(N+E)
class solution
{
public:
    void prims_algo(int v, vector<pair<int, int>> adj[])
    {
        int key[v];
        int parent[v];
        bool mstset[v];
        for (int i = 0; i < v; i++)
        {
            key[v] = INT_MAX;
            parent[v] = -1;
            mstset[v] = false;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        key[0] = 0;
        parent[0] = -1;

        pq.push({0, 0});
        for (int i = 0; i < v - 1; i++)
        {
            int u = pq.top().second;
            pq.pop();
            mstset[u] = true;
            for (auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;
                if (mstset[v] == false && key[v] > weight)
                {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }
        for (int i = 1; i <= v; i++)
        {
            cout << parent[i] << "-" << i << endl;
        }
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    solution s;
    s.prims_algo(n, adj);
    return 0;
}