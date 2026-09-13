#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
class EDGE{ public: int y,w,r; }e[kn];
int hd[kn],ct=1;
inline void addedge(int x,int y,int w){ e[++ct].y=y; e[ct].w=w; e[ct].r=hd[x]; hd[x]=ct; }
int n,m,a[kn],vis[kn],A=0,B=0,vit=0;
bool dfs(int u,int w,int k){
	vis[u]=vit;
	if(w){ a[u]|=1<<k; ++A; }
	else{ a[u]&=~(1<<k); ++B; }
	for(int j=hd[u];j;j=e[j].r){
		if(vis[e[j].y]==vit){
			if(((a[e[j].y]>>k&1)^(a[u]>>k&1)) != (e[j].w>>k&1)) return false;
			continue;
		}
		if(!dfs(e[j].y, w^(e[j].w>>k&1), k)) return false;
	}
	return true;
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y,w;i<=m;++i){
		cin>>x>>y>>w;
		addedge(x,y,w);
		addedge(y,x,w);
	}
	for(int k=0;k<32;++k){
		for(int i=1;i<=n;++i) vis[i]=0;
		for(int i=1;i<=n;++i){
			if(vis[i]) continue;
			A=0; B=0; ++vit;
			if(!dfs(i,0,k)){ printf("-1\n"); return 0; }
			if(A>B){ ++vit; dfs(i,1,k); }
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	printf("\n");
    return 0;
}
