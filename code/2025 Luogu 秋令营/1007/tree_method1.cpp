#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
vector <int> ver[maxn];
int f[maxn][32];
void dfs(int x){
    for(int i = 0; i <= 30; i++){
        if(a[x] >> i & 1){
            f[x][i] = 1;
            break;
        }
    }
    for(auto u : ver[x]){
        dfs(u);
        for(int i = 0; i <= 30; i++){
            f[x][i] += f[u][i];
        }
    }    
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        ver[x].push_back(i);
    }
    dfs(1);
    int q; cin >> q;
    while(q--){
        int u, x, y;
        cin >> u >> x >> y;
        int ans = 0;
        for(int i = 0; i <= 30; i++){
            int val= (1 << i);
            if(val >= x && val <= y){
                ans += f[u][i];
            }
        }
        cout << ans <<"\n";
    }
    return 0;
}