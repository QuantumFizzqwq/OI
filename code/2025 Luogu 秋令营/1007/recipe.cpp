#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;
const int mod = 998244353;

ll ans;
int n, m, k, tot;
int primes[maxn], prime_cnt;
int factor_val[1000], factor_exp[1000], factor_use[1000];
ll f[maxn];

// 线性筛
void get_primes() {
    for (int i = 2; i < maxn; i++) {
        if (!primes[i]) primes[++prime_cnt] = i;
        for (int j = 1; j <= prime_cnt && i * primes[j] < maxn; j++) {
            primes[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

// 质因数分解
void factorize(int x) {
    tot = 0;
    int t = 1, mx = sqrt(x);
    while (primes[t] <= mx && x != 1) {
        if (x % primes[t] == 0) {
            factor_val[++tot] = primes[t];
            factor_exp[tot] = 0;
            while (x % primes[t] == 0) {
                x /= primes[t];
                factor_exp[tot]++;
            }
        }
        t++;
    }
    if (x != 1) factor_val[++tot] = x, factor_exp[tot] = 1;
}

// 快速幂
ll quick_pow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

// 杨辉三角，计算组合数 C(n,k)
int comb[1005][1005];
void build_comb() {
    for (int i = 0; i < 1005; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
    }
}

// DFS 枚举 v 统计答案
void dfs(int pos) {
    if (pos == tot + 1) {
        int prod = 1;
        for (int i = 1; i <= tot; i++)
            prod *= quick_pow(factor_val[i], factor_use[i]);
        ll sum = 1;
        for (int i = 1; i <= tot; i++) {
            int r = factor_exp[i] - factor_use[i];
            if (r == 0) continue;
            sum = sum * comb[r + k - 1][r] % mod; 
        }
        if (prod <= n) ans = (ans + f[prod] * sum % mod) % mod;
        return;
    }
    for (int i = 0; i <= factor_exp[pos]; i++) {
        factor_use[pos] = i;
        dfs(pos + 1);
    }
}

int main() {
    freopen("recipe.in", "r", stdin);
    freopen("recipe.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    get_primes();
    build_comb();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];

    cin >> m;
    while (m--) {
        cin >> k;
        int x;
        cin >> x;
        factorize(x);
        ans = 0;
        dfs(1);
        cout << ans % mod << "\n";
    }

    return 0;
}