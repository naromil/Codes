#include<bits/stdc++.h>
#define e1 md=(l+r)>>1
#define e2 ls=u<<1, rs=u<<1|1
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n,a[kn],ans[kn];
class SGT{
	public: int v[kn<<2],t[kn<<2];
	void pu(int u){
		int e2;
		v[u]=max(v[ls],v[rs]);
	}
	void pd(int u){
		int e2;
		v[ls]+=t[u]; v[rs]+=t[u]; t[ls]+=t[u]; t[rs]+=t[u]; t[u]=0;
	}
	void upd(int u,int l,int r,int x,int y,int w){
		if(l==x&&r==y){ t[u]+=w; v[u]+=w; return; }
		pd(u);
		int e1,e2;
		if(y<=md) upd(ls,l,md,x,y,w);
		else if(x>md) upd(rs,md+1,r,x,y,w);
		else upd(ls,l,md,x,md,w), upd(rs,md+1,r,md+1,y,w);
		pu(u);
	}
	int qry(int u,int l,int r,int x){
		if(l==r) return l;
		pd(u);
		int e1,e2;
		if(v[ls]>=x) return qry(ls,l,md,x);
		else return qry(rs,md+1,r,x);
	}
}G;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		G.upd(1,1,n,i,i,i);
	}
	for(int i=n;i>=1;--i){
		int x=G.qry(1,1,n,a[i]);
//		printf("%d %d: %d\n",i,a[i],x);
		ans[x]=i;
		G.upd(1,1,n,x,x,0xc1c1c1c1);
		if(x+1<=n) G.upd(1,1,n,x+1,n,-1);
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
