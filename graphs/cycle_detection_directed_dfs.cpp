#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// time complexity=O(N+E)
// space complexity=O(N+E) + O(N) + O(N)

class solution
{
    bool check_cycle(int node, int vis[], int dfsvis[], vector<int> adj[])
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (check_cycle(it, vis, dfsvis, adj))
                {
                    return true;
                }
            }
            else if (dfsvis[it])
            {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }

public:
    bool iscycle(int v, vector<int> adj[])
    {
        int vis[v + 1], dfsvis[v + 1];
        memset(vis, 0, sizeof(vis));
        memset(dfsvis, 0, sizeof(dfsvis));
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                if (check_cycle(i, vis, dfsvis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    solution s;
    if (s.iscycle(n, adj))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}