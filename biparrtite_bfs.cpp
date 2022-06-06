#include<bits/stdc++.h>
using namespace std;
bool checkbipartite(int node,vector<int>&color,vector<int>adj[])
{
   queue<int>q;
   color[node]=0;
   q.push(node);
   while(!q.empty())
   {
       int src=q.front();
       q.pop();
       for(auto it:adj[src])
       {
           if(color[it]==-1)
           {
           color[it]=1-color[src];
           q.push(it);
           }
           else if(color[it]==color[src])
           {
               return false;
           }
       }
   }
   return true;
}
bool isbipartite(int v,vector<int>adj[])
{
    vector<int>color(v+1,-1);
    for(int i=1;i<=v;i++)
    {
        if(color[i]==-1)
        {
            if(!checkbipartite(i,color,adj))
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
    bool a=isbipartite(n,adj);
    if(a)
    {
        cout<<"bipartite";

    }
    else{
        cout<<"no bipartite";
    }
    return 0;
}
