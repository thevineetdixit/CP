#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int i, int j, vector<vector<char>> &grid)
{
    grid[i][j] = '#';
    for (auto &dir : directions)
    {
        int x = i + dir[0];
        int y = j + dir[1];
        if (valid(x, y) && grid[x][y] == '.')
            dfs(x, y, grid);
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                dfs(i, j, grid);
                ans++;
            }
        }

    cout << ans;
    return 0;
}

//done with both dfs and bfs
