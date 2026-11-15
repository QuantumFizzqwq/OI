#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    freopen("scroll.in", "r", stdin);
    freopen("scroll.out", "w", stdout);
    string S;
    cin >> S;
    int n = (int)S.size();

    int q;
    cin >> q;
    while (q--) {
        char X, Y;
        cin >> X >> Y;

        if (X == Y) {
            // 如果 X == Y，那么任意子串 X,Y 出现次数必然相等
            long long total = 1LL * n * (n + 1) / 2;
            cout << total << "\n";
            continue;
        }

        // 差分取值范围 [-n, n]，我们加偏移 n 使下标非负
        vector<long long> freq(2 * n + 1, 0);
        int offset = n;

        int diff = 0;
        freq[offset] = 1; // 空前缀
        long long ans = 0;

        for (char c : S) {
            if (c == X) diff++;
            if (c == Y) diff--;

            ans += freq[diff + offset];
            freq[diff + offset]++;
        }

        cout << ans << "\n";
    }

    return 0;
}
