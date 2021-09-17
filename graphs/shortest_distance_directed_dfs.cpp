#include <bits/stdc++.h>
using namespace std;

// time complexity is O(N+E)
// space complexity is O(N+E) + O(N) + O(N)

class solution
{
    void toposort(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                toposort(it.first, vis, adj, st);
            }
        }
        st.push(node);
    }

public:
    void directed_dfs(int v, int src, vector<pair<int, int>> adj[])
    {
        stack<int> st;
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                toposort(i, vis, adj, st);
            }
        }
        int distance[v];
        for (int i = 0; i < v; i++)
        {
            distance[i] = INT_MAX;
        }
        distance[src] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (distance[node] != INFINITY)
            {
                for (auto it : adj[node])
                {
                    if (distance[node] + it.second < distance[it.first])
                    {
                        distance[it.first] = distance[node] + it.second;
                    }
                }
            }
        }
        for (int i = 0; i < v; i++)
        {
            (distance[i] == INFINITY) ? cout << "INFINITY" : cout << distance[i] << " ";
        }
    }
};

int main()
{
    int m, n, src;
    cin >> m >> n;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    solution s;
    cout << "Enter the source:" << endl;
    cin >> src;
    s.directed_dfs(n, src, adj);
    return 0;
}