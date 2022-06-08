#include <bits/stdc++.h>
using namespace std;
void shortpath(int v, vector<pair<int, int>> adj[], int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap pair(dist,from)
    vector<int> dis(v+1, INT_MAX);
    dis[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            if (dis[node] + it.second < dis[it.first])
            {
                dis[it.first] = dis[node] + it.second;
                pq.push(make_pair(dis[it.first], it.second));
            }
        }
    }
    cout << "The distances from source " << src << " are : \n";
    for (int i = 1; i <= v; i++)
        cout << dis[i] << " ";
    cout << "\n";
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
        adj[v].push_back({u, wt});
    }
    shortpath(n, adj, 1);

    return 0;
}