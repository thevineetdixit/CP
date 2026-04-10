#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    vector<int>dist(n+1,INT_MAX);
    vector<int> parent(n+1,-1);

    queue<int>q;
    q.push(1);
    parent[1]=1;
    dist[1]=0;

    vector<bool>visited(n+1,0);
    visited[1]=1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto &neib: adj[node])
        {
            if(!visited[neib] )
            {
                dist[neib]= dist[node]+1;
                visited[neib]=1;
                q.push(neib);
                parent[neib]= node;
            }
        }
    }

    if(dist[n]==INT_MAX)
    cout<<"IMPOSSIBLE";
    else
    {
        //an lagega path compression;
        stack<int>st;
        int curr = n;
        while(curr!= parent[curr])
        {
            st.push(curr);
            curr = parent[curr];
        }
        st.push(1);
        
        cout<<st.size()<<"\n";

        while(!st.empty())
        {
            int x = st.top();
            cout<<x<<" ";
            st.pop();
        }
    }

    return 0;
}