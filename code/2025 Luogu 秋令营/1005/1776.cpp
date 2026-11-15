#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;
const int M = 4e4 + 5;

int n, m, tot;
int V[N * 20], W[N * 20];
int dp[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int v, w, cnt;
        cin >> v >> w >> cnt;
        for (int j = 0; (1 << j) <= cnt; j ++) {
            V[++ tot] = (1 << j) * v;
            W[tot] = (1 << j) * w;
            cnt -= (1 << j);
        }
        V[++ tot] = cnt * v;
        W[tot] = cnt * w;
    }
    for (int i = 1; i <= tot; i ++) {
        for (int j = m; j >= W[i]; j --) {
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}