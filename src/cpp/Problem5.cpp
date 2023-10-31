/*
 * Author: RAXIMBERDI
 * Date:
 * Name:
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int depth[100005];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent) {
    depth[node] = depth[parent] + 1;
    for(int child : adj[node]) {
        if(child != parent) {
            dfs(child, node);
        }
    }
}

int solve(int n, int x, vector<pair<int, int>>& edges) {
    for(auto& edge : edges) {
        add_edge(edge.first, edge.second);
    }

    dfs(1, 0);

    if(depth[1] <= depth[x]) {
        return 2 * depth[x] - 1;
    } else {
        return 2 * depth[x];
    }
}

int main() {
    int n = 5;
    int x = 3;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};

    cout << solve(n, x, edges) << endl;  // Output: 5

    return 0;
}
