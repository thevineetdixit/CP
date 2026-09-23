#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<P>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;

        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    // dist[node][0] -> coupon not used
    // dist[node][1] -> coupon already used
    vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));

    priority_queue<
        tuple<ll, int, int>,
        vector<tuple<ll, int, int>>,
        greater<tuple<ll, int, int>>
    > pq;

    dist[1][0] = 0;

    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [cost, u, used] = pq.top();
        pq.pop();

        if (cost != dist[u][used])
            continue;

        for (auto &[v, w] : adj[u]) {

            // Don't use discount
            if (dist[v][used] > cost + w) {
                dist[v][used] = cost + w;
                pq.push({dist[v][used], v, used});
            }

            // Use discount on this edge
            if (!used) {
                ll newCost = cost + w / 2;

                if (dist[v][1] > newCost) {
                    dist[v][1] = newCost;
                    pq.push({newCost, v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << '\n';

    return 0;
}