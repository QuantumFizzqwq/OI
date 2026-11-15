#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
const int N=100005;

int n,k;
int w[N];
vector<int> edge[N];
int dep[N];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	for(int y:edge[x]){
		if(y==f)continue;
		dfs(y,x);
	}
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n-1;i++){
		int u,v; cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(dep[i]-1<=2*k){
			ans+=w[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*

*/