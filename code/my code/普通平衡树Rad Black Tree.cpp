#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
const int MAXN=1000010;
const bool BLACK=0;   //黑色节点
const bool RED=1;     //红色节点
//红黑树节点结构体
rope<int>a;
struct Node{
	int val;//节点存储的值
	bool color;//节点颜色 RED/BLACK
	int l,r,fa;//左孩子、右孩子、父节点编号
	int cnt;//当前数值重复次数（支持重复元素）
	int size;//以当前节点为根的子树总节点数量(包含重复cnt)
}tr[MAXN];
int root,tot;//root根节点编号，tot节点分配计数器
const int NIL=0;//NIL代表空叶子节点（哨兵节点，简化边界判断）
//初始化红黑树
void init(){
	tr[NIL].color=BLACK;
	tr[NIL].l=tr[NIL].r=tr[NIL].fa=0;
	tr[NIL].size=tr[NIL].cnt=0;
	root=NIL;
	tot=0;
}
//向上更新size信息
inline void pushup(int u){
	tr[u].size=tr[tr[u].l].size+tr[tr[u].r].size+tr[u].cnt;
}
//新建一个值为v的红色节点
int newnode(int v){
	++tot;
	tr[tot].val=v;
	tr[tot].color=RED;
	tr[tot].l=tr[tot].r=NIL;
	tr[tot].fa=NIL;
	tr[tot].cnt=1;
	tr[tot].size=1;
	return tot;
}
//左旋：以u为支点左旋
void rotate_left(int u){
	int v=tr[u].r;
	tr[u].r=tr[v].l;
	if(tr[v].l!=NIL) 
		tr[tr[v].l].fa=u;
	tr[v].fa=tr[u].fa;
	if(tr[u].fa==NIL) 
		root=v;
	else if(tr[tr[u].fa].l==u) 
		tr[tr[u].fa].l=v;
	else 
		tr[tr[u].fa].r=v;
	tr[v].l=u;
	tr[u].fa=v;
	pushup(u);pushup(v);
}
//右旋：以u为支点右旋
void rotate_right(int u){
	int v=tr[u].l;
	tr[u].l=tr[v].r;
	if(tr[v].r!=NIL) 
		tr[tr[v].r].fa=u;
	tr[v].fa=tr[u].fa;
	if(tr[u].fa==NIL) root=v;
	else if(tr[tr[u].fa].l==u) 
		tr[tr[u].fa].l=v;
	else 
		tr[tr[u].fa].r=v;
	tr[v].r=u;
	tr[u].fa=v;
	pushup(u);pushup(v);
}
//插入节点之后，向上调整修复红黑树性质
void insert_fix(int u){
	while(tr[tr[u].fa].color==RED){
		int f=tr[u].fa;//父亲
		int gf=tr[f].fa;//祖父
		if(tr[gf].l==f){//父亲是祖父左子树
			int uncle=tr[gf].r;//叔叔（祖父右孩子）
			if(tr[uncle].color==RED){
				tr[f].color=BLACK;
				tr[uncle].color=BLACK;
				tr[gf].color=RED;
				u=gf;
			}
			else{
				if(tr[f].r==u){
					rotate_left(f);
					u=f;
					f=tr[u].fa;
				}
				tr[f].color=BLACK;
				tr[gf].color=RED;
				rotate_right(gf);
			}
		}
		else{//父亲是祖父右子树，对称操作
			int uncle=tr[gf].l;
			if(tr[uncle].color==RED){
				tr[f].color=BLACK;
				tr[uncle].color=BLACK;
				tr[gf].color=RED;
				u=gf;
			}
			else{
				if(tr[f].l==u){
					rotate_right(f);
					u=f;
					f=tr[u].fa;
				}
				tr[f].color=BLACK;
				tr[gf].color=RED;
				rotate_left(gf);
			}
		}
	}
	tr[root].color=BLACK;
}
//插入数值x（支持重复值）
void insert(int x){
	int cur=root,p=NIL;
	while(cur!=NIL){
		p=cur;
		pushup(cur);
		if(tr[cur].val==x){
			tr[cur].cnt++;
			pushup(cur);
			return;
		}
		cur=(x<tr[cur].val)?tr[cur].l:tr[cur].r;
	}
	int nw=newnode(x);
	tr[nw].fa=p;
	if(p==NIL) root=nw;
	else if(x<tr[p].val) tr[p].l=nw;
	else tr[p].r=nw;
	insert_fix(nw);
}
//查找以u为根的最小值（最靠左节点，删除用）
int get_min(int u){
	while(tr[u].l!=NIL) 
		u=tr[u].l;
	return u;
}
//移植：用v子树替换u子树
void transplant(int u,int v){
	if(tr[u].fa==NIL) root=v;
	else if(tr[tr[u].fa].l==u) 
		tr[tr[u].fa].l=v;
	else 
		tr[tr[u].fa].r=v;
	tr[v].fa=tr[u].fa;
}
//删除后修复红黑树性质
void del_fix(int u){
	while(u!=root&&tr[u].color==BLACK){
		int f=tr[u].fa;
		if(tr[f].l==u){//u是左孩子
			int bro=tr[f].r; //兄弟节点
			if(tr[bro].color==RED){
				tr[bro].color=BLACK;
				tr[f].color=RED;
				rotate_left(f);
				bro=tr[f].r;
			}
			if(tr[tr[bro].l].color==BLACK&&tr[tr[bro].r].color==BLACK){
				tr[bro].color=RED;
				u=f;
			}
			else{
				if(tr[tr[bro].r].color==BLACK){
					tr[tr[bro].l].color=BLACK;
					tr[bro].color=RED;
					rotate_right(bro);
					bro=tr[f].r;
				}
				tr[bro].color=tr[f].color;
				tr[f].color=BLACK;
				tr[tr[bro].r].color=BLACK;
				rotate_left(f);
				u=root;
			}
		}
		else{  //u是右孩子，完全对称
			int bro=tr[f].l;
			if(tr[bro].color==RED){
				tr[bro].color=BLACK;
				tr[f].color=RED;
				rotate_right(f);
				bro=tr[f].l;
			}
			if(tr[tr[bro].l].color==BLACK&&tr[tr[bro].r].color==BLACK){
				tr[bro].color=RED;
				u=f;
			}
			else{
				if(tr[tr[bro].l].color==BLACK){
					tr[tr[bro].r].color=BLACK;
					tr[bro].color=RED;
					rotate_left(bro);
					bro=tr[f].l;
				}
				tr[bro].color=tr[f].color;
				tr[f].color=BLACK;
				tr[tr[bro].l].color=BLACK;
				rotate_right(f);
				u=root;
			}
		}
	}
	tr[u].color=BLACK;
}
//删除一个x（多个相同值只减少计数，数量为1时真正删除节点）
void remove(int x){
	int cur=root;
	while(cur!=NIL){
		if(tr[cur].val==x) break;
		cur=x<tr[cur].val?tr[cur].l:tr[cur].r;
	}
	if(cur==NIL) 
		return;
	if(tr[cur].cnt>1){
		tr[cur].cnt--;
		pushup(cur);
		return;
	}
	int y=cur;
	bool y_old_color=tr[y].color;
	int child;
	if(tr[cur].l==NIL){
		child=tr[cur].r;
		transplant(cur,tr[cur].r);
	}
	else if(tr[cur].r==NIL){
		child=tr[cur].l;
		transplant(cur,tr[cur].l);
	}
	else{
		y=get_min(tr[cur].r);
		y_old_color=tr[y].color;
		child=tr[y].r;
		if(tr[y].fa==cur) 
			tr[child].fa=y;
		else{
			transplant(y,tr[y].r);
			tr[y].r=tr[cur].r;
			tr[tr[y].r].fa=y;
		}
		transplant(cur,y);
		tr[y].l=tr[cur].l;
		tr[tr[y].l].fa=y;
		tr[y].color=tr[cur].color;
		pushup(y);
	}
	if(y_old_color==BLACK) 
		del_fix(child);
}
//查询小于x元素总个数
int get_less(int x){
	int u=root,res=0;
	while(u!=NIL){
		if(tr[u].val>=x){
			u=tr[u].l;
		}else{
			res+=tr[tr[u].l].size+tr[u].cnt;
			u=tr[u].r;
		}
	}
	return res;
}
//查询第k小元素
int get_kth(int k){
	int u=root;
	while(u!=NIL){
		int lsz=tr[tr[u].l].size;
		if(k<=lsz){
			u=tr[u].l;
		}else if(k<=lsz+tr[u].cnt){
			return tr[u].val;
		}else{
			k-=lsz+tr[u].cnt;
			u=tr[u].r;
		}
	}
	return 0;
}
//查找前驱
int get_pre(int x){
	int res=-1e9;
	int u=root;
	while(u!=NIL){
		if(tr[u].val<x){
			res=tr[u].val;
			u=tr[u].r;
		}
		else 
			u=tr[u].l;
	}
	return res;
}
//查找后继：大于x的最小值
int get_suc(int x){
	int res=1e9;
	int u=root;
	while(u!=NIL){
		if(tr[u].val>x){
			res=tr[u].val;
			u=tr[u].l;
		}
		else 
			u=tr[u].r;
	}
	return res;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int n,opt,x;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	n=read();
	while(n--){
		opt=read();
		x=read();
		if(opt==1) 
			insert(x);
		else if(opt==2) 
			remove(x);
		else if(opt==3) 
			cout<<get_less(x)+1<<'\n';
		else if(opt==4) 
			cout<<get_kth(x)<<'\n';
		else if(opt==5) 
			cout<<get_pre(x)<<'\n';
		else if(opt==6) 
			cout<<get_suc(x)<<'\n';
	}
	return 0;
}