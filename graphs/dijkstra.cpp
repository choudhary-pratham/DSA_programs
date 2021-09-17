#include <bits/stdc++.h>
using namespace std;
// time complexity is O(NlogN)
// space complexity is O(N+E) + O(N) + O(N)
class solution
{
public:
    void bfs(int v, int src, vector<pair<int, int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(v + 1, INT_MAX);
        distTo[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for (auto it : adj[prev])
            {
                int next = it.first;
                int nextdist = it.second;
                if (distTo[prev] + nextdist < distTo[next])
                {
                    distTo[next] = distTo[prev] + nextdist;
                    pq.push({distTo[next], next});
                }
            }
        }
        for (int i = 1; i <= v; i++)
        {
            cout << distTo[i] << " ";
        }
    }
};
int main()
{
    int m, n, src;
    cin >> m >> n;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    solution s;
    cout << "Enter the source:" << endl;
    cin >> src;
    s.bfs(n, src, adj);
    return 0;
}