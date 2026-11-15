#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
const int N=1000005;

int n,k,ans;
int a[N],b[N];
int check(int x){
	if(x==1)return 0;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return 0;
	}
	return 1;
}
void dfs(int now,int last){
	if(now==k+1){
		int sum=0;
		for(int i=1;i<=k;i++)sum+=b[i];
		if(check(sum))ans++;
		return;
	}
	for(int i=last+1;i<=n;i++){
		b[now]=a[i];
		dfs(now+1,i);
		b[now]=0;
	}
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
/*

*/