#include<bits/stdc++.h>
using namespace std;
bool cycledfs(int src,int parent,vector<int>&vis,vector<int>adj[])
{
    vis[src]=1;
    for(auto it: adj[src])
    {
       if(vis[it]==0)
       {
           if(cycledfs(it,src,vis,adj))
           {
               return true;
           }
           
       }
       else if(parent!=it)
           {
               return true;
           }
    }
    return false;
}

bool cycle(int v,vector<int>adj[])
{
    vector<int>vis(v+1,0);
    
       for(int i=1;i<=v;i++)
        {

            if(vis[i]==0)
            {
                if(cycledfs(i,-1,vis,adj))
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
    if(a)
    {
        cout<<"cycle detected";

    }
    else{
        cout<<"no cycle detected";
    }
}