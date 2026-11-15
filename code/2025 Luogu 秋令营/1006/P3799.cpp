#include <bits/stdc++.h>
using namespace std;
const int M = 5e3 + 5, mod = 1e9 + 7;
int cnt[M];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int ans = 0;
  for (int i = 1; i < M; i++) {
    int x = 1ll * (cnt[i]) * (cnt[i] - 1) / 2 % mod;
    for (int j = 1; j <= i / 2; j++) {
      int y;
      if (j == i - j)
        y = 1ll * cnt[j] * (cnt[j] - 1) / 2 % mod;
      else
        y = 1ll * cnt[j] * cnt[i - j] % mod;
      ans += 1ll * x * y % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}