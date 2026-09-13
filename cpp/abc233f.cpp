#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;

const int kn=1024;
int n,m,a[kn],c[kn]; // the num on pos i now, the num i's pos

class EDGE{ public: int y,w,r; } e[400044];
int h[kn], ct=1;
void cnct(int x,int y,int w){ e[++ct].y=y; e[ct].w=w; e[ct].r=h[x]; h[x]=ct; }
int fu[kn];
set<int> lst[kn];
inline int find(int x){ return (fu[x]==x)?x:fu[x]=find(fu[x]); }

int siz[kn], dfn[kn], dft=0;
pair<int,int> fa[kn];
void dfs(int cur,int pre){
	dfn[cur]=++dft;
	siz[cur]=1;
	for(int j=h[cur];j;j=e[j].r){
		int nxt=e[j].y;
		if(siz[nxt]) continue;
		fa[nxt]={cur,e[j].w};
		dfs(nxt,cur);
		siz[cur]+=siz[nxt];
	}
}
vector<int> ans;
void exch(int u,int v){ swap(c[a[u]],c[a[v]]); swap(a[u],a[v]); }
void build(int u,int v){
	stack<int> ansr,stk;
	for(; dfn[v]>dfn[u]||dfn[v]+siz[v]-1<dfn[u]; v=fa[v].x)
		stk.push(v), ansr.push(fa[v].y);
	while(u!=v){
		ans.emplace_back(fa[u].y);
		exch(u,fa[u].x);
		u=fa[u].x;
	}
	while(!stk.empty()){
		int nxt=stk.top(), w=ansr.top(); stk.pop(); ansr.pop();
		ans.emplace_back(w);
		exch(u,nxt);
		u=nxt;
	}
}
void solve(int cur){
	for(int j=h[cur];j;j=e[j].r){
		int nxt=e[j].y;
		if(fa[nxt].x!=cur) continue;
		solve(nxt);
	}
	build(c[cur],cur);
}

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n; for(int i=1;i<=n;++i) cin>>a[i], c[a[i]]=fu[i]=i;
	cin>>m; for(int i=1;i<=m;++i){
		int x,y; cin>>x>>y;
		cnct(x,y,i); cnct(y,x,i);
		if(find(x)!=find(y)) fu[find(y)]=find(x);
	}
	for(int i=1;i<=n;++i) lst[find(i)].insert(a[i]);
	for(int i=1;i<=n;++i) if(lst[find(i)].find(i) == lst[find(i)].end()){ cout<<"-1\n"; return 0; }

	for(int i=1;i<=n;++i) if(find(i)==i) dfs(i,0), solve(i);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();++i) cout<<ans[i]<<' ';
	return 0;
}
