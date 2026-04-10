#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> dir{'U','D','L','R'};
string ans = "";
int step = INT_MAX;

using pii = pair<int,int>;
bool valid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}



int main()
{
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> path(n,vector<char>(m));
    
    pii start,end;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j]=='A')
            start = {i,j};
            if(grid[i][j]=='B')
            end = {i,j};
        }    

    bool flag = 0;
    queue<pii> q;
    q.push(start);
    grid[start.first][start.second]='#';

    while(!q.empty())
    {
        auto node = q.front();
        q.pop();

        int x = node.first;
        int y = node.second;


        for(int k=0;k<4;k++)
        {
            int nx = x+directions[k][0];
            int ny = y+directions[k][1];
            char d = dir[k];

            if(valid(nx,ny) && grid[nx][ny]!='#')
            {
                grid[nx][ny]='#';
                q.push({nx,ny});
                path[nx][ny] = d;
                if(make_pair(nx,ny) == end)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)break;
        
    }

    if(!flag)
    {
        cout<<"NO\n";
        return 0;
    }

    //ab baari h path reconstruction ki 
    pii curr = end;
    string ans = "";

    while(curr != start)
    {
        char r = path[curr.first][curr.second];
        ans.push_back(r);

        //ab humko ye pata krna h ki ye aaya kaha se h 
        //or humko kis taraf wapas jaana h
        //to ye hum jo char h usko dir me dekhenge fr waha jayenge
        int idx = find(dir.begin(),dir.end(),r)- dir.begin();
        curr.first -= directions[idx][0];
        curr.second -= directions[idx][1];

    }

    reverse(ans.begin(),ans.end()); 
    cout << "YES\n";
    cout << ans.size() << "\n";
    cout << ans;


    return 0;
}