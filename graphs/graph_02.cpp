// storing graphs in cpp method -2
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    // vector<int>adj[n+1];  if weight is not mentioned.
    vector<pair<int,int>>adj[n+1]; // if weight is mentioned.
    for(int i=0;i<m;i++)
    {
        int u,v,wt;// here wt is the weight of the edges(if not mentioned assume it as unit)
        cin>>u>>v>>wt;

        // logic:
        // we create an vector adjacent array and push_back values according the edges each node 
        // share with the other.
        // time complexity : O(N+2E)+2E -> E is the number of edges. still better because it is less than n*n
        // if no weights are given:
        // adj[u].push_back(v);
        // adj[v].push_back(u);// if it is a undirected graph

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});// if it is a undirected graph
    }
    return 0;
}