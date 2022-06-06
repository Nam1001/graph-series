#include<bits/stdc++.h>
using namespace std;
void topobfs(int v,vector<int>adj[])
{
    queue<int>q;
    vector<int>indegree(v+1,0);
    for(int i=1;i<=v;i++)
    {
       for(auto it:adj[i])
       {
           indegree[it]++;
       }
    }
    for(int i=1;i<=v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        topo.push_back(node);
        q.pop();
       
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    for(int i=0;i<topo.size();i++)
    {
        cout<<topo[i];
    }
  

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
     topobfs(n,adj);
   
    
}