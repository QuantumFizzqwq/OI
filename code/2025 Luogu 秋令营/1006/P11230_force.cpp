#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, k, q;
vector<int> s[N];

set<tuple<int, int, int>> vis;

bool dfs(int r, int R, int now, int target, int prev) {
  if (r == R) return now == target;
  auto state = make_tuple(r, now, prev);
  if (vis.count(state)) return false;
  vis.insert(state);

  for (int i = 1; i <= n; i++) {
    if (i == prev) continue;
    for (int j = 0; j < (int)s[i].size(); j++) {
      if (s[i][j] != now) continue;
      for (int len = 2; len <= k && j + len <= (int)s[i].size(); len++) {
        int nxt = s[i][j + len - 1];
        if (dfs(r + 1, R, nxt, target, i)) return true;
      }
    }
  }
  return false;
}

int main() {
  freopen("chain.in", "r", stdin);
  freopen("chain.ans", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
      int len;
      cin >> len;
      s[i].resize(len);
      for (int j = 0; j < len; j++) cin >> s[i][j];
    }

    while (q--) {
      int R, target;
      cin >> R >> target;
      bool ok = false;
      vis.clear();

      for (int i = 1; i <= n && !ok; i++) {
        for (int j = 0; j < (int)s[i].size(); j++) {
          if (s[i][j] != 1) continue;
          for (int len = 2; len <= k && j + len <= (int)s[i].size(); len++) {
            int last = s[i][j + len - 1];
            if (dfs(1, R, last, target, i)) {
              ok = true;
              break;
            }
          }
        }
      }
      cout << (ok ? 1 : 0) << "\n";
    }
  }
  return 0;
}