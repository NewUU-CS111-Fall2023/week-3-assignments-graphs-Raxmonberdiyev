# * Author:Raximberdi
# * Date:10/31/2023
from collections import deque

def solve(n, m, j, maze):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    visited = [[[False]*(j+1) for _ in range(m)] for _ in range(n)]
    queue = deque()

    for i in range(n):
        for k in range(m):
            if maze[i][k] == '@':
                queue.append((i, k, 0))
                visited[i][k][0] = True

    while queue:
        x, y, s = queue.popleft()
        if maze[x][y] == 'x':
            return "SUCCESS"

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if maze[nx][ny] == '#':
                continue
            if maze[nx][ny] == 's' and s < j and not visited[nx][ny][s+1]:
                visited[nx][ny][s+1] = True
                queue.append((nx, ny, s+1))
            elif maze[nx][ny] != 's' and not visited[nx][ny][s]:
                visited[nx][ny][s] = True
                queue.append((nx, ny, s))

    return "IMPOSSIBLE"
