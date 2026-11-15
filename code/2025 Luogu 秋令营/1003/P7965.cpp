#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;

int n,m,q;
vector<int> edge[N];
int vis[N][N];
void bfs(int s){
	queue<int> q;
	q.push(s);
	vis[s][s]=1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int y:edge[x]){
			if(vis[s][y])continue;
			vis[s][y]=1;
			q.push(y);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int x; cin>>x;
			edge[j].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=q;i++){
		int a,b; cin>>a>>b;
		if(vis[a][b]){
			cout<<"DA"<<'\n';
		}else{
			cout<<"NE"<<'\n';
		}
	}
	return 0;
}
/*

*/