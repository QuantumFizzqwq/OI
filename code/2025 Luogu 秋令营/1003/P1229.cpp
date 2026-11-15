#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define ll long long
const int N=10005;

string s,t;

signed main()
{
	cin>>s>>t;
	int cnt=0;
	for(int i=0;i<(int)s.size()-1;i++){
		for(int j=0;j<t.size();j++){
			if(s[i]==t[j]&&j-1>=0&&s[i+1]==t[j-1])cnt++;
		}
	}
	cout<<(1ll<<cnt)<<'\n';
	return 0;
}
/*

*/