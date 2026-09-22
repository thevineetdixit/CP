#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int n, m;
vector<string> grid;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dirChar[4] = {'D', 'U', 'R', 'L'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grid.resize(n);

    for (int i = 0; i < n; i++) cin >> grid[i];

    queue<pii> q;

    vector<vector<int>> monsterDist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> playerDist(n, vector<int>(m, -1));
    vector<vector<char>> parent(n, vector<char>(m));

    pii start;

    // Step 1: Push all monsters
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                monsterDist[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    // Step 2: Monster BFS
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (monsterDist[nx][ny] != INT_MAX) continue;

            monsterDist[nx][ny] = monsterDist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // Step 3: Player BFS
    queue<pii> pq;
    pq.push(start);
    playerDist[start.first][start.second] = 0;

    while (!pq.empty()) {
        auto [x, y] = pq.front(); pq.pop();

        // Escape condition (border)
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
            // reconstruct path
            string path;
            while (make_pair(x, y) != start) {
                char c = parent[x][y];
                path.push_back(c);

                if (c == 'D') x--;
                else if (c == 'U') x++;
                else if (c == 'R') y--;
                else if (c == 'L') y++;
            }
            reverse(path.begin(), path.end());

            cout << "YES\n";
            cout << path.size() << "\n";
            cout << path << "\n";
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (playerDist[nx][ny] != -1) continue;

            int nextTime = playerDist[x][y] + 1;

            // KEY CONDITION
            if (nextTime >= monsterDist[nx][ny]) continue;

            playerDist[nx][ny] = nextTime;
            parent[nx][ny] = dirChar[d];
            pq.push({nx, ny});
        }
    }

    cout << "NO\n";
}