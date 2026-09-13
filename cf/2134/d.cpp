#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,O,OA,OB,fa[kn],in[kn],dep[kn],low[kn],high[kn];
vector<int> c[kn];
void dfs(int u,int b){
	dep[u]=dep[b]+1;
	low[u]=high[u]=(c[u].size()==1 ? u : 0);
	for(auto v: c[u]){
		if(v==b||v==OA||v==OB) continue;
		dfs(v,u);
		if(low[u]==0||dep[low[u]]<dep[low[v]]) low[u]=low[v];
		if(high[u]==0||dep[high[u]]>dep[high[v]]) high[u]=high[v];
	}
}
void FDdfs1(int u,int b){
	dep[u]=dep[b]+1;
	if(dep[u]>dep[OA]) OA=u;
	for(auto v: c[u]){
		if(v==b) continue;
		FDdfs1(v,u);
	}
}
void FDdfs2(int u,int b){
	dep[u]=dep[b]+1;
	fa[u]=b;
	if(dep[u]>dep[OB]) OB=u;
	for(auto v: c[u]){
		if(v==b) continue;
		FDdfs2(v,u);
	}
}
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		c[i].clear();
		fa[i]=low[i]=high[i]=dep[i]=in[i]=0;
	}
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		c[x].emp(y); c[y].emp(x);
		++in[x]; ++in[y];
	}
	O=OA=OB=0;
	FDdfs1(1,0);
	FDdfs2(OA,0);
	O=OB;
	while(O!=OA){
		if(in[fa[O]]>2){ OA=fa[fa[O]]; OB=O; O=fa[O]; break; }
		O=fa[O];
	}
	if(in[O]<=2){ printf("-1\n"); return; }
	dfs(O,0);
	int U=0,V=0;
	for(auto cr: c[O]){
		if(high[cr]==high[O]) V=cr;
//		if(V==0||dep[high[cr]]<dep[high[V]]){
//			if(!U) U=V;
//			V=cr;
//		}
//		else if(U==0||dep[low[cr]]>dep[low[U]]){
//			U=cr;
//		}
	}
	printf("%d %d %d\n",OA,O,V);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
