//busqueda en profundidad o DFS, GRAFOS

vector adj[N]; // vector<vector<int>> adj;
bool visited[N];

void dfs(int s) {
  if (visited[s]) return;
  visited[s] = true;
  // process node s
  for (auto u: adj[s]) {
      dfs(u);
  }
}
