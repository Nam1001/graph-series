#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> adj;
    vector<int> dis(n + 1, INT_MAX);
    for (int i = 1; i <= m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj.push_back(node(u, v, wt));
    }
    int src = 0;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : adj)
        {
            if (dis[it.u] + it.wt < dis[it.v])
            {
                dis[it.v] = dis[it.u] + it.wt;
            }
        }
    }
    int flg = 0;
    for (auto it : adj)
    {
        if (dis[it.u] + it.wt < dis[it.v])
        {
            flg = 1;
            break;
        }
    }

    if (flg == 1)
    {
        cout << "negative cyle";
    }
    else{
        for(int i=1;i<n;i++)
        {
            cout<<dis[i]<<" ";
        }
    }
}