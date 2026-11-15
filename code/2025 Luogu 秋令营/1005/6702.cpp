#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 5;

const int inf = 0x3f3f3f3f;

int dp[N];

int main() {
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    // 0x3f3f3f3f is used to represent infinity

    dp[0] = 0;
    dp[3] = 1;
    for (int i = 5; i <= n; i ++) {
        dp[i] = min(dp[i], dp[i - 3] + 1);
        dp[i] = min(dp[i], dp[i - 5] + 1);
    }
    if (dp[n] > n) cout << -1 << endl;
    else cout << dp[n] << endl;
    return 0;
}