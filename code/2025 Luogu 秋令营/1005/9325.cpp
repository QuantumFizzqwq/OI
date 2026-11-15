#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 5;

int n, a[N];
long long f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    memset (f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i ++) f[i][i] = f[i + 1][i] = 0;


    cout << 0 << ' ';
    for (int len = 2; len <= n; len ++) {
        long long ans = 0x3f3f3f3f;
        for (int i = 1; i + len - 1 <= n; i ++) {
            int j = i + len - 1; // right endpoint
            f[i][j] = f[i + 1][j - 1] + abs (a[i] - a[j]);
            ans = min (ans, f[i][j]);
        }
        cout << ans << ' ';
    }
    cout << endl;
    
    return 0;
}