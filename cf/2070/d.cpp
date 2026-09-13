#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=6e5+65,p=998244353;
int n,dep[kn],id[kn],lbod[kn],rbod[kn];
vector<int> c[kn];
class SGT{
	public: ll t[kn<<2],v[kn<<2];
	inline void pd(int u){ int ls=u<<1, rs=u<<1|1; v[ls]=(v[ls]+v[u])%p; v[rs]=(v[rs]+v[u])%p; t[ls]=(t[ls]+v[u])%p; t[rs]=(t[rs]+v[u])%p; v[u]=0; }
	ll qry(int u,int l,int r,int x){
		if(l==r) return t[u];
		pd(u);
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		if(x<=md) return qry(ls,l,md,x);
		else return qry(rs,md+1,r,x);
	}
	void upd(int u,int l,int r,int x,int y,int w){
		if(l==x&&r==y){ t[u]=(t[u]+w)%p; v[u]=(v[u]+w)%p; return; }
		pd(u);
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		if(y<=md) upd(ls,l,md,x,y,w);
		else if(x>md) upd(rs,md+1,r,x,y,w);
		else upd(ls,l,md,x,md,w), upd(rs,md+1,r,md+1,y,w);
	}
	void bud(int u,int l,int r){
		v[u]=t[u]=0;
		if(l==r){ t[u]=(l==1); return; }
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		bud(ls,l,md);
		bud(rs,md+1,r);
	}
}S;
inline void bfs(){
	queue<int> q;
	int ct=0;
	dep[1]=1;
	q.push(1);
	while(!q.empty()){
		int u=q.front(); q.pop();
		id[u]=++ct;
		if(!lbod[dep[u]]) lbod[dep[u]]=id[u];
		rbod[dep[u]]=id[u];
		for(auto v: c[u]){
			dep[v]=dep[u]+1;
			q.push(v);
		}
	}
}
ll ans[kn];
inline void bfs2(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u=q.front(); q.pop();
		ans[u]=S.qry(1,1,n,id[u]);
		if(lbod[dep[u]+1]&&lbod[dep[u]+1]<=rbod[dep[u]+1]&&rbod[dep[u]+1]<=n) S.upd(1,1,n,lbod[dep[u]+1],rbod[dep[u]+1],ans[u]);
		for(auto v: c[u]){
			if(u!=1) S.upd(1,1,n,id[v],id[v],-ans[u]);
			q.push(v);
		}
	}
}
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		lbod[i]=rbod[i]=id[i]=0;
		c[i].clear();
	}
	for(int i=2,x;i<=n;++i){ cin>>x; c[x].emp(i); }
	S.bud(1,1,n);
	bfs();
	bfs2();
	ll anss=0;
	for(int i=1;i<=n;++i) anss=(anss+ans[i])%p;
	printf("%lld\n",(anss+p)%p);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
