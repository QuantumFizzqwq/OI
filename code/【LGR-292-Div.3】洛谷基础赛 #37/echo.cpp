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
int n,tmp;
string s,ans;
signed main(){
    freopen("echo.in","r",stdin);
    freopen("echo.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    tmp=n=s.size();
    while(tmp>0){
        rep(i,0,tmp-1){
            ans+=s[i];
        }
        tmp--;
        per(i,n-1,n-tmp){
            ans+=s[i];
        }
        tmp--;
    }
    cout<<ans;
    return 0;
}