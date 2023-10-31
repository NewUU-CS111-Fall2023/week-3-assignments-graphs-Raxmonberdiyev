/*
 * Author: RAXIMBERDI
 * Date: 10/31/2023
 * Name:
 */

#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    int n, m, j;  //al of them 2<=n, m, j=<40
    cout<<"Enter the number of row"<<endl;
    cin >>n;
    cout<<"Enter the width of each row"<<endl;
    cin  >>m;
    cout<<"Enter the number of times Jarmtin can avoid spikes"<<endl;
    cin >> j;
    cout<<"Enter the all characters "<<endl;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(j+1)));
    queue<tuple<int, int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (maze[i][k] == '@') { // '@' for an entrance (which is also an exit),
                q.push({i, k, 0});
                visited[i][k][0] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y, s] = q.front();
        q.pop();
        if (maze[x][y] == 'x') { //The character 'x' will be used for the place of the treasure
            cout << "SUCCESS" << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maze[nx][ny] == '#') continue; // '#' for walls
            if (maze[nx][ny] == 's' && s < j && !visited[nx][ny][s+1]) {  // 's' for spikes
                visited[nx][ny][s+1] = true;
                q.push({nx, ny, s+1});
            } else if (maze[nx][ny] != 's' && !visited[nx][ny][s]) {
                visited[nx][ny][s] = true;
                q.push({nx, ny, s});
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
