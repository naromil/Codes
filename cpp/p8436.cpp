#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n,m;
vector<int> c[kn];
int dfn[kn],low[kn],dft=0,ins[kn];
stack<int> stk;
vector<vector<int>> ans;
void tarjan(int u,int b){
	dfn[u]=low[u]=++dft;
	ins[u]=true; stk.push(u);
	bool tob=false;
	for(auto v: c[u]){
		if(!dfn[v]){ tarjan(v,u); low[u]=min(low[u],low[v]); }
		else if(tob||v!=b) low[u]=min(low[u],dfn[v]);
		else tob=true;
	}
	if(dfn[u]==low[u]){
		vector<int> tmp;
		while(!stk.empty()){
			int cr=stk.top(); stk.pop();
			tmp.emplace_back(cr);
			if(cr==u) break;
		}
		ans.emplace_back(tmp);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y;i<=m;++i){
		cin>>x>>y;
		c[x].emplace_back(y);
		c[y].emplace_back(x);
	}
	for(int i=1;i<=n;++i) if(!dfn[i]){ tarjan(i,0); }
	printf("%ld\n",ans.size());
	for(auto u: ans){
		printf("%ld ",u.size());
		for(auto v: u) printf("%d ",v);
		printf("\n");
	}
	return 0;
}
