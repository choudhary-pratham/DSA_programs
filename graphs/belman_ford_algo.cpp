#include <bits/stdc++.h>
using namespace std;
//TC- O(N-1)*O(E)
//SC - O(N)
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int third)
    {
        u = first;
        v = second;
        wt = third;
    }
};

int main()
{
    int m, n;
    cin >> n >> m;
    vector<node> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;
    vector<int> dist(n, 1000000);
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : adj)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int flag = 1;
    for (auto it : adj)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }
    else
    {
        cout << "NEGATIVE CYCLE" << endl;
    }

    return 0;
}