#include<bits/stdc++.h>
using namespace std;
bool dfscycle(int node,vector<int>&vis,vector<int>adj[],vector<int>&dfsvis)
{
     vis[node]=1;
     dfsvis[node]=1;
     for(auto it:adj[node])
     {
         if(!vis[it])
         {
             if(dfscycle(it,vis,adj,dfsvis))
             {
                 return true;
             }
         }
         else if(dfsvis[it]==1)
         {
             return true;
         }
     }
     dfsvis[node]=0;
     return false;
}
bool cycle(int v,vector<int>adj[])
{
    vector<int> vis(v+1,0);
    vector<int>dfsvis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
           if( dfscycle(i,vis,adj,dfsvis))
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
        
         
    }
    bool a=cycle(n,adj);
    if(a)
    {
        cout<<"cycle detected";

    }
    else{
        cout<<"no cycle detected";
    }
}