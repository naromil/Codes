#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2048;
int n,pos[kn],dis[kn][kn],s1,s2,m1,m2;
bool vis[kn][kn];
vector<int> c1[kn],c2[kn];
class PRIO{
	public: int x,y,w;
	bool operator < (const PRIO &v) const { return w>v.w; }
};
priority_queue<PRIO> pq;
inline void bfs(){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[s1][s2]=0;
	pq.push({s1, s2, 0});
	while(!pq.empty()){
		int x=pq.top().x, y=pq.top().y; pq.pop();
		if(vis[x][y]) continue;
		vis[x][y]=true;
		for(auto v1: c1[x]){
			for(auto v2: c2[y]){
				if(dis[v1][v2]>dis[x][y]+abs(v1-v2)){
					dis[v1][v2]=dis[x][y]+abs(v1-v2);
					pq.push({v1, v2, dis[v1][v2]});
				}
			}
		}
	}
}
bool tmp[kn];
inline void _solv(){
	cin>>n>>s1>>s2;
	cin>>m1;
	for(int i=1,x,y;i<=m1;++i){
		cin>>x>>y;
		c1[x].emp(y);
		c1[y].emp(x);
	}
	cin>>m2;
	for(int i=1,x,y;i<=m2;++i){
		cin>>x>>y;
		c2[x].emp(y);
		c2[y].emp(x);
	}
	for(int u=1;u<=n;++u){
		for(auto v: c1[u]){ tmp[v]=1; }
		for(auto v: c2[u]){ if(tmp[v]) pos[u]=1; }
		for(auto v: c1[u]){ tmp[v]=0; }
	}
	bfs();
	int ans=0x3f3f3f3f;
	for(int u=1;u<=n;++u){
		if(pos[u]) ans=min(ans, dis[u][u]);
	}
	if(ans>1e9) printf("-1\n");
	else printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		pos[i]=0;
		c1[i].clear();
		c2[i].clear();
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
