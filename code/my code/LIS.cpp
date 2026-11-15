#include<bits/stdc++.h>
using namespace std;
int LIS(vector<int>&nums){
	vector<int>tails;
	for(int x:nums){
		auto it=lower_bound(tails.begin(),tails.end(),x);
		if (it==tails.end()){
			tails.push_back(x);
		} 
		else{
			*it=x;
		}
	}
	return tails.size();
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	vector<int>sub1;
	vector<int>sub2;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=k-2;i++){
		if(a[i]<a[k-1]){
			sub1.push_back(a[i]);
		}
	}
	for(int i=k;i<=n-1;i++){
		if(a[i]>a[k-1]){
			sub2.push_back(a[i]);
		}
	}
	cout<<LIS(sub1)+LIS(sub2)+1;
}
