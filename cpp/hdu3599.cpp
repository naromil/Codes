#include<bits/stdc++.h>
#define emp push_back
using namespace std;
using ll=long long;
const int kn=2e5+23,inf=0x3f3f3f3f;
class EDGE1{
	public: int y,w;
	bool operator < (const EDGE1 &v) const{ return w>v.w; }
};
int n,dis[kn];
bool vis[kn];
vector<EDGE1> c[kn];
void dijkstra(){
	for(int i=1;i<=n;++i) dis[i]=inf, vis[i]=false;
	priority_queue<EDGE1> pq;
	dis[1]=0;
	pq.push({1,0});
	while(!pq.empty()){
		int u=pq.top().y; pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto j: c[u]){
			int v=j.y;
			if(dis[v]>dis[u]+j.w){
				dis[v]=dis[u]+j.w;
				if(!vis[v]) pq.push({v,dis[v]});
			}
		}
	}
}
class EDGE2{ public: int y,w,r; }e[1145141];
int hd[kn],ct=1,crt[kn],lv[kn];
void cnct(int x,int y,int w){
	e[++ct].y=y; e[ct].w=w; e[ct].r=hd[x]; hd[x]=ct;
	e[++ct].y=x; e[ct].w=0; e[ct].r=hd[y]; hd[y]=ct;
}
bool bfs(){
	for(int i=1;i<=n;++i) crt[i]=hd[i], lv[i]=0;
	queue<int> q;
	q.push(1);
	lv[1]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int j=hd[u];j;j=e[j].r){
			int v=e[j].y;
			if(!e[j].w||lv[v]) continue;
			lv[v]=lv[u]+1;
			if(v==n) return true;
			q.push(v);
		}
	}
	return false;
}
int dinic(int u,int flw){
	if(u==n) return flw;
	int avi=flw;
	for(int j=crt[u];j&&avi;j=e[j].r){
		crt[u]=j;
		int v=e[j].y;
		if(!e[j].w||lv[v]!=lv[u]+1) continue;
		int ret=dinic(v,min(avi,e[j].w));
		if(!ret) lv[v]=0;
		avi-=ret;
		e[j].w-=ret;
		e[j^1].w+=ret;
	}
	return flw-avi;
}
int _solv(){
	cin>>n;
	ct=1;
	for(int i=1;i<=n;++i) c[i].clear(), hd[i]=0;
	for(int x,y,w;;){
		cin>>x>>y>>w;
		if(!x&&!y&&!w) break;
		c[x].emp({y,w});
		c[y].emp({x,w});
	}
	if(n==1) return 0;
	dijkstra();
	for(int i=1;i<=n;++i) for(auto j: c[i]) if(dis[j.y]==dis[i]+j.w) cnct(i,j.y,1);
	int ret=0;
	while(bfs()) ret+=dinic(1,inf);
	return ret;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) printf("%d\n",_solv());
	return 0;
}
