#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
const int N=1000005;

string s;
int n;
int a[N];
int ls[N],rs[N];
int stk[N],top;
char c[N];
int cnt;
int vis[N],rev[N];
void dfs(int x){
	if(c[x]=='&'){
		if((a[rs[x]]^rev[rs[x]])==1){
			if(ls[x]<=n)vis[ls[x]]=1;
			else dfs(ls[x]);
		}
		if((a[ls[x]]^rev[ls[x]])==1){
			if(rs[x]<=n)vis[rs[x]]=1;
			else dfs(rs[x]);
		}
	}else{
		if((a[rs[x]]^rev[rs[x]])==0){
			if(ls[x]<=n)vis[ls[x]]=1;
			else dfs(ls[x]);
		}
		if((a[ls[x]]^rev[ls[x]])==0){
			if(rs[x]<=n)vis[rs[x]]=1;
			else dfs(rs[x]);
		}
	}
}
signed main()
{
	getline(cin,s);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int num=0;
	cnt=n;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')num=num*10+s[i]-'0';
		else{
			if(num)stk[++top]=num,num=0;
			if(s[i]=='&'||s[i]=='|'){
				c[++cnt]=s[i];
				int x=stk[top--],y=stk[top--];
				if(s[i]=='&'){
					a[cnt]=((a[x]^rev[x])&(a[y]^rev[y]));
				}else a[cnt]=((a[x]^rev[x])|(a[y]^rev[y]));
				ls[cnt]=x,rs[cnt]=y,stk[++top]=cnt;
			}
			if(s[i]=='!')rev[stk[top]]^=1;
		}
	}
	int rt=stk[1],ans=a[rt];
	dfs(rt);
	int q; cin>>q;
	for(int i=1;i<=q;i++){
		int x; cin>>x;
		cout<<(ans^rev[rt]^vis[x])<<'\n';
	}
	return 0;
}
/*

*/