#include<bits/stdc++.h>
using namespace std;
long long s[300005],t[300005],a[10000005];
int n,m,l[300005],r[300005];
void add1(int l,int r,long long s,long long t){
    long long d=(t-s)/(r-l);//数据保证 l<r 因此无需特判
    a[l]+=d,a[r+1]-=d;
}
void add2(int l,int r,long long s,long long t){
    long long d=(t-s)/(r-l);
    a[r+1]-=(r-l+1)*d;
    a[l]+=s-d,a[r+1]-=s-d;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>s[i]>>t[i];
    for(int i=1;i<=m;i++) add1(l[i],r[i],s[i],t[i]);
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    for(int i=1;i<=m;i++) add2(l[i],r[i],s[i],t[i]);
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    long long ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        ans1^=a[i];
        ans2=max(ans2,a[i]);
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}