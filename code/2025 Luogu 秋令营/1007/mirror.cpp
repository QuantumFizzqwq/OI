#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    freopen("mirror.in", "r", stdin);
    freopen("mirror.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            cin.ignore();   // 丢掉换行符
            string s;
            getline(cin, s);
            cout << s << "\n";
        } else {
            long long h, w;
            cin >> h >> w;
            long long rows = (long long)ceil((double)h / 224.0);
            long long cols = (long long)ceil((double)w / 224.0);
            cout << rows * cols << "\n";
        }
    }
    return 0;
}
