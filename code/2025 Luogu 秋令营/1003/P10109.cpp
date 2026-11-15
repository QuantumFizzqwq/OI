










#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
const int N=10005;

int n,q;
int fa[N];
int cnt[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n-1;i++)cin>>fa[i];
	cin>>q;
	for(int i=1;i<=q;i++){
		int m; cin>>m;
		for(int j=1;j<=n;j++)cnt[j]=0;
		for(int j=1;j<=m;j++){
			int x; cin>>x;
			while(x){
				cnt[x]++; x=fa[x];
			}
		}
		int ans=0;
		for(int j=n;j>=1;j--)if(cnt[j]==m){ans=j; break;}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

*/
