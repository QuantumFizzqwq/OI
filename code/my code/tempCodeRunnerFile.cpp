#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define ull unsigned long long
#define db double
#define ld long double
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define pdb pair<double,double>
#define pdi pair<double,int>
#define ep emplace
#define eb emplace_back
#define pb push_back
#define mpr make_pair
#define fi first
#define se second
#define popcnt __builtin_popcountll
#define lowbit(x) ((x)&(-x))
#define fp(x) fixed<<setprecision(x)
#define lb lower_bound
#define ub upper_bound
#define mem(a,x) memset(a,x,sizeof(a))
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset=tree<pair<T,int>,null_type,less<pair<T,int>>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename Key, typename Val>
using my_gp_hash_table=gp_hash_table<Key,Val,direct_mask_range_hashing<>,linear_probe_fn<>,hash_standard_resize_policy<>>;
constexpr int inf=1e18;
constexpr int dx[]={1,-1,0,0,1,1,-1,-1};
constexpr int dy[]={0,0,1,-1,1,-1,1,-1};
int T=1,n,m;
vector<vector<int>>s;
inline int count(int msk){
    vector<int>key(n,0);
    rep(i,0,n-1){
        int h=0;
        rep(j,0,m-1){
            if(msk>>j&1) 
                continue;
            h=h*26+s[i][j];
        }
        key[i]=h;
    }
    sort(key.begin(),key.end());
    int cnt=0,r=1;
    for(int i=1;i<n;i++){
        if(key[i]==key[i-1]) 
            r++;
        else{ 
            cnt+=r*(r-1)/2;
            r=1; 
        }
    }
    cnt+=r*(r-1)/2;
    return cnt;
}
inline void solve(){
    cin>>n>>m;
    s.assign(n,vector<int>(m));
    string t;
    rep(i,0,n-1){
        cin>>t;
        rep(j,0,m-1) 
            s[i][j]=t[j]-'a';
    }
    int z=count(0);
    int s1=0,s2=0;
    rep(msk,1,(1<<m)-1){
        int pc=popcnt(msk);
        if(pc==1)
            s1+=count(msk);
        else if(pc==2) 
            s2+=count(msk);
    }
    int e1=s1-m*z,c2=m*(m-1)/2,e2=s2-c2*z-(m-1)*e1;
    cout<<z+e1+e2<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    while(T--){
        solve();
    }
    return 0;
}
