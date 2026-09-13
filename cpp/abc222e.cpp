#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1024,p=998244353;
int n,m,k,a[kn],fa[kn][10],dep[kn];
vector<int> nbr[kn];
void init(int cur,int pre){
	dep[cur]=dep[pre]+1; fa[cur][0]=pre;
	for(int i=1;i<10;++i) fa[cur][i]=fa[fa[cur][i-1]][i-1];
	for(auto nxt: nbr[cur]) if(nxt!=pre) init(nxt,cur);
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=9;i>=0;--i) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return y;
	for(int i=9;i>=0;--i) if(fa[x][i]!=fa[y][i]) x=fa[x][i], y=fa[y][i];
	return fa[y][0];
}
int val[kn];
void dfs(int cur,int pre){ for(auto nxt: nbr[cur]) if(nxt!=pre) dfs(nxt,cur), val[cur]+=val[nxt]; }
ll f[2][200022];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>a[i];
	for(int i=2;i<=n;++i){ int x,y; cin>>x>>y; nbr[x].push_back(y); nbr[y].push_back(x); }
	init(1,0);
	for(int i=2;i<=m;++i){ val[a[i]]++; val[a[i-1]]++; val[lca(a[i-1],a[i])]-=2; }
	dfs(1,0);

	f[1][100000]=1;
	for(int ii=2;ii<=n;++ii){
		int i=ii&1,pr=i^1;
		for(int j=val[ii];j<=200000;++j) f[i][j]=f[pr][j-val[ii]];
		for(int j=200000-val[ii];j>=0;--j) f[i][j]=(f[i][j]+f[pr][j+val[ii]])%p;
	}
	cout<<f[n&1][k+100000]<<'\n';
	return 0;
}
