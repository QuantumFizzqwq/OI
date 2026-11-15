#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],b[10005],c[10005];
int f(int x,int i){
    //计算第 i 个函数对应的 f(x) 值
    return a[i]*x*x+b[i]*x+c[i];
}
struct Value{
    int x,i;//表示第 i 个函数对应的 f(x)
    bool operator<(Value y)const{
        return f(x,i)>f(y.x,y.i);
    }
};
priority_queue<Value> q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++) q.push(Value{1,i});
    for(int i=1;i<=m;i++){
        Value now=q.top();
        q.pop();
        cout<<f(now.x,now.i)<<' ';
        q.push(Value{now.x+1,now.i});
    }
    return 0;
}