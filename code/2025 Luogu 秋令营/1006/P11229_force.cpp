#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 2e9;
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
ll ans;
void dfs(int sum, ll x) {
  if (sum > n) return;
  if (sum == n) {
    ans = min(ans, x);
    return;
  }
  for (int i = 0; i <= 9; i++) {
    if (i == 0 && sum == 0) continue;
    dfs(sum + a[i], x * 10 + i);
  }
}
int main() {
  for (n = 1; n <= 50; n++) {
    ans = inf;
    dfs(0, 0);
    printf("%d \t %lld \n", n, ans);
  }
}
