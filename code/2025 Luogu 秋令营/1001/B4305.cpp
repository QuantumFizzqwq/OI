#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005];
bool check(int x){
    //检查连续段价值和不超过 x 时是否不能完成连续段划分
    int cnt=1,sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x) return 1;
        if(sum+a[i]<=x) sum+=a[i];
        else ++cnt,sum=a[i];
    }
    if(cnt>k) return 1;
    return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>k;
    int l=1,r=1e8,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans+1<<'\n';
    return 0;
}