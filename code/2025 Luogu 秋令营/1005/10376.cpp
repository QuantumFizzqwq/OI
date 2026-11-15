#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a, b, c;
int f[N];

int main() {
    cin >> n >> a >> b >> c;
    for (int i = 0; i <= n; i ++) {
        if (i <= c) f[i] = 1;
        else 
            f[i] = (f[max (0, i - a)] + f[max (0, i - b)]) % 1000000007;
    }
    cout << f[n] << endl;
    return 0;   
}