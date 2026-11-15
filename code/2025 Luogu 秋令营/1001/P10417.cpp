#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005];
long long k;
bool check(int x){
    long long cnt=0;//极限情况下 n*m 会超出 int 类型范围
    for(int i=1;i<=m;i++){
        int p=upper_bound(a+1,a+n+1,x-b[i])-a-1;
        cnt+=p;
    }
    if(cnt>=k) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+n+1);
    int l=1,r=2e9,ans=2e9;
    while(l<=r){
        int mid=l+(r-l)/2;//防止加法结果超出 int 类型范围
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<'\n';
    return 0;
}