#include<bits/stdc++.h>
using namespace std;
int n,k,c[305];
int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>c[i];
    sort(c+1,c+k+1,greater<int>());
    int ans=0;
    for(int i=1;i<=k;i++){
        if(i>n-i+1) break;
        ans+=((n-i+1)-i)*c[i];
    }
    cout<<ans<<'\n';
    return 0;
}