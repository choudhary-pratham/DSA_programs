#include <iostream>
#include <vector>
using namespace std;
class solution
{
    void print_dfs(int node, vector<int> &vis, vector<int> &dfs, vector<int> adj[])
    {
        dfs.push_back(node);
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                print_dfs(it, vis, dfs, adj);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int v, vector<int> adj[])//TC - O(N+E) AND SC = O(N+E) + O(N) + O(N)---->E is travelling through adjacent nodes
    {
        vector<int> dfs;
        vector<int> vis(v + 1, 0);
        for (int i = 1; i <= v + 1; i++)
        {
            if (!vis[i])
            {
                print_dfs(i, vis, dfs, adj);
            }
        }
        return dfs;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> dfs;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution s;
    dfs = s.dfsOfGraph(n, adj);
    for (auto it = dfs.begin(); it != dfs.end(); it++)
    {
        cout << (*it) << " ";
    }
    return 0;
}