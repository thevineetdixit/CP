// find cycle in directed graph and print the nodes coming in the cycle
// take a visited for every dfs call and then backtrack (mark 0)
// when coming out of that path
// also take a parent array to find the cycle path

/*
Summary of the Approach:
1. Start DFS from every unvisited node.
2. While doing DFS:
   Mark the current node in both visited[] and recstack[].
   -> For each neighbor:
      If it's unvisited continue DFS.
   -> If it's already in recstack[] cycle found.
3. If cycle is found:
   -> Use parent[] to backtrack and reconstruct the cycle path.
4. If no cycle is found in the entire graph print "IMPOSSIBLE".
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> adj;
vector<int> visited;
vector<bool> rec_stack;
vector<int> parent;

int cycle_start = -1;
int cycle_end = -1;


bool dfs(int u)
{
    visited[u] = 1;
    rec_stack[u] = 1;

    for(auto &v : adj[u])
    {
        if(!visited[v])
        {
            parent[v] = u;

            if(dfs(v))
            return true;
        }

        else if(rec_stack[v])
        {
            cycle_end = u;
            cycle_start = v;

            return true;
        }
    }

    // Backtracking:
    // u is no longer part of the current DFS path
    rec_stack[u] = 0;

    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

  
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    rec_stack.resize(n + 1, 0);
    parent.resize(n + 1, -1);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    // Take a rec_stack for recursion
    // and visited for exploration of DFS

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
            {
                break;
            }
        }
    }


    // If cycle not found
    if(cycle_end == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }


    // Otherwise extract the cycle

    vector<int> cycle;

    cycle.push_back(cycle_start);

    for(int v = cycle_end; v != cycle_start; v = parent[v])
    {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size()<< '\n';

    for(auto &i : cycle)
    {
        cout << i << " ";
    }

    cout << '\n';

    return 0;
}