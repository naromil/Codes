#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5555;
const ll inf=0x3f3f3f3f3f3f3f3f;
int N,M,S,T;
class EDGE{ public: int y,r; ll w; }e[kn<<1];
int hd[kn],ct=1;
void cnct(int x,int y,ll w){
	e[++ct].y=y; e[ct].w=w; e[ct].r=hd[x]; hd[x]=ct;
	e[++ct].y=x; e[ct].w=0; e[ct].r=hd[y]; hd[y]=ct;
}
int crt[kn],lv[kn];
bool bfs(){
	memset(lv,0,sizeof lv);
	for(int i=1;i<=T;++i) crt[i]=hd[i]; ////
	queue<int> q;
	q.push(S);
	lv[S]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int j=hd[u];j;j=e[j].r){
			int v=e[j].y;
			if(!e[j].w||lv[v]) continue;
			lv[v]=lv[u]+1;
			if(v==T) return true;
			q.push(v);
		}
	}
	return false;
}
ll dinic(int u,ll flw){
	if(u==T) return flw;
	ll avi=flw;
	for(int j=crt[u];j&&avi;j=e[j].r){
		crt[u]=j;
		int v=e[j].y;
		if(!e[j].w||lv[v]!=lv[u]+1) continue;
		ll ret=dinic(v,min(e[j].w,avi));
		if(!ret) lv[v]=0;
		avi-=ret;
		e[j].w-=ret;
		e[j^1].w+=ret;
	}
	return flw-avi;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>N>>M; S=N+M+1; T=S+1;
	ll ans=0;
	for(int i=1,w;i<=N;++i) cin>>w, cnct(i,T,w);
	for(int i=1,x,y,w;i<=M;++i) cin>>x>>y>>w, cnct(S,N+i,w), cnct(N+i,x,inf), cnct(N+i,y,inf), ans+=w;
	while(bfs()) ans-=dinic(S,inf);
	cout<<ans<<'\n';
	return 0;
}
