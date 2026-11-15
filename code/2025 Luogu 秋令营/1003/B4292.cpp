#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
const int N=100005;

int n,m;
vector<int> edge[N];
int dis[N];
void bfs(){
    queue<int> q;
    memset(dis,-1,sizeof(dis));
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int y:edge[x]){
            if(dis[y]!=-1)continue;
            dis[y]=dis[x]+1;
            q.push(y);
        }
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    bfs();
    for(int i=1;i<=n-1;i++){
        cout<<dis[i]<<' ';
    }
    return 0;
}
/*

*/