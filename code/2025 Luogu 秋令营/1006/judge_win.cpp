#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0;
  do {
    cout << "Running on test " << ++cnt << endl;
    system(".\\make.exe");
    system(".\\P11230.exe");
    system(".\\P11230_force.exe");
  } while (!system("fc chain.out chain.ans"));
  return 0;
}