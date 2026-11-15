#include <bits/stdc++.h>
using namespace std;

// 产生随机数
mt19937 gen(time(0));
int rand(int l, int r) {
  int p = gen();
  p = abs(p);
  return p % (r - l + 1) + l;
}

int main() {
  int T = 5;
  freopen("chain.in", "w", stdout);
  cout << T << endl;

  while (T--) {
    int n = rand(1, 10);
    int k = rand(2, 10);
    int q = rand(1, 10);
    cout << n << " " << k << " " << q << endl;

    for (int i = 0; i < n; i++) {
      int len = rand(1, 20);
      cout << len;
      for (int j = 0; j < len; j++) {
        int x = rand(1, 20);
        cout << " " << x;
      }
      cout << endl;
    }

    for (int i = 0; i < q; i++) {
      int r = rand(1, 5);
      int c = rand(1, 20);
      cout << r << " " << c << endl;
    }
  }

  return 0;
}