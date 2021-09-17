#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// time complexity is O(N+E)
// space complexity is O(N+E) + O(N) + O(N)

class solution
{
public:
    bool iscycle(int v, vector<int> adj[])
    {
        vector<int> indegree(v, 0);
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt == v)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    solution s;
    if (s.iscycle(n, adj))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}