#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n, m;
int f[N][N][2];
int a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i ++) cin >> b[i];
    memset (f, 0x3f, sizeof f);
    f[0][0][0] = f[0][0][1] = 0;
    for (int i = 0; i <= n; i ++) 
        for (int j = 0; j <= m; j ++) {
            if (i > 0) {
                f[i][j][0] = 
                    min(f[i][j][0], f[i - 1][j][0] + 1 + (bool)(a[i] == a[i - 1]));
                f[i][j][0] = 
                    min(f[i][j][0], f[i - 1][j][1] + 1 + (bool)(a[i] == b[j]));
            }
            if (j > 0) {
                f[i][j][1] = 
                    min(f[i][j][1], f[i][j - 1][1] + 1 + (bool)(b[j] == b[j - 1]));
                f[i][j][1] = 
                    min(f[i][j][1], f[i][j - 1][0] + 1 + (bool)(b[j] == a[i]));
            }
        }
    cout << min(f[n][m][0], f[n][m][1]) << endl;
    return 0;
}