#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll ksm(ll a, ll b, ll mod) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    ll k, a, b;
    scanf("%lld%lld%lld", &k, &a, &b);
    ll c1 = (b - a + 1) - (b / k - (a - 1) / k);
    vector<int> s;
    // (long long)ceil( a / (double)k )
    ll c2 = min(a - 1, b / k) - (a + k - 1) / k + 1;
    printf("%lld\n", ksm(2, c1 + c2, mod));
  }
  return 0;
}
