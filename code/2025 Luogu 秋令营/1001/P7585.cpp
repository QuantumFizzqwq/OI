#include<bits/stdc++.h>
using namespace std;
int n,m,c[300005];
bool check(int x){
    //检查每个孩子发的弹珠不超过 x 个时能否将所有弹珠发完
    long long cnt=0;
    for(int i=1;i<=m;i++){
        cnt+=(c[i]+x-1)/x;//累加 c[i]/x 向上取整的值
    }
    if(cnt>n) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>c[i];
    int l=1,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans+1<<'\n';
    return 0;
}