#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kN=1e4+11,inf=0x3f3f3f3f;
int n,m,k;
class EDGE{
	public: int y,w,r;
}e[kN<<1];
int ct=1,h[kN];
inline void cnct(int x,int y,int w){
	e[++ct].y=y;
	e[ct].w=w;
	e[ct].r=h[x];
	h[x]=ct;
}
inline void prep(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,w; scanf("%d %d %d",&x,&y,&w);
		cnct(x,y,w);
	}
}
int dis[kN][2];
bool vis[kN];
inline void bfs(int rot){
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(rot);
	dis[rot][0]=0;
	vis[rot]=true;
	while(!q.empty()){
		int cur=q.front(); q.pop();
		vis[cur]=false;
		for(int j=h[cur];j;j=e[j].r){
			int nxt=e[j].y,w=e[j].w;
			int ds=dis[cur][0]+1;
			if(ds>=w&&ds<dis[nxt][ds&1]){
				dis[nxt][ds&1]=ds;
				if(!vis[nxt]) q.push(nxt);
				vis[nxt]=true;
			}
			ds=dis[cur][1]+1;
			if(ds>=w&&ds<dis[nxt][ds&1]){
				dis[nxt][ds&1]=ds;
				if(!vis[nxt]) q.push(nxt);
				vis[nxt]=true;
			}
		}
	}
}
inline int calc(int ds){
	int suf=(ds%k==0) ? ds : ds-ds%k+k;
	if(ds%2==suf%2) return suf;
	else if(k%2) return suf+k;
	else return -1;
}
signed main(){
	prep();
	bfs(1);
	int ans=calc(dis[n][0]), ret=calc(dis[n][1]);
	if(ans==-1||ans>ret) printf("%d\n",ret);
	else printf("%d\n",ans);
	return 0;
}
