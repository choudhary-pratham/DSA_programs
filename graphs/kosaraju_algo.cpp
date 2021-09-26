#include <bits/stdc++.h>
using namespace std;
// TC - O(N+E)
//SC - O(N+E) + O(N) + O(N)
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto iter : adj[node])
    {
        if (!vis[iter])
        {
            dfs(iter, vis, adj, st);
        }
    }
    st.push(node);
}

void revdfs(int node, vector<int> transpose[], vector<int> &vis)
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revdfs(it, transpose, vis);
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> transpose[n + 1];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cout << "SCC:" << endl;
            revdfs(node, transpose, vis);
            cout << endl;
        }
    }
    return 0;
}