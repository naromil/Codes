#include<bits/stdc++.h>
#define emp push_back
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
using namespace std;
using ll=long long;
const int kn=5e3+53,km=2e5+25;
int n,m,k;
pii te1[km],te2[km];
class EDGE{
	public:
	int x,y,w,i;
	bool op=false;
	bool operator < (const EDGE &v) const{ return w<v.w; }
};
vector<EDGE> e,c[kn];
int fu[kn];
int find(int x){ return (fu[x]==x?x:fu[x]=find(fu[x])); }
void kruskal(){
	sort(e.begin(),e.end());
	for(auto u: e) if(find(u.x)!=find(u.y)){
		fu[find(u.y)]=find(u.x);
		c[te1[u.i].x][te1[u.i].y].op=c[te2[u.i].x][te2[u.i].y].op=true;
	}
}
int maxd[kn],posd[kn];
void dfs(int u,int p){
	for(auto v: c[u]){
		if(v.y==p||!v.op) continue;
		if(v.w>=maxd[u]) maxd[v.y]=v.w, posd[v.y]=v.i;
		else maxd[v.y]=maxd[u], posd[v.y]=posd[u];
		dfs(v.y,u);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fu[i]=i;
	for(int i=1,x,y,w;i<=m;++i){
		cin>>x>>y>>w;
		e.emp({x,y,w,i});
		c[x].emp({x,y,w,i});
		c[y].emp({y,x,w,i});
		te1[i]=mp(x,c[x].size()-1);
		te2[i]=mp(y,c[y].size()-1);
	}
	kruskal();
	vector<int> ls;
	int sum=0;
	for(int j=0;j<c[1].size();++j){
		if(c[1][j].op) ++sum;
		else ls.emp(j);
	}
	if(sum<k) for(int cs=sum+1;cs<=k;++cs){
		dfs(1,0);
		int g=-1;
		for(auto u: ls)
			if(g==-1||c[1][u].w-maxd[c[1][u].y]<=c[1][g].w-maxd[c[1][g].y]) g=u;
		if(g==-1) return puts("-1\n"), 0;
		c[1][g].op=true;
		int ps=posd[c[1][g].y];
		c[te1[ps].x][te1[ps].y].op=c[te2[ps].x][te2[ps].y].op=true;
	}
	else if(sum>k){
	}
	return 0;
}
/*
4 5 2
1 2 1
2 3 1
3 4 1
1 3 3
1 4 2

3
1 5 2
*/
