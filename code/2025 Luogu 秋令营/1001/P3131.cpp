#include<bits/stdc++.h>
using namespace std;
int n,p[10],a[50005];
long long s[50005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=0;i<=6;i++) p[i]=-1;//初始化
    for(int i=0;i<=n;i++){
        //对于所有 k 求出满足 s[l−1]%7==k 时最小的 l−1
        if(p[s[i]%7]==-1) p[s[i]%7]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){//枚举 r 的值计算答案
        ans=max(ans,i-p[s[i]%7]);
    }
    cout<<ans<<'\n';
    return 0;
}