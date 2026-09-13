#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
using namespace std;
using ll=long long;
const int kn=88;
int n,m,M,q,a[kn][kn],f[512][kn],ans[kn][kn],vis[kn];
inline void getmin(int& x,int y){ if(y<x) x=y; }
void dfs(const int& k,const int& i,int j,int res){
	if(j>m){ getmin(f[k][i],f[res][i]+f[k^res][i]); return; }
	if(k>>j&1){ dfs(k,i,j+1,res^(1<<j)); }
	dfs(k,i,j+1,res);
}
inline void dijkstra(const int& k){
	memset(vis,0,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for(int i=1;i<=n;++i){ pq.push(mp(f[k][i],i)); }
	while(!pq.empty()){
		int u=pq.top().y; pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=1;i<=n;++i){
			if(f[k][i]>f[k][u]+a[u][i]){
				f[k][i]=f[k][u]+a[u][i];
				pq.push(mp(f[k][i],i));
			}
		}
	}
}
inline void _solv(int u){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;++i){
		f[0][i]=0;
		if(i<=m) f[1<<i-1][i]=0;
		if(i==u) f[1<<m][i]=0;
	}
	for(int k=0;k<M;++k){
		for(int i=1;i<=n;++i){ dfs(k,i,0,0); }
		dijkstra(k);
	}
	for(int i=1;i<=n;++i){
		ans[u][i]=f[M-1][i];
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	M=(1<<m+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){ cin>>a[i][j]; }
	cin>>q;
	for(int i=1;i<=n;++i) _solv(i);
	for(int i=1,x,y;i<=q;++i){
		cin>>x>>y;
		printf("%lld\n",ans[x][y]);
	}
	return 0;
}
