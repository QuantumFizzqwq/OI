#include<bits/stdc++.h>
using namespace std;
int n,m,a[300005],s[300005],l[300005],r[300005];
int sum[2][300005];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=m;i++){
        ++a[l[i]];
        --a[r[i]+1];
    }
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        if(s[i]==0) sum[0][i]=1;//维护区间中 0 的数量
        if(s[i]==1) sum[1][i]=1;//维护区间中 1 的数量
    }
    for(int i=1;i<=n;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
    }
    for(int i=1;i<=m;i++){
        int ans=sum[0][l[i]-1]+(sum[0][n]-sum[0][r[i]]);
        ans+=sum[1][r[i]]-sum[1][l[i]-1];
        cout<<ans<<'\n';
    }
    return 0;
}