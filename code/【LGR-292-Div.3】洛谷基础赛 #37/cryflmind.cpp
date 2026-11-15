#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define ep emplace
#define eb emplace_back
#define pb push_back
#define x first
#define y second
bool check[200010];
int N,E,M,A,a[200010],ans,vis[200010],cur;
vector<int>g[200010];
void dfs(int u,int p){
    vis[u]=cur;
    check[u]=1;
    for(int v:g[u]){
        if(vis[v]!=cur&&a[v]<=p&&v!=A){
            dfs(v,p);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>N>>E>>M>>A;
    rep(i,1,N){
        cin>>a[i];
    }
    rep(i,1,E){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i,1,M){
        int s;
        cin>>s;
        cur++;
        dfs(s,a[s]);
    }
    for(int v:g[A]){
        if(check[v]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}