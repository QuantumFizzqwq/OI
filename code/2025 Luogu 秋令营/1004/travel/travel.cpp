#include <bits/stdc++.h>

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  int T;
  for (std::cin >> T; T; --T) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> e(n + 1);
    for (int i = 1; i <= m; ++i) {
      int u, v, w;
      std::cin >> u >> v >> w;
      e[u].emplace_back(v, w);
      e[v].emplace_back(u, w);
    }
    int k;
    std::cin >> k;
    int ans = 0;
    auto check = [&](int mid) -> bool {
      std::vector<int> vis(n + 1);
      std::queue<int> Q;
      for (int i = 1; i <= n; ++i) if (!vis[i]) {
        int cnt = 1;
        Q.push(i);
        vis[i] = 1;
        while (!Q.empty()) {
          int u = Q.front();
          Q.pop();
          for (auto [v, w] : e[u]) if (w <= mid && !vis[v]) {
            vis[v] = 1;
            ++cnt;
            Q.push(v);
          }
        }
        if (cnt < k) return false;
      }
      return true;
    };
    for (int l = 1, r = 1'000'000'000, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
    std::cout << ans << "\n";
  }
}