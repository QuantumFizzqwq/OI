#include <bits/stdc++.h>
using namespace std;
set<string> se;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    se.insert(s);
  }
  cout << 52 - se.size() << endl;
}