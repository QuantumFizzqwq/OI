#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005],b[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+n+1,greater<int>());
    long long ans=0;
    for(int i=1;i<=min(n,m);i++) ans+=max(a[i],k);
    for(int i=1;i<=n;i++) ans+=a[i];
    for(int i=1;i<=m;i++) ans+=b[i];
    cout<<ans<<'\n';
    return 0;
}