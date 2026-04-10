#include<bits/stdc++.h>
using namespace std;

//IT IS CLASSIC COMPONENTS PROBLEM
//BASIC ULTIMATE PARENT CODE
int findpar(int u,vector<int>&parent)
{
    if(parent[u]==u)
    return u;
    return parent[u] = findpar(parent[u],parent);
}
//MERGE KRO SMALLER PART
void Union(int u,int v,vector<int>& parent,vector<int>& rank)
{
    int Pu = findpar(u,parent);
    int Pv = findpar(v,parent);
    if(rank[Pu] > rank[Pv])
    parent[Pv] = Pu;
    else if(rank[Pv] > rank[Pu])
    parent[Pu] = Pv;
    else
    {
        parent[Pv] = Pu;
        rank[Pu]++;
    }
}
    void makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        for(int i=0;i<n+1;i++)
        parent[i]=i;
        int components = n;
        for(auto &vec: connections)
        {
            if(findpar(vec[0],parent)!= findpar(vec[1],parent))
            {
                Union(vec[0],vec[1],parent,rank);
                components--;//JAIE HI MERGE HUA TO 2 COMPONENT MILKE EK HO GYE 
            }
        }
        //JITNE BACHENGE ELEMENT AB UNKO CONNECT KRNE KE LIYE V-1 EDGES CHAHIYE NA

        cout<<components-1<<"\n";

        vector<int>rep;
        for(int i=1;i<n+1;i++)
        {
            if(parent[i]==i)
            rep.push_back(i);
        }

        for(int i=1;i<rep.size();i++)
        {
            cout<<rep[0]<<" "<<rep[i]<<"\n";
        }

    }


int main ()
{
    vector<vector<int>> connections;
    int n,m;
    cin>> n>>m;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        connections.push_back({u,v});
    }

    makeConnected(n,connections);

    return 0;
}