#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4000005;

int n,m;
struct node{
    int v,p,q,id;
}a[N];
int vis[N];
int pos[N];
ll ans=0;
bool cmp(node A,node B){
    return A.q<B.q;
}
void dfs(int now,int sum){
    if(sum>n)return;
    if(now==m+1){
        ll tot=0;
        for(int i=1;i<=m;i++)if(vis[i]){
            tot+=1ll*a[i].v*a[i].p;
        }
        ans=max(ans,tot);
        return;
    }
    dfs(now+1,sum);
    if(a[now].q==0||vis[pos[a[now].q]]){
        vis[now]=1;
        dfs(now+1,sum+a[now].v);
        vis[now]=0;
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].v>>a[i].p>>a[i].q;
        a[i].id=i;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)pos[a[i].id]=i;
    dfs(1,0);
    cout<<ans<<'\n';
    return 0;
}
/*

*/