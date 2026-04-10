#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<int>ans;
vector<bool>visited;
bool flag = 0;
int node;

void dfs(int src,vector<vector<int>> &adj)
{
    if(flag)return;
    visited[src]=1;

    for(auto &neib:adj[src])
    {
        if(neib != parent[src])
        {
            if(flag)break;;
            if(visited[neib]==1)
            {
                parent[neib] = src;
                ans.push_back(neib);
                flag = 1;
                node = neib;
                break;
            }
            parent[neib]= src;
            dfs(neib,adj);
        }
    }

}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    parent.resize(n+1,-1);
    visited.resize(n+1,0);


    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) // handle disconnected graph
    {
        if(!visited[i])
        {
            dfs(i,adj);
        }
    }

    if(!flag)
    cout<<"IMPOSSIBLE";
    else
    {
        int temp = parent[node];
        while(temp != node && temp != -1)
        {
            ans.push_back(temp);
            temp = parent[temp];
        }
        ans.push_back(node);
        
        cout<<ans.size()<<"\n";

        for(int i=ans.size()-1;i>=0;i--)
        {
            cout<<ans[i]<<" ";
        }
    }

    return 0;
}
