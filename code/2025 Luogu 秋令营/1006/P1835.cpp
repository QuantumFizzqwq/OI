#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, M = 2e6 + 5;
vector<int> prime;
bool vis[N], vis_bias[M];
void seive(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) prime.push_back(i);
    for (int p : prime) {
      if (1ll * i * p > n) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }
}
int main() {
  seive(N - 1);
  int l, r;
  cin >> l >> r;
  for (int p : prime) {
    for (long long i = max(p * p, (l + p - 1) / p * p); i <= r; i += p) {
      vis_bias[i - l] = true;
    }
  }
  int ans = 0;
  vis[1] = 1;
  for (int i = l; i <= r; i++) {
    if (i < N) {
      ans += !vis[i];
    } else {
      ans += !vis_bias[i - l];
    }
  }
  cout << ans << endl;
  return 0;
}