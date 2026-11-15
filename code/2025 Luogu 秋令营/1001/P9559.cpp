#include<bits/stdc++.h>
using namespace std;
struct Player{int v,w;}a[100005];
int n;
bool check(int x){//检查最慢的人的速度是否能不小于 x
    multiset<int> s;//存储需要被背负的人的体重
    for(int i=1;i<=n;i++) if(a[i].v<x) s.insert(a[i].w);
    for(int i=1;i<=n;i++) if(a[i].v>=x){
        auto it=s.upper_bound(a[i].v+a[i].w-x);
        if(it!=s.begin()) s.erase(prev(it));
    }
    return s.empty();
}
void solution(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].v>>a[i].w;
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solution();
    return 0;
}