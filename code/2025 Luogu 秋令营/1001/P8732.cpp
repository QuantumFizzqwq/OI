#include<bits/stdc++.h>
using namespace std;
int n,a[1005],e[1005],s[1005],p[1005];
bool cmp(int x,int y){
    // int sumx=(s[x]+a[x])+(s[x]+a[x]+e[x]+s[y]+a[y]);
    // int sumy=(s[y]+a[y])+(s[y]+a[y]+e[y]+s[x]+a[x]);
    // return sumx<sumy;
    return s[x]+a[x]+e[x]<s[y]+a[y]+e[y];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i]>>a[i]>>e[i];
    for(int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,cmp);
    long long ans=0,sum=0;
    for(int i=1;i<=n;i++){
        sum+=s[p[i]]+a[p[i]];
        ans+=sum;
        sum+=e[p[i]];
    }
    cout<<ans<<'\n';
    return 0;
}