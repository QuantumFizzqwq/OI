#include<bits/stdc++.h>
using namespace std;
long long s[1000005];
int n,k,a[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    long long ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,s[i]-s[max(i-k-1,0)]);
    cout<<ans<<'\n';
    return 0;
}