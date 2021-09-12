#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class solution
{
    bool check_bipartite(int node,int colour[],vector<int>adj[])
    {
        for(auto it : adj[node])
        {
            if(colour[it] == -1)
            {
                colour[it] = 1 - colour[node];
                if(!check_bipartite(it, colour,adj))
                {
                    return false;
                }
            }
            else if(colour[it] == colour[node])
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isbipartite(int v, vector<int>adj[])
    {
        int colour[v+1];
        memset(colour,-1,sizeof(colour));
        for(int i=1;i<=v;i++)
        {
            if(colour[i] == -1)
            {
                colour[i] = 1;
                if(!check_bipartite(i,colour,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solution s;
    if(s.isbipartite(n,adj))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}