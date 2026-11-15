#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;

int n, A, B;
int w[N], dp[N][N];

int main() {
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++)
        for (int j = A; j >= 0; j --)
            for (int k = B; k >= 0; k --) {
                if (j >= w[i])
                    dp[j][k] = max(dp[j][k], dp[j - w[i]][k] + w[i]);
                if (k >= w[i])
                    dp[j][k] = max(dp[j][k], dp[j][k - w[i]] + w[i]);
            }
    cout << dp[A][B] << endl;
    return 0;
}