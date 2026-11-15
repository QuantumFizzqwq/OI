#include <bits/stdc++.h>

using namespace std;

int n, m, K;
int candy[105], dp[1 << 20];

int main() {
    cin >> n >> m >> K;
    for (int i = 1; i <= n; i ++) {
       for (int j = 1; j <= K; j ++) {
            int v;
            cin >> v;
            candy[i] |= 1 << (v - 1);
       }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++)
        //for (int j = (1 << m) - 1; j >= 0; j --)
        for (int j = 0; j < (1 << m); j ++)
            dp[j | candy[i]] = min(dp[j | candy[i]], dp[j] + 1);

    cout << (dp[(1 << m) - 1] > n ? -1 : dp[(1 << m) - 1]) << endl;
    return 0;
}