#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1000;
const int mod=1e9+7;
int f(int n, int p[],int c[]){
	int tot=0;
	if(n<2)
		return 0;
	int num=0;
	while(n%2==0){
		num++;
		n/=2;
	}
	if(num>0){
		p[tot]=2;
		c[tot]=num;
		tot++;
	}
	for(long long i=3;i*i<=n;i+=2){
		num=0;
		while(n%i==0){
			num++;
			n/=i;
		}
		if(num>0){
			p[tot]=i;
			c[tot]=num;
			tot++;
		}
	}
	if(n>1){
		p[tot]=n;
		c[tot]=1;
		tot++;
	}
	return tot;
}
signed main(){
	
	return 0;
}
