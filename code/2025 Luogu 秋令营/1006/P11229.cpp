#include <bits/stdc++.h>
using namespace std;
int a[9] = {0, -1, 1, 7, 4, 2, 6, 8, 10};
void print8(int cnt) {
  for (int i = 0; i < cnt; i++) cout << 8;
};
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n <= 8) {
      cout << a[n] << endl;
      continue;
    }
    int d = n % 7, q = n / 7;
    if (d == 0) {
      print8(q);
    } else if (d == 1) {
      cout << 10;
      print8(q - 1);
    } else if (d == 2) {
      cout << 1;
      print8(q);
    } else if (d == 3) {
      if (n == 10)
        cout << 22;
      else {
        cout << 200;
        print8(q - 2);
      }
    } else if (d == 4) {
      cout << 20;
      print8(q - 1);
    } else if (d == 5) {
      cout << 2;
      print8(q);
    } else if (d == 6) {
      cout << 6;
      print8(q);
    }
    cout << '\n';
  }
  return 0;
}