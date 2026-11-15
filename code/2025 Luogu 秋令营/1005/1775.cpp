#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 5;

int n;
int a[N], sum[N];

int f[N][N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    memset (f, 0x3f, sizeof (f));
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = 0;
    }

    for (int len = 2; len <= n; len ++) {
        for (int i = 1; i + len - 1 <= n; i ++) {
            int j = i + len - 1;
            for (int k = i; k < j; k ++) {
                f[i][j] = 
                    min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}