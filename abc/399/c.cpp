#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,ans=0,vis[kn];
class EDGE{ public: int y,r; }e[kn<<1];
int hd[kn],ct=1,del[kn<<1];
inline void addedge(int x,int y){ e[++ct].y=y; e[ct].r=hd[x]; hd[x]=ct; }
void dfs(int u,int b){
	vis[u]=1;
	for(int j=hd[u];j;j=e[j].r){
		int v=e[j].y;
		if(v==b||del[j]) continue;
		if(vis[v]) del[j]=del[j^1]=++ans;
		else dfs(v,u);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y;i<=m;++i){
		cin>>x>>y;
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]) dfs(i,0);
	}
	printf("%d\n",ans);
	return 0;
}
