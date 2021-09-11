#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{
public:
    vector<int> BfsOfGraph(int v, vector<int> adj[]) //TC - O(N+E) AND SC = O(N+E) + O(N) + O(N)---->E is travelling through adjacent nodes
    {
        vector<int> bfs;
        vector<int> vis(v + 1, 0);
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty())
                {
                    int node;
                    node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for (auto it : adj[node])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return bfs;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> bfs;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution s;
    bfs = s.BfsOfGraph(n, adj);
    for (auto it = bfs.begin(); it != bfs.end(); it++)
    {
        cout << (*it) << " ";
    }
    return 0;
}