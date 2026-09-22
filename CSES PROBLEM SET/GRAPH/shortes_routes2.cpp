#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<long long>> adj(n+1, vector<long long>(n+1, LLONG_MAX));

    for(int i=1;i<=n;i++) adj[i][i] = 0;

    for(int i=0;i<m;i++)
    {
        int u,v;
        long long wt;
        cin>>u>>v>>wt;

        // FIX: you forgot to add edges
        adj[u][v] = min(adj[u][v], wt);
        // if graph is undirected, also add:
        adj[v][u] = min(adj[v][u], wt);
    }

    for(int via=1;via<=n;via++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(adj[i][via] != LLONG_MAX && adj[via][j] != LLONG_MAX)
            adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
    }

    for(int i=0;i<q;i++)
    {
        int u,v;
        cin>>u>>v;

        if(adj[u][v] == LLONG_MAX)
            cout<<-1<<"\n";
        else
            cout<<adj[u][v]<<"\n";
    }

    return 0;
}