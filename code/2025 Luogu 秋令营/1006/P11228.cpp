#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char a[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, d;
    cin >> x >> y >> d;
    for (int i = 1; i <= n; i++) cin >> (a[i] + 1);

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
    cout << vis.size() << "\n";
  }
  return 0;
}