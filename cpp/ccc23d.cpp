#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2048;
class EDGE{ public: int y,w,c,r; }e[kn<<1];
int n,m,hd[kn],ct=1,vis[kn],cst[kn],pre[kn];
inline void addedge(int x,int y,int w,int c){ e[++ct].y=y; e[ct].w=w; e[ct].c=c; e[ct].r=hd[x]; hd[x]=ct; }
ll dis[kn];
class PRIO{ public: int u; ll w,c; bool operator < (const PRIO& v) const { return (w!=v.w ? w>v.w : c>v.c); } };
inline void dijkstra(int o){
	memset(dis,0x3f,sizeof dis);
	memset(cst,0x3f,sizeof cst);
	memset(vis,0,sizeof vis);
	priority_queue<PRIO> pq;
	pq.push({o,0ll,0ll});
	pre[o]=dis[o]=cst[o]=0;
	while(!pq.empty()){
		PRIO nr=pq.top(); pq.pop();
		if(vis[nr.u]) continue;
		vis[nr.u]=true;
		int u=nr.u;
		for(int j=hd[u];j;j=e[j].r){
			int v=e[j].y, w=e[j].w, c=e[j].c;
			if(dis[v]>dis[u]+w||dis[v]==dis[u]+w&&cst[v]>c){
				dis[v]=dis[u]+w;
				cst[v]=c;
				pre[v]=j;
				pq.push({v,dis[v],c});
			}
		}
	}
	for(int i=1;i<=n;++i) e[pre[i]].c=e[pre[i]^1].c=0;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	ll ans=0;
	for(int i=1,x,y,w,c;i<=m;++i){
		cin>>x>>y>>w>>c;
		addedge(x,y,w,c);
		addedge(y,x,w,c);
		ans+=c;
	}
	for(int i=1;i<=n;++i) dijkstra(i);
	for(int j=2;j<=ct;j+=2) ans-=e[j].c;
	printf("%lld\n",ans);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2048;
class EDGE{ public: int y,w,c,r; }e[kn<<1];
int hd[kn],ct=1;
inline void addedge(int x,int y,int w,int c){ e[++ct]={y,w,c,hd[x]}; hd[x]=ct; }
int n,m,vis[kn];
ll dis[kn],cst[kn];
class PRIO{ public: int u; ll w,c; bool operator < (const PRIO& v) const { return (w!=v.w)?w<v.w:c<v.c; }
inline void dijkstra(int o){
	memset(dis,0x3f,sizeof dis);
	memset(cst,0x3f,sizeof cst);
	memset(vis,0,sizeof vis);
	priority_queue<PRIO> pq;
	dis[o]=cst[o]=0;
	pq.push({o,0,0});
	while(!pq.empty()){
		PRIO nr=pq.top(); pq.pop();
		if(vis[nr.u]) continue;
		vis[nr.u]=true;
		int u=nr.u;
		for(int j=hd[u];j;j=e[j].r){
			int v=e[j].y, w=e[j].w, c=e[j].c;
			if(dis[v]>dis[u]+w || dis[v]==dis[u]+w&&cst[v]>cst[u]+c){
				dis[v]=dis[u]+w;
				cst[v]=cst[u]+c;
				pq.push({v,dis[v],cst[v]});
			}
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y,w,c;i<=m;++i){
		cin>>x>>y>>w>>c;
		addedge(x,y,w,c);
		addedge(y,x,w,c);
	}
	for(int i=1;i<=n;++i) dijkstra(i);
	return 0;
}

5 7
1 2 15 1
2 4 9 9
5 2 5 6
4 5 4 4
4 3 3 7
1 3 2 7
1 4 2 1
*/

