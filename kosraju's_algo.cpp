#include <bits/stdc++.h>
using namespace std;
void toposort(vector<int> adj[], stack<int> &st, vector<int> &vis, int node)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if(!vis[it])
        {
        toposort(adj, st, vis, it);
        }
    }
    st.push(node);
}
void kosaraju(vector<int> transpose[], int node,vector<int>&vis)
{
    cout << node<<" ";
    vis[node]=1;
    for (auto it : transpose[node])
    {
        if(!vis[it])
        {
        kosaraju( transpose, it,vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <=m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int> st;
    vector<int> vis(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            toposort(adj, st, vis, i);
        }
    }

    vector<int> transpose[n + 1];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;

        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if(!vis[node])
        {
            cout<<"SCC: ";
            kosaraju(transpose, node ,vis);
            cout<<endl;
            
        }


    }
}