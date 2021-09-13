#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity=O(N+E)
// space complexity=O(N)+O(N)
//Auxiliary space complexity - O(N)

class solution
{
public:
    vector<int> toposort(int v, vector<int> adj[])
    {
        vector<int> indegree(v, 0);
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> topo;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    solution s;
    topo = s.toposort(n, adj);
    for (auto it : topo)
    {
        cout << it << " ";
    }
    return 0;
}