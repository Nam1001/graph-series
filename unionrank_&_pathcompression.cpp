#include<bits/stdc++.h>
using namespace std;
int parent[10000];
int rank1[10000];
void makeset( int n)
    {
         for(int i=1;i<=n;i++)
         {
            parent[i]=i;
            rank1[i]=0;
         }
    }

void union1(int u,int v)
{
    if(rank1[u]>rank1[v])
    {
        parent[v]=u;
    }
    else if(rank1[v]>rank1[u])
    {
        parent[u]=v;
    }
    else
    {
        parent[u]=v;
        rank1[v]++;
    }
}
int findparent(int node)
{
    if(node==parent[node])
    {
        return node;
    }
    return parent[node]= findparent(parent[node]);
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    makeset(n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        union1(u,v);

    }
    if(findparent(2)!=findparent(3))
    {
        cout<<"different comopent";
    }
    else{
        cout<<"same";
    }
    

return 0;
}