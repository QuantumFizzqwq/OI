#include <bits/stdc++.h>

int main() {
  freopen("doubt.in", "r", stdin);
  freopen("doubt.out", "w", stdout);
  int q;
  std::cin >> q;
  using ll = long long;
  for (ll n, k; q; --q) {
    std::cin >> n >> k;
    int x = __builtin_ctzll(k);
    std::cout << n - x << '\n';
  }
}