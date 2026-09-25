/*Your task is to find the k shortest flight routes from Syrjälä to Metsälä. A route can visit the same city several times.
Note that there can be several routes with the same price and each of them should be considered (see the example).*/


// *******(kmlog(kn))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<p>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    //in this problem we have to find k shortest path from s to d in O(nlogn)
    //the idea is when we itreate djikstra from 1 to n ,then for a node the first k marked distances are the shortest i.e agr last node pr k times hum relax kr chuke h to uske pass already k shortest distance h nodepe

    //apply basic djikstra with dist a vector of upto k size and then just return the dist[n];

    priority_queue<p,vector<p>,greater<p>> pq;
    vector<vector<ll>> dist(n+1);
    pq.push({0,1});

    //hum while me hi k dist push krte rhenge 
    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();

        if(dist[u].size()>=(ll)k)continue;
        dist[u].push_back(d);//jo bhi dist mila wo kth min hoga

        for(auto [v,w] : adj[u])// * saare edge push kro chahe repeat ho
        pq.push({d+w,v});//bs saare edges daalo,baaki ho jayega

    }


    for(int i = 0;i<k;i++)
    {
        cout<<dist[n][i]<<" ";
    }

    cout<<endl;


    return 0;
}