#include<iostream>
using namespace std;
int main()
{
    int m,n; //n,m->number of nodes of the graph and edges(in this case the number of lines) respectively.
    cin>>n>>m;
    // declare adjacency matrix
    int adj[n+1][n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;// if it is undirected graph then include this line.
    }
    return 0;
}