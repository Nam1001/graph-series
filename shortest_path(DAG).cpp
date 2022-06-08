#include <bits/stdc++.h>
using namespace std;
void toposort(int node, vector<int> &vis, vector< pair<int,int>> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            toposort(it.first, vis, adj, st);
        }
    }
    st.push(node);
}
void shortest_path(int v, vector<pair <int,int>> adj[],int src)
{
    vector<int> vis(v + 1, 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            toposort(i, vis, adj, st);
        }
    }
    int dist[v];
  
    for (int i = 0; i < v ; i++)
    {
        dist[i]=INT_MAX;
    }
      dist[src]=0;
    while (!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!=INFINITY)
        {
            for(auto it:adj[node])
            {
              if(dist[node]+it.second<dist[it.first])
              {
                   dist[it.first]=it.second+dist[node];
              }
            }
        }
    }
    for (int i = 0; i < v; i++) 
		(dist[i] == INT_MAX)? cout << "INF ": cout << dist[i] << " "; 

}

int main()
{

    int n, m;
    cin >> n;

    cin >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    shortest_path(n, adj, 0);

    return 0;
}