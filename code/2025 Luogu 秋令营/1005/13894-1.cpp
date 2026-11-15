#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n;
int f[N];
string s;

int main() {
    cin >> s;
    n = s.size();
    f[0] = 0;
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1];
        // 检查能否使 s[i-2] 和 s[i-1] 相同（0-based）
        char a = s[i - 2], b = s[i - 1];
        bool can = (a == b) || (a == '?') || (b == '?');
        if (can) {
            f[i] = max(f[i], f[i - 2] + 1);
        }
    }
    cout << f[n] << endl; 
    return 0;
}