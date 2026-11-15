#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 5e5 + 5;
int n, a[N], b[N], sa[N], sb[N], ssa[N], ssb[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sa[i] = (sa[i - 1] + a[i]) % mod;
    ssa[i] = (ssa[i - 1] + sa[i]) % mod;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sb[i] = (sb[i - 1] + b[i]) % mod;
    ssb[i] = (ssb[i - 1] + sb[i]) % mod;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + 1ll * i * sa[i] % mod * sb[i]) % mod;
    ans = (ans - 1ll * sb[i - 1] * (ssa[n] - ssa[i - 1]) % mod) % mod;
    ans = (ans - 1ll * sa[i - 1] * (ssb[n] - ssb[i - 1]) % mod) % mod;
    ans = (ans + 1ll * (n - i + 1) * sa[i - 1] % mod * sb[i - 1]) % mod;
  }
  cout << (ans % mod + mod) % mod << endl;
}