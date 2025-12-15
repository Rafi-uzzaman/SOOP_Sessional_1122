#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> maze(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> maze[i][j];

  int sx, sy, ex, ey;
  cin >> sx >> sy;
  cin >> ex >> ey;

  vector<vector<int>> dist(n, vector<int>(m, -1));
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

  queue<pair<int, int>> q;
  q.push({sx, sy});
  dist[sx][sy] = 0;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 0 &&
          dist[nx][ny] == -1) {
        dist[nx][ny] = dist[x][y] + 1;
        parent[nx][ny] = {x, y};
        q.push({nx, ny});
      }
    }
  }

  if (dist[ex][ey] == -1) {
    cout << "No path exists\n";
    return 0;
  }

  cout << "Shortest path length: " << dist[ex][ey] << endl;
  vector<pair<int, int>> path;
  for (int x = ex, y = ey; x != -1;) {
    path.push_back({x, y});
    auto p = parent[x][y];
    x = p.first;
    y = p.second;
  }
  reverse(path.begin(), path.end());

  cout << "Path: ";
  for (auto p : path)
    cout << "(" << p.first << "," << p.second << ") ";
}
