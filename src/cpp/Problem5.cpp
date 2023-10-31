/*
 * Author: RAXIMBERDI
 * Date:10/31/2023
 * Name:
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dist[MAXN];

void bfs(int s) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    int d = dist[x];
    bfs(x);
    int max_d = *max_element(dist + 1, dist + n + 1);

    cout << max(d * 2, max_d * 2) << "\n";

    return 0;
}
