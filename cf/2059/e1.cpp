#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;
const int kn=3e5+35;
int n,m,N,b[kn],I,J,K;
vector<int> a[kn];
class QUERY{
	public:
	int i,j,w;
};
vector<QUERY> qs;
class SGT{
	public: int v[kn<<2],t[kn<<2];
	inline void pu(int u){
		int ls=u<<1, rs=u<<1|1;
		v[u]=min(v[ls],v[rs]);
	}
	inline void pd(int u){
		int ls=u<<1, rs=u<<1|1;
		v[ls]+=t[u]; v[rs]+=t[u]; t[ls]+=t[u]; t[rs]+=t[u]; t[u]=0;
	}
	void bud(int u,int l,int r){
		v[u]=0x3f3f3f3f;
		t[u]=0;
		if(l==r) return;
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		bud(ls,l,md);
		bud(rs,md+1,r);
	}
	void upd(int u,int l,int r,int x,int w){
		if(l==r){ v[u]=w; return; }
		pd(u);
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		if(x<=md) upd(ls,l,md,x,w);
		else upd(rs,md+1,r,x,w);
		pu(u);
	}
	void dec(int u,int l,int r,int x,int y){
		if(l==x&&r==y){ --v[u]; --t[u]; return; }
		pd(u);
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		if(y<=md) dec(ls,l,md,x,y);
		else if(x>md) dec(rs,md+1,r,x,y);
		else dec(ls,l,md,x,md), dec(rs,md+1,r,md+1,y);
		pu(u);
	}
	int fnd(int u,int l,int r){
		if(l==r) return l;
		pd(u);
		int md=(l+r)>>1, ls=u<<1, rs=u<<1|1;
		if(v[rs]==0) return fnd(rs,md+1,r);
		else return fnd(ls,l,md);
	}
}T;
inline void _solv(){
	cin>>n>>m;
	I=0; J=m; K=0;
	qs.clear();
	T.bud(1,1,n);

	for(int i=1;i<=n;++i){
		a[i].resize(m+5);
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n*m;++i){
		cin>>b[i];
	}

	for(int i=1,k=0,num=0,brk=0;i<=n;++i){
		for(int j=1;j<=m;++j){
			while(k<n*m && b[++k]!=a[i][j]){
				if(num<(j==1?0:m-j+1)) break;
				++num;
				if(j==1) qs.pb({i-1,m,b[k]});
				else qs.pb({i,j-1,b[k]});
			}
//			printf("%d %d - %d\n",i,j,k);
			if(b[k]!=a[i][j]){ brk=1; break; }
			if(j==m||num>=m-j){ I=i; J=j; K=k; }
		}
		if(brk) break;
	}
	while(!qs.empty() && (qs.back().i>I || (qs.back().i==I&&qs.back().j>=J))) qs.pop_back();
	for(++K;K<=n*m;++K) qs.pb({I,J,b[K]});
	N=qs.size();
	printf("%d\n",N);

	for(int j=1;j<=N;++j){
		T.upd(1,1,N,j,m-qs[j-1].j);
	}
	for(int i=1;i<=N;++i){
		int j=T.fnd(1,1,N);
		printf("%d %d\n",qs[j-1].i+1,qs[j-1].w);
		T.upd(1,1,N,j,0x3f3f3f3f);
		if(j+1<=N) T.dec(1,1,N,j+1,N);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
