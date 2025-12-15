#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;

  vector<vector<int>> adj(V);
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int start;
  cin >> start;

  vector<bool> visited(V, false);
  queue<int> q;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
  return 0;
}
