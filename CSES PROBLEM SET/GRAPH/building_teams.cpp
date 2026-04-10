#include<bits/stdc++.h>
using namespace std;

bool flag = 0;

void isBipartite(vector<vector<int>>& graph, vector<int>& color) {
    int V = graph.size();
    queue<int> q;

    for(int i = 1; i < V; i++)
    {
        if(color[i] == -1)
        {
            color[i] = 0;
            q.push(i);

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int j = 0; j < graph[node].size(); j++)
                {
                    if(color[graph[node][j]] == -1)
                    {
                        color[graph[node][j]] = (color[node] + 1) % 2;
                        q.push(graph[node][j]);
                    }
                    else
                    {
                        if(color[graph[node][j]] == color[node])
                        {
                            flag = 1;
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> color(n + 1, -1);

    isBipartite(adj, color);

    if(flag)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            cout << color[i] + 1 << " ";
        }
    }
}