#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,siz[kn],son[kn],dep[kn];
vector<int> c[kn];
ll ans=0;
void init(int u,int b){
	dep[u]=dep[b]+1;
	siz[u]=1;
	for(auto v: c[u]){
		if(v==b) continue;
		init(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
class TAR{
	public: ll t[kn];
	inline int lb(const int& x){ return -x&x; }
	inline void upd(int u,int w){
		for(;u<=n;u+=lb(u)) t[u]+=w;
	}
	inline ll qry(int u){
		ll res=0;
		for(;u;u-=lb(u)) res+=t[u];
		return res;
	}
	ll& operator [] (const int& i){ return t[i]; }
}t0,t1;
void dfs(int u,int b,int o){
	ll t0l=t0.qry(dep[u]), t1l=t1.qry(dep[u]), t1r=t1.qry(n);
//	printf("GET ANS FROM: %d %d: %lld %lld %lld\n",u,o,t0l,t1l,t1r);
	ans+=2*(t0l-t1l*o)-t1l;
	ans+=2*(t1r-t1l)*(dep[u]-o)-(t1r-t1l);
	for(auto v: c[u]) if(v!=b) dfs(v,u,o);
}
void upd(int u,int b,int w){
	t0.upd(dep[u],dep[u]*w);
	t1.upd(dep[u],w);
//	printf("UPD: %d %d: %d\n",u,dep[u],w);
	for(auto v: c[u]) if(v!=b) upd(v,u,w);
}
void dsu(int u,int b,int op){
//	printf("%d:\n",u);
	for(auto v: c[u]){
		if(v!=b&&v!=son[u]) dsu(v,u,0);
	}
	if(son[u]) dsu(son[u],u,1);
	for(auto v: c[u]){
		if(v!=b&&v!=son[u]){
			dfs(v,u,dep[u]);
			upd(v,u,1);
		}
	}
	t0.upd(dep[u],dep[u]);
	t1.upd(dep[u],1);
//	printf("UPD: %d %d: %d\n",u,dep[u],1);
	if(!op) upd(u,b,-1);
//	printf("RETURN\n");
}
inline void _solv(){
	cin>>n;
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
	}
	init(1,0);
	dsu(1,0,0);
	printf("%lld\n",ans);
	ans=0;
	for(int i=1;i<=n;++i){
		c[i].clear();
		t0[i]=t1[i]=son[i]=0;
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();// printf("\n\n\n\n");
	return 0;
}
