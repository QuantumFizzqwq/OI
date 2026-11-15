#include <bits/stdc++.h>

using namespace std;

const int N = 200 + 5;

int n;
int a[N][N];
int f[N * 2][N][N];

int main() {
    cin >> n;
    int dx, dy, dw;
    while (cin >> dx >> dy >> dw) {
        a[dx][dy] = dw;
    }
    for (int T = 1; T <= n + n; T ++)
        for (int x1 = 1; x1 <= n; x1 ++)
            for (int x2 = 1; x2 <= n; x2 ++) {
                int y1 = T + 1 - x1;
                int y2 = T + 1 - x2;
                f[T][x1][x2] = max({
                    f[T - 1][x1 - 1][x2 - 1], 
                    f[T - 1][x1][x2 - 1],
                    f[T - 1][x1][x2],
                    f[T - 1][x1 - 1][x2]
                });
                f[T][x1][x2] += a[x1][y1] + a[x2][y2];
                if (x1 == x2 && y1 == y2) f[T][x1][x2] -= a[x1][y1];
            }
    cout << f[n + n][n][n] << endl;
    return 0;
}