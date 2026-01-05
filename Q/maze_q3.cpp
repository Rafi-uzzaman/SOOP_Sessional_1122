// BFS Shortest Path in Maze

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));

    queue<pair<int,int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int visited = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        visited++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    cout << "Shortest path length: " << dist[ex][ey] << endl;

    vector<pair<int,int>> path;
    for (int x = ex, y = ey; x != -1; tie(x, y) = parent[x][y])
        path.push_back({x, y});
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << "(" << path[i].first << "," << path[i].second << ")";
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << endl;

    cout << "Total nodes visited: " << visited << endl;

    return 0;
}
