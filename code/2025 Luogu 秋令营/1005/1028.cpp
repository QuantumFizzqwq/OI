#include <iostream> 
using namespace std;
int n;
long long f[1010], s[1010];

int main(){
	cin >> n;
    f[1] = 1;
    s[1] = 1;
	for (int i = 2; i <= n; i++) {
        f[i] = s[i / 2];
		// for (int j = 0; j <= i / 2; j ++) {
		// 	f[i] += f[j];
		// }
        f[i] ++;
        s[i] = s[i - 1] + f[i];
	}
    cout << f[n] << endl;
	return 0;
}