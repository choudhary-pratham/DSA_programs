#include <bits/stdc++.h>
using namespace std;

// time complexity is O(N+E)
// space complexity is O(N+E) + O(N) + O(N)

class solution
{
public:
    void BFS(int v, int src, vector<int> adj[])
    {
        int distance[v];
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            distance[i] = INT_MAX;
        }
        distance[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (distance[node] + 1 < distance[it])
                {
                    distance[it] = distance[node] + 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < v; i++)
        {
            cout << distance[i] << " ";
        }
    }
};

int main()
{
    int m, n, src;
    cin >> m >> n;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution s;
    cout << "Enter source node : " << endl;
    cin >> src;
    s.BFS(n, src, adj);
    return 0;
}