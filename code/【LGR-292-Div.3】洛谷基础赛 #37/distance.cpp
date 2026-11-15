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
struct node{
    int left,right,cnt,dist;
};
int n,d[100010],l,r,ans;
bool t[100010];
vector<node>v;
signed main(){
    freopen("distance25.in","r",stdin);
    freopen("distance25.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    l=r=1e18;
    rep(i,1,n-1){
        cin>>d[i];
    }
    int tmpd=0;
    rep(i,1,n){
        cin>>t[i];
        if(l==1e18||r==1e18){
            tmpd+=d[i-1];
        }
        if(l==1e18&&t[i]==0){
            l=i;
            continue;
        }
        if(r==1e18&&t[i]==0){
            r=i;
            v.pb({l,r,r-l,tmpd});
            tmpd=0;
            l=r;
            r=1e18;
            continue;
        }
    }
    
    for(auto u:v){
        //cout<<u.left<<" "<<u.right<<" "<<u.cnt<<" "<<u.dist<<"\n";
        rep(i,u.left+1,u.right-1){
            if((double)d[i-1]!=u.dist*1.0/u.cnt||(double)d[i]!=u.dist*1.0/u.cnt){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}