#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//time complexity=O(N+E)
//space complexity=O(N)+O(N)
//auxiliary space complexity O(N)
// topological sort is only possible for directed acyclic graph(DAG)
//a topolocial sort means sorting the nodes in a way like if there exists 
// two sets u and v such that u->v then u will always come before v.
//it is not possible for undirected graph since u->v also means v->u
//it is also not possible for directed cyclic graph since the u->v law violates

class solution
{
    void findtoposort(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                findtoposort(it, st, vis, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> toposort(int v, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                findtoposort(i, st, vis, adj);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
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