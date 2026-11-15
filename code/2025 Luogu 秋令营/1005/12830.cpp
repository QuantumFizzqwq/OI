#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
const int n = 2025;

int dp[20], dp2[20], ans;

int main() {
    for (int i = 0; i < 15; i ++) dp[i] = 1;
    for (int i = 1; i < n; i ++) {
        memset (dp2, 0, sizeof dp2);
        for (int a = 0; a < 15; a ++) {
            int x = a / 3, y = a % 3;
            for (int b = 0; b < 15; b ++) {
                int xx = b / 3, yy = b % 3;
                if (max (x, xx) == 4 && max (y, yy) == 2) dp2[b] = (dp2[b] + dp[a]) % P;
            }
        }
        for (int j = 0; j < 20; j ++) dp[j] = dp2[j];
    }
    int ans = 0;
    for (int i = 0; i < 15; i ++) ans = (ans + dp[i]) % P;
    cout << ans << endl;

    return 0;
}