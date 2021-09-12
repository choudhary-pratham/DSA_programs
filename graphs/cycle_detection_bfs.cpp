#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{
    bool check_cycle(int i, vector<int> &vis, vector<int> adj[]) //TC - O(N+E) AND SC = O(N+E) + O(N) + O(N)---->E is travelling through adjacent nodes
    {
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = true;
        while (!q.empty())
        {
            int node, par;
            node = q.front().first;
            par = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push({it, node});
                }
                else if (it != par)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool iscycle(int v, vector<int> adj[])
    {
        vector<int> vis(v + 1, 0);
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                if (check_cycle(i, vis, adj))
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
        cout << "This Graph contains a cycle";
    }

    else
    {
        cout << "This Graph does not contain a cycle";
    }
    return 0;
}