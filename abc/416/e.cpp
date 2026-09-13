#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,K,T,q,E[555][555];
inline void addedge(int x,int y,int w){ E[x][y]=min(E[x][y],w); }
ll dis[555][555];
int vis[555];
class PQ{ public: int x; ll w; bool operator < (const PQ& v) const { return w>v.w; } };
inline void dijkstra(int o){
	memset(dis[o],0x3f,sizeof dis[o]);
	memset(vis,0,sizeof vis);
	priority_queue<PQ> pq;
	pq.push({o,dis[o][o]=0});
	while(!pq.empty()){
		int u=pq.top().x; pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v=1;v<=n+1;++v){
			if(dis[o][v]>dis[o][u]+E[u][v]){
				dis[o][v]=dis[o][u]+E[u][v];
				if(!vis[v]) pq.push({v,dis[o][v]});
			}
		}
	}
}
ll ans=0;
inline void update(int o,int x,int y){
	if(dis[o][y]<=dis[o][x]+E[x][y]) swap(x,y);
	if(dis[o][y]<=dis[o][x]+E[x][y]) return;
	if(dis[o][y]<1e18) ans-=dis[o][y]-dis[o][x]-E[x][y];
	dis[o][y]=dis[o][x]+E[x][y];
	for(int v=1;v<=n+1;++v){
		if(dis[o][v]>dis[o][y]+dis[y][v]){
			if(dis[o][v]<1e18) ans-=dis[o][v]-dis[o][y]-dis[y][v];
			dis[o][v]=dis[o][y]+dis[y][v];
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	memset(E,0x3f,sizeof E);
	cin>>n>>m;
	for(int i=1,x,y,w;i<=m;++i){
		cin>>x>>y>>w;
		addedge(x,y,w);
		addedge(y,x,w);
	}
	cin>>K>>T;
	for(int i=1,x;i<=K;++i){
		cin>>x;
		addedge(x,n+1,T);
		addedge(n+1,x,T);
	}
	for(int i=1;i<=n+1;++i) dijkstra(i);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(dis[i][j]<1e18) ans+=dis[i][j];
	cin>>q;
	for(int cs=1,op,x,y,w;cs<=q;++cs){
		cin>>op;
		if(op==1){
			cin>>x>>y>>w;
			addedge(x,y,w);
			addedge(y,x,w);
			for(int i=1;i<=n+1;++i) update(i,x,y);
		}
		else if(op==2){
			cin>>x;
			addedge(x,n+1,T);
			addedge(n+1,x,T);
			for(int i=1;i<=n+1;++i) update(i,x,n+1);
		}
		else{
			printf("%lld\n",ans);
		}
	}
	return 0;
}
