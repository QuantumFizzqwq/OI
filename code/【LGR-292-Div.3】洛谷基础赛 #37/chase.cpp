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
//疑似图论专场
//不能CSP-J2026也是图论专场吧qwq
//bushi
const int INF=1e18;
int n,m;
vector<pii>g[510];
int dp[510][510],ans=INF;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].eb(v,w);
    }
    rep(i,1,n){
        rep(u,1,n){
            dp[i][u]=INF;
        }
    }
    dp[1][1]=0;
    rep(i,1,n){
        rep(u,1,n){
            if(dp[i][u]==INF){
                continue;
            }
            for(auto edge:g[u]){
                int v=edge.x,w=edge.y;
                if(i+1>n){
                    continue;
                }
                dp[i+1][v]=min(dp[i+1][v],dp[i][u]+w);
            }
        }
    }
    rep(i,2,n){
        if(2*i<=n){
            ans=min(ans,dp[i][n]);
        }
    }
    if(ans==INF){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    return 0;
}