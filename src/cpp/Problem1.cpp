/*
 * Author: RAXIMBERDI
 * Date:
 * Name:
 */

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3005;
vector<int> adj[MAXN];
bool forbidden[MAXN][MAXN];
int dist[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        forbidden[a][b] = true;
    }

    memset(dist, -1, sizeof(dist));
    dist[0][1] = 0;
    queue<pair<int, int>> q;
    q.push({0, 1});

    while(!q.empty()) {
        int prev = q.front().first;
        int cur = q.front().second;
        q.pop();

        for(int next : adj[cur]) {
            if(next == prev || (forbidden[prev][cur] && forbidden[cur][next])) continue;
            if(dist[cur][next] == -1) {
                dist[cur][next] = dist[prev][cur] + 1;
                parent[cur][next] = {prev, cur};
                q.push({cur, next});
            }
        }
    }

    pair<int, int> end = {0, 0};
    for(int i = 1; i <= n; i++) {
        if(dist[i][n] != -1 && (end.first == 0 || dist[i][n] < dist[end.first][end.second])) {
            end = {i, n};
        }
    }

    if(end.first == 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    while(end.second != 0) {
        path.push_back(end.second);
        end = parent[end.first][end.second];
    }

    reverse(path.begin(), path.end());

    cout << dist[path[0]][path[1]] << endl;
    for(int city : path) {
        cout << city << " ";
    }

    return 0;
}
