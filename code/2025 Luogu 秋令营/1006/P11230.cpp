#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, R = 1e2 + 5, C = 2e5 + 5;
int n, k, q;
vector<int> s[N];
int f[R][C];  // f[r][j]表示第r轮，结尾为j是否存在
              // -1: 无法接龙 0: 任意接龙 i：限制i不能接龙
void init(int n) {
  memset(f, -1, sizeof(f));
  f[0][1] = 0;
  for (int r = 1; r < R; r++) {
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int x : s[i]) {
        if (cnt > 0) {
          if (f[r][x] == -1)
            f[r][x] = i;
          else if (f[r][x] != i)
            f[r][x] = 0;
          cnt--;
        }
        if (f[r - 1][x] != -1 && f[r - 1][x] != i) {
          cnt = k - 1;
        }
      }
    }
  }
}
int main() {
  //freopen("chain.in", "r", stdin);
  //freopen("chain.out", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      s[i].clear();
      s[i].resize(x);
      for (int &it : s[i]) cin >> it;
    }
    init(n);
    while (q--) {
      int r, c;
      cin >> r >> c;
      cout << (f[r][c] == -1 ? 0 : 1) << endl;
    }
  }
  return 0;
}
