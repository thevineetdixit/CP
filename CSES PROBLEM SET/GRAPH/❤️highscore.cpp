//this is high score problem
//given a graph directed,can have cycles ,
// return the longest distance from source to last node
//clearly not a dijkstra & since edges can be negative too
// so it a very good problem,longest path in a negative edge graph 


// ********************BELLMAN FORD ALGO *****************
 /*
1-> SINGLE SOURCE  shortest path algo 
2-> works with WEIGHTED DIRECTED/ UNDIRECTED graph   
3-> can handle negative edge weights
4-> can detect negative wegith cycles (nth time relaxation changes)
5-> simpler than dijkstra but have higher TC i.e O(V*E) + E 
*/

/*
basic bellman ford algo 

vector<int>dist(n,INT_MAX);
n = vertec(V)

dist[src]=0;

for(int i=0;i<n-1;i++)
for(auto &e: edges)
int u = e[0],v = e[1],wt = e[2];
if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
dist[v] = dist[u] + wt;

last time relax
for(auot &e:edges)
if(dist[u] != INT_MAx && dist[u] + wt < dist[v])
return -1;

*/


//               🔥🔥🔥🔥ROAD-MAP FOR THIS QUESTION
//FIRST DO BELLMAN FORD V-1 TIMES THEN VTH TIMES REALX TO FIND WHICH NODES ARE IN THE CYCLES
// AFTER FINDING THESE NODES,APPLY BFS FROM SOURCE(1) TO CHECK WHETHER YOU WILL GO TO THOSE CYCLE NODES OR NOT
// THEN CHECK WHETHER FROM THESE NODES YOU CAN GO TO LAST NODE OR NOT
// IF YOU CAN GO FROM SRC TO THOSE NODES WHICH THEN GOES TO END NODES,RETURN -1 ;
// ELSE NOT 



#include<bits/stdc++.h>
using namespace std; 

typedef pair<int,pair<int,int>> P;
typedef long long ll;


int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1); //not for bellman but for later BFS
    vector<P> edges(m);// for bellman
    

    //taking the input m lines with u v wt
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>> u>> v>> wt;
        edges.push_back({u,{v,wt}});
        adj[u].push_back(v);//it will just define reachability
    }

    // BELLMAN LAGAO ULTA WALA 
    vector<ll>dist(n+1,LLONG_MIN); 
    dist[1] = 0;

    for(int i=0;i<n-1;i++)
    for(auto &e:edges)
    {
        int u = e.first, v= e.second.first, wt= e.second.second;
        if(dist[u] != LLONG_MIN && dist[u] + wt > dist[v])
        dist[v] = dist[u] + wt;
    }


    //nth relaxation and store cyclic nodes v
    set<int> cycle_nodes;
    for(auto &e:edges)
    {
        int u = e.first, v= e.second.first, wt= e.second.second;
        if(dist[u] != LLONG_MIN && dist[u] + wt > dist[v])
        cycle_nodes.insert(v);
    }

    // now bfs from 1 to all these nodes to find reachability 
    vector<bool>visited(n+1,0);
    queue<int>q,cycle_q;//cycle_q for the nodes that are rachable from 1
    q.push(1);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(visited[u])
        continue;
        visited[u] =1;

        //agr ye node cycle wali h to isko cycle-q me daaldo
        if(cycle_nodes.count(u))
        cycle_q.push(u);

        for(auto &v:adj[u])
        if(!visited[v])
        q.push(v);
    }


    // now bfs from all these nodes to n 
    //check if any rachable cycle_q node can reach nth node or not

    visited.assign(n+1,0);
    bool can_reach_end = 0;

    while(!cycle_q.empty())
    {
        int u = cycle_q.front();cycle_q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        //agr ye node nth node h mtlb wo bsdk pahuch gye end tak jop cyclic the to chud gye guru ho gya na
        if(u == n)
        {
            can_reach_end =1;
            break;
        }

        for(auto &v:adj[u])
        if(!visited[v])
        cycle_q.push(v);
    }

    
    if(can_reach_end)
    cout<< "-1"<<endl;
    else 
    cout<<dist[n];

    return 0;
}