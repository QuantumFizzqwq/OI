#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4000005;

int n;
struct node{
    int x,y;
}a[N];
bool cmp(node A,node B){
    if(A.y!=B.y)return A.y<B.y;
    return A.x<B.x;
}
int to[N];
int vis[N],tag[N];
int ans;
int dfs2(int x){
    if(tag[x])return 1;
    if(!to[x])return 0;
    tag[x]=1;
    return dfs2(vis[to[x]]);
}
void dfs(int now){
    if(now==n+1){
        int flag=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)tag[j]=0;
            if(dfs2(i)){flag=1;break;}
        }
        if(flag)ans++;
        return;
    }
    if(vis[now]){dfs(now+1);return;}
    for(int i=now+1;i<=n;i++){
        if(vis[i])continue;
        vis[now]=i,vis[i]=now;
        dfs(now+1);
        vis[now]=0,vis[i]=0;
    }
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n;i++){
        if(a[i].y==a[i+1].y)to[i]=i+1;
    }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}
/*

*/