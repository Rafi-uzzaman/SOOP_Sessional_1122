#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
  int N;
  cin >> N;

  int sx, sy, ex, ey;
  cin >> sx >> sy;
  cin >> ex >> ey;

  vector<vector<int>> dist(N, vector<int>(N, -1));
  vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));

  queue<pair<int, int>> q;
  q.push({sx, sy});
  dist[sx][sy] = 0;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    if (x == ex && y == ey)
      break;

    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && nx < N && ny < N && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[x][y] + 1;
        parent[nx][ny] = {x, y};
        q.push({nx, ny});
      }
    }
  }

  cout << "Minimum moves: " << dist[ex][ey] << endl;

  vector<pair<int, int>> path;
  for (int x = ex, y = ey; x != -1;) {
    path.push_back({x, y});
    auto p = parent[x][y];
    x = p.first;
    y = p.second;
  }
  reverse(path.begin(), path.end());

  cout << "Path:\n";
  for (auto p : path)
    cout << "(" << p.first << "," << p.second << ") ";
}
