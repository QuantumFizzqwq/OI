#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0;
  do {
    cout << "Running on test " << ++cnt << endl;
    system("./make");
    system("./P11230");
    system("./P11230_force");
  } while (!system("diff chain.out chain.ans"));
  return 0;
}