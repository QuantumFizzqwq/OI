#include <bits/stdc++.h>

int main() {
  freopen("stair.in", "r", stdin);
  freopen("stair.out", "w", stdout);
  using ll = long long;
  ll n, t, k, s;
  std::cin >> n >> t >> k >> s;
  std::cout << (n - 1) * t + s * ((n - 1) / k) << '\n';
}