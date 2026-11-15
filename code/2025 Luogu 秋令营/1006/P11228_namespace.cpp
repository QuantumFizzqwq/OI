#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int T, n, m, k;

char a[N][N];
int x, y, d;

namespace n_equal_1 {
int main() {
  set<int> vis;
  vis.insert(y);

  while (k--) {
    if (d == 0) {
      if (y + 1 <= m && a[1][y + 1] == '.') {
        y++;
        vis.insert(y);
      } else {
        d = (d + 1) % 4;
      }
    } else if (d == 2) {
      if (y - 1 >= 1 && a[1][y - 1] == '.') {
        y--;
        vis.insert(y);
      } else {
        d = (d + 1) % 4;
      }
    } else {
      d = (d + 1) % 4;
    }
  }

  cout << vis.size() << endl;
  return 0;
}

}  // namespace n_equal_1

namespace correct {

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
  set<pair<int, int>> vis;
  vis.insert({x, y});

  while (k--) {
    int nx = x + dx[d], ny = y + dy[d];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.') {
      x = nx, y = ny;
      vis.insert({x, y});
    } else {
      d = (d + 1) % 4;
    }
  }
  cout << vis.size() << endl;
  return 0;
}

}  // namespace correct

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    cin >> x >> y >> d;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) cin >> (a[i] + 1);
    if (n == 1)
      n_equal_1::main();
    else
      correct::main();
  }
}