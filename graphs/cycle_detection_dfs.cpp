#include <iostream>
#include <vector>
using namespace std;
class solution
{
    bool check_cycle(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (check_cycle(it, node, vis, adj))
                    return true;
            }
            else if (it != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    bool iscycle(int v, vector<int> adj[]) //TC - O(N+E) AND SC = O(N+E) + O(N) + O(N)---->E is travelling through adjacent nodes
    {
        vector<int> vis(v + 1, 0);
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                if (check_cycle(i, -1, vis, adj))
                    return true;
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
        adj[v].push_back(u);
    }
    solution s;
    if (s.iscycle(n, adj))
    {
        cout << "Cycle is present";
    }
    else
    {
        cout << "Cycle is not present";
    }
    return 0;
}