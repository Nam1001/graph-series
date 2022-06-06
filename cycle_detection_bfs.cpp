#include<bits/stdc++.h>
using namespace std;
bool checkcycle(int src,vector<int> adj[],vector<int> &vis ,int v)
{
    queue<pair<int,int>>q;
    vis[src]=true;
    q.push({src,-1});
    while(!q.empty())
    {
    int node=q.front().first;
    int parent=q.front().second;
    q.pop();
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            q.push({it,node});
            vis[it]=true;
        }
        else if(parent!=it)
        {
            return true;
        }
    }
    }

return false;

}
bool cycle(int n,vector<int>adj[])
{
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
           if(checkcycle(i,adj,vis,n))
           {
               return true;
           }
        }
    }
    return false;
}
int main()
{
    int n,m;
    cout<<"enter the vertex";
    cin>>n;
    cout<<"enter the edges";
    cin>>m;
    vector<int>adj[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
         
    }
    bool a=cycle(n,adj);
    cout<<a;
}