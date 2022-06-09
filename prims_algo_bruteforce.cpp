#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int parent[n];
    int key[n];
    bool mstset[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1, key[i] = INT_MAX, mstset[i] = false;
    }
    key[0] = 0;
    parent[0]=-1;
    for (int i = 0; i < n - 1; i++)
    {
        int mini = INT_MAX, u;
        for (int v = 0; v < n; v++)
        {
            if (mstset[v] == false && key[v] < mini)
            {
                mini = key[v], u = v;
            }
        }
        mstset[u] = true;
        for (auto it : adj[u])
        {
            if (mstset[it.first] == false && it.second < key[it.first])
            {
                key[it.first] = it.second, parent[it.first] = u;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "---" << i
             << "\n";
    }
}