#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25,p=998244353;
int n,m,V,a[kn];
vector<int> c[kn];
int dfn[kn],low[kn],dft=0,dcc[kn],dct=0,siz[kn];
stack<int> stk;
int col[kn],mul[kn];
bool odd[kn];
void tarjan(int u,int b=0){
	dfn[u]=low[u]=++dft;
	stk.push(u);
	bool tob=false;
	for(auto v: c[u]){
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(tob||v!=b) low[u]=min(low[u],dfn[v]);
		else tob=true;
	}
	if(dfn[u]==low[u]){
		++dct;
		while(!stk.empty()){
			int cr=stk.top(); stk.pop();
			dcc[cr]=dct;
			siz[dct]+=(a[cr]==-1);
			if(a[cr]>=0){
				if(mul[dct]==-1) mul[dct]=a[cr];
				else if(mul[dct]!=a[cr]) mul[dct]=-2;
			}
			if(cr==u) break;
		}
	}
}
void dfs(int u,int b){
	for(auto v: c[u]){
		if(dcc[v]!=dcc[u]) continue;
		if(col[v]==-1){ col[v]=col[u]^1; dfs(v,u); }
		else if(col[v]==col[u]) odd[dcc[u]]=true;
	}
}
inline void _solv(){
	cin>>n>>m>>V;
	dft=dct=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		dfn[i]=low[i]=odd[i]=siz[i]=0;
		col[i]=mul[i]=-1;
		c[i].clear();
	}
	for(int i=1,x,y;i<=m;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;++i){
		if(col[i]==-1){ col[i]=0; dfs(i,0); }
	}
//	for(int i=1;i<=n;++i){
//		printf("%d: %d\n",i,dcc[i]);
//	}
	ll ans=1;
	for(int i=1;i<=dct;++i){
//		printf("DCC %d: %d %d %d\n",i,siz[i],odd[i],mul[i]);
		if(odd[i]&&mul[i]>0||mul[i]==-2){ ans=0; break; }
		else if(!odd[i]&&mul[i]==-1) ans=ans*V%p;
	}
	printf("%lld\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
