#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=222,inf=0x3f3f3f3f;
bool nopr[200025];
void get_pr(int n){
	vector<int> prs;
	nopr[1]=true;
	for(int i=2;i<=n;++i){
		if(!nopr[i]) prs.emp(i);
		for(auto p: prs){
			if(i*p>n) break;
			nopr[i*p]=true;
			if(i%p==0) break;
		}
	}
}
int n,m,S,T,P[kn],C[kn],L[kn],col[kn],hd[kn],ct=1;
class EDGE{ public: int y,w,r; }e[kn*kn<<1];
void cnct(int x,int y,int w){
	e[++ct].y=y; e[ct].w=w; e[ct].r=hd[x]; hd[x]=ct;
	e[++ct].y=x; e[ct].w=w; e[ct].r=hd[y]; hd[y]=ct;
}
bool del[kn];
void dfs(int u){
	if(!col[u]) cnct(S,u,P[u]);
	else cnct(u,T,P[u]);
	for(int j=hd[u];j;j=e[j].r){
		int v=e[j].y;
		if(v>n) continue;
		if(!~col[v]) col[v]=col[u]^1, dfs(v);
		e[j^col[u]^1].w=0;
	}
}
int lv[kn],crt[kn];
bool bfs(){
	memset(lv,0,sizeof lv);
	for(int i=1;i<=T;++i) crt[i]=hd[i];
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
int dinic(int u,int flw){
	if(u==T) return flw;
	int avi=flw;
	for(int j=crt[u];j&&avi;j=e[j].r){
		int v=e[j].y;
		crt[u]=j;
		if(!e[j].w||lv[v]!=lv[u]+1) continue;
		int ret=dinic(v,min(avi,e[j].w));
		if(!ret) lv[v]=0;
		avi-=ret;
		e[j].w-=ret;
		e[j^1].w+=ret;
	}
	return flw-avi;
}
bool check(int md){
	int max1=0,ans=0; ct=1;
	memset(hd,0,sizeof hd);
	memset(col,-1,sizeof col);
	for(int i=1;i<=n;++i) del[i]=(md<L[i]);
	for(int i=1;i<=n;++i) if(!del[i]&&C[i]==1&&P[i]>P[max1]) max1=i;
	for(int i=1;i<=n;++i) if(!del[i]&&C[i]==1&&i!=max1) del[i]=true;
	for(int i=1;i<=n;++i) if(!del[i]) ans+=P[i];
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(!del[i]&&!del[j]&&i<j&&!nopr[C[i]+C[j]]) cnct(i,j,inf);
	for(int i=1;i<=n;++i) if(!~col[i]) col[i]=0, dfs(i);
	while(bfs()) ans-=dinic(S,inf);
//	cerr<<md<<' '<<ans<<'\n';
	return ans>=m;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	get_pr(200000);
	cin>>n>>m;
	S=n+1; T=n+2;
	for(int i=1;i<=n;++i) cin>>P[i]>>C[i]>>L[i];
	int lm=1,rm=n,am=-1;
	while(lm<=rm){
		int md=lm+rm>>1;
		 if(check(md)) rm=md-1, am=md;
		 else lm=md+1;
	}
	cout<<am<<'\n';
	return 0;
}
