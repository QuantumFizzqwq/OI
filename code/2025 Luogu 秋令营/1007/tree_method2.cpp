#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n, q;
long long w[MAXN];
int p[MAXN];
vector<int> tree[MAXN];
vector<int> dfs_seq[32]; // 每个指数对应的dfs序列
int in[MAXN], out[MAXN];
int timer = 0;

void dfs(int u) {
    in[u] = ++timer;
    long long e = w[u] & -w[u]; 
    int k = (int)log2(e);    
    dfs_seq[k].push_back(in[u]);
    for (int v : tree[u]) dfs(v);
    out[u] = timer;
}

int count_in_range(const vector<int> &vec, int L, int R) {
    return upper_bound(vec.begin(), vec.end(), R) - lower_bound(vec.begin(), vec.end(), L);
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        tree[p[i]].push_back(i);
    }

    dfs(1);

    cin >> q;
    while (q--) {
        int u;
        long long l, r;
        cin >> u >> l >> r;
        int L = (int)ceil(log2(l));
        int R = (int)floor(log2(r));
        int ans = 0;
        for (int e = L; e <= R && e < 32; ++e) {
            ans += count_in_range(dfs_seq[e], in[u], out[u]);
        }
        cout << ans << "\n";
    }

    return 0;
}
