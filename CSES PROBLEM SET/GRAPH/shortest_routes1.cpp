#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }

    vector<long long>dist(n+1,LLONG_MAX);
    vector<bool> explored(n+1,0);

    priority_queue<pii,vector<pii>,greater<pii>> pq;

    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty())
    {
        int node = pq.top().second;
        // int wt = pq.top().first;
        pq.pop();

        if(explored[node])continue;
        explored[node]=1;

        for(auto edge : adj[node])
        {
            int neib = edge.first;
            int d = edge.second;
            if(!explored[neib] && dist[neib] > dist[node] + d)
            {
                dist[neib] = dist[node] + d;
                pq.push({dist[neib], neib});
            }
        }
    }

    for(int i=1;i<n+1;i++)
    cout<<dist[i]<<" ";

    return 0;
}