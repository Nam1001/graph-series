#include<bits/stdc++.h>
using namespace std;
bool topo(int V,vector<int>adj[])
{
    queue<int>q;
    vector<int>indegree(V+1,0);
    for(int i=1;i<=V;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=1;i<=V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        count++;
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    if(count==V)
    {
         return false;
    }
    return true;
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
  bool a=topo(n,adj);
  cout<<a;
  return 0;
}