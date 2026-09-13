#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n,q,rot;
vector<int> nbr[kn];
int fa[kn][20],dep[kn];
int low[kn],dfn[kn],dft=0;
void init(int cur,int pre){
	low[cur]=dfn[cur]=++dft;
	dep[cur]=dep[pre]+1;
	fa[cur][0]=pre;
	for(int i=1;i<20;++i) fa[cur][i]=fa[fa[cur][i-1]][i-1];
	for(auto nxt: nbr[cur]){
		if(nxt==pre) continue;
		init(nxt,cur);
		low[cur]=max(low[cur],low[nxt]);
	}
}
bool is_anc(int x,int y){return dfn[x]<=dfn[y]&&low[x]>=dfn[y];}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	if(is_anc(x,y)) return x;
	for(int i=19;i>=0;--i) if(fa[x][i]&&!is_anc(fa[x][i],y)) x=fa[x][i];
	return fa[x][0];
}
signed main(){
	scanf("%d %d %d",&n,&q,&rot);
	for(int i=2;i<=n;++i){
		int x,y; scanf("%d %d",&x,&y);
		nbr[x].pb(y), nbr[y].pb(x);
	}
	init(rot,0);
	for(int i=1;i<=q;++i){
		int x,y; scanf("%d %d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
