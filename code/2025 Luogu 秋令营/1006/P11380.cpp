#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 2e5 + 5;
int n, m, l[N], r[N], f[N];
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
int main() {
  cin >> n >> m;
  iota(f, f + N, 0);
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (!l[b] && !r[a]) {
      int fa = find(a), fb = find(b);
      if (fa == fb) {
        puts("0");
        return 0;
      }
      f[fa] = fb;
      l[b] = a, r[a] = b;
    }
    if (l[b] != a || r[a] != b) {
      puts("0");
      return 0;
    }
  }
  int cnt = 0, ans = 1;
  for (int i = 1; i <= n; i++) {
    if (i == find(i)) {
      ans = 1ll * ans * (++cnt) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}