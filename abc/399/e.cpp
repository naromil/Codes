#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=32;
int n,dfn[kn],low[kn],ins[kn],scc[kn],siz[kn],dft=0,ans=0,gout[kn];
stack<int> stk;
string a,b;
vector<int> ps[kn],c[kn];
bool spa=false,anylop=false;
void tarjan(int u){
	dfn[u]=low[u]=++dft;
	ins[u]=true;
	stk.push(u);
	for(auto v: c[u]){
		if(!dfn[v]){ tarjan(v); low[u]=min(low[u],low[v]); }
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		while(!stk.empty()){
			int v=stk.top(); stk.pop();
			scc[v]=u;
			ins[v]=false;
			++siz[u];
			if(v==u) break;
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>a>>b; a=" "+a; b=" "+b;
	for(int i=1;i<=n;++i){
		ps[a[i]-'a'+1].emp(i);
	}
	for(int x=1;x<=26;++x){
		if(ps[x].empty()){ spa=true; continue; }
		int y=0;
		for(auto i: ps[x]){
			if(!y) y=b[i]-'a'+1;
			else if(y!=b[i]-'a'+1){ printf("-1\n"); return 0; }
		}
		if(y==x) continue;
		c[x].emplace_back(y);
//		printf("%c %c\n",x+'a'-1,y+'a'-1);
		++ans;
	}
	for(int i=1;i<=26;++i) if(!dfn[i]) tarjan(i);
	for(int u=1;u<=26;++u) for(auto v: c[u]){
		if(scc[v]!=scc[u]) gout[scc[v]]=true;
	}
	for(int u=1;u<=26;++u) if(siz[u]>1&&!gout[u]){
		anylop=true;
		++ans;
	}
	for(int u=1;u<=26;++u){
		bool flg=false;
		for(auto v: c[u]){ if(scc[v]!=scc[u]) flg=true; }
		if(flg==true) spa=true;
	}
	if(anylop&&!spa) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
