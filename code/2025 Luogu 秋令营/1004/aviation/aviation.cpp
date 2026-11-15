#include <bits/stdc++.h>

int main() {
  freopen("aviation.in", "r", stdin);
  freopen("aviation.out", "w", stdout);
  int T;
  for (std::cin >> T; T; --T) {
    int n, m, t;
    std::cin >> n >> m >> t;
    const int INF = 0x3f3f3f3f;
    std::vector<std::vector<std::vector<int>>> dis(t + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, INF)));
    for (int u, v; m; --m) {
      std::cin >> u >> v;
      for (int i = 1, x; i <= t; ++i) {
        std::cin >> x;
        dis[i][u][v] = dis[i][v][u] = x;
      }
    }
    std::vector<int> c(n + 1);
    for (int i = 1; i <= n; ++i) {
      std::cin >> c[i];
    }
    std::vector<std::vector<std::vector<int>>> f(t + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, INF)));
    f[0][1][1] = 0;
    for (int i = 1; i <= t; ++i) {
      for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) if (dis[i][u][v] < INF) {
          for (int pre = 1; pre <= n; ++pre) {
            int cost = dis[i][u][v] + (pre != v ? 0 : c[u]);
            f[i][u][v] = std::min(f[i][u][v], f[i - 1][pre][u] + cost);
          }
        }
      }
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        ans = std::min({ans, f[t][i][j], f[t][j][i]});
      }
    }
    std::cout << ans << '\n';
  }
}