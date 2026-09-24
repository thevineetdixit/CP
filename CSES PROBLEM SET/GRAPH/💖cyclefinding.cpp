/*Initialize:

dist[v] = 0 for every v
parent[v] = -1


        Bellman-Ford
             │
             ▼
     Relax all edges n times
             │
             ▼
   Was something relaxed
   during nth iteration?
          /       \
        NO         YES
        │           │
        ▼           ▼
       NO         x = relaxed vertex
       cycle          │
                      │
                      ▼
              Move parent n times
                      │
                      ▼
                x is inside
                negative cycle
                      │
                      ▼
              Follow parent[]
              until x again
                      │
                      ▼
                 Construct cycle

*/



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,pair<int,int>> p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<p> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,{v,w}});
    }

    //main part is dist of every node is 0 which shows that every one is source 
    vector<ll> dist(n+1,0);
    // relaxant array 
    vector<int>relaxant(n+1,-1);

    //ab dekho ye h jaadu code for bellman why?
    //coz no nth itreation alag se ,hum har baar x ko -1 krde rhe h 
    // so nth iteration me agr x change hoga to mtlb kuchh to relax hua h,
    //agr kuchh relax hua h to usko daalo peti me aur uska relaxant bhi 
    int x = -1;
    for(int i=0;i<n;i++)
    {
        x = -1;
        for(auto &e:edges)
        {
            int u = e.first,v = e.second.first, w = e.second.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u]+ w;   
                relaxant[v] = u;
                x = v;
            }
        }
    }

    if(x == -1)
    {
        cout<<"NO";
        return 0;
    }

    //ab agr h cycle to ghamasaan h
    //in worst case we may check n times to find cycle llike poori hi cycle ho 
    for(int i=0;i<n;i++)
    x = relaxant[x];

    //ab cycle print krna h 
    vector<int> cycle;
    for(int curr = x;;curr = relaxant[curr])
    {
        cycle.push_back(curr);
        if(curr == x && cycle.size()> 1)
        break;
    }

    reverse(cycle.begin(),cycle.end());

    cout<<"YES"<<endl;
    for(auto i:cycle)
    cout<<i<<" ";
    

    return 0;
}