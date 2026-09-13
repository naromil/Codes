#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=4e5+45;
int n,a[kn],rp[kn],m=0,dfn[kn],siz[kn],fa[kn][20],dep[kn],nxt[kn];
vector<int> c[kn];
void dfs(int u,int b){
	dep[u]=dep[b]+1;
	dfn[u]=++m;
	siz[u]=1;
	fa[u][0]=b;
	for(int i=1;i<20;++i){ fa[u][i]=fa[fa[u][i-1]][i-1]; }
	for(auto v: c[u]){
		if(v==b) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
inline int lca(int x,int y){
	if(!x||!y) return x|y;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;--i) if(dep[fa[x][i]]>=dep[y]){ x=fa[x][i]; }
	if(x==y) return y;
	for(int i=19;i>=0;--i) if(fa[x][i]!=fa[y][i]){ x=fa[x][i]; y=fa[y][i]; }
	return fa[y][0];
}
class SGT{
	public: int t[kn<<2];
	void bud(int u,int l,int r){
		t[u]=0;
		if(l==r) return;
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		bud(ls,l,md);
		bud(rs,md+1,r);
	}
	void upd(int u,int l,int r,int x,int w){
		if(l==r){ t[u]=w; return; }
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		if(x<=md) upd(ls,l,md,x,w);
		else upd(rs,md+1,r,x,w);
		t[u]=lca(t[ls],t[rs]);
	}
	int qry(int u,int l,int r,int x,int y){
		if(x>y||x<l||y>r) return 0;
		if(l==x&&r==y) return t[u];
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		if(y<=md) return qry(ls,l,md,x,y);
		else if(x>md) return qry(rs,md+1,r,x,y);
		else return lca(qry(ls,l,md,x,md), qry(rs,md+1,r,md+1,y));
	}
}S,G;
int ttt=0;
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
	}
	dfs(1,0);
	iota(rp+1,rp+n+1,1);
	sort(rp+1,rp+n+1,[](int x,int y){ return a[x]>a[y]; });
	vector<int> ans,buf;
	for(int I=1;I<=n;++I){
		if(a[rp[I]]!=a[rp[I-1]]){
			for(auto i: buf){
				S.upd(1,1,n,dfn[i],i);
				G.upd(1,1,n,dfn[i],nxt[i]);
			}
			buf.clear();
		}
		int i=rp[I];
		nxt[i]=lca(S.qry(1,1,n,1,dfn[i]-1), S.qry(1,1,n,dfn[i]+siz[i],n));
		int cr=lca(G.qry(1,1,n,1,dfn[i]-1), G.qry(1,1,n,dfn[i]+siz[i],n));
		buf.emp(i);
		if(nxt[i] && (cr==0 || dfn[cr]>=dfn[i] && dfn[cr]<=dfn[i]+siz[i]-1)) ans.emp(i);
	}
	sort(ans.begin(),ans.end());
	printf("%ld ",ans.size());
	for(auto u: ans) printf("%d ",u);
	printf("\n");
	for(int i=1;i<=n;++i){
		c[i].clear();
		a[i]=rp[i]=dfn[i]=siz[i]=dep[i]=nxt[i]=0;
		for(int k=0;k<20;++k) fa[i][k]=0;
	}
	m=0;
	S.bud(1,1,n);
	G.bud(1,1,n);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) ++ttt, _solv();
	return 0;
}
