#include <bits/stdc++.h>
using namespace std;
// time complexity - O(N+E)
// space complexity - O(N)
class solution
{
public:
    void dfs(int node, int parent, int &timer, vector<int> &tin, vector<int> &low, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;

            if (!vis[it])
            {
                dfs(it, node, timer, tin, low, vis, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node])
                {
                    cout << node << " - " << it << endl;
                }
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
};

int main()
{
    solution s;
    int m, n;
    cin >> m >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n + 1, -1);
    vector<int> low(n + 1, -1);
    vector<int> vis(n + 1, 0);
    int timer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            s.dfs(i, -1, timer, tin, low, vis, adj);
        }
    }
    return 0;
}