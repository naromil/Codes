#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n,m;
vector<int> c[kn];
int dfn[kn],low[kn],dft=0,ins[kn],cut[kn];
stack<int> stk;
void tarjan(int u,int o){
	dfn[u]=low[u]=++dft;
	ins[u]=true; stk.push(u);
	int num=0;
	for(auto v: c[u]){
		if(!dfn[v]){
			++num;
			tarjan(v,o);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){ cut[u]=1; }
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(u==o&&num<2) cut[u]=0;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y;i<=m;++i){
		cin>>x>>y;
		c[x].emplace_back(y);
		c[y].emplace_back(x);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]) tarjan(i,i);
	}
	vector<int> ans;
	for(int i=1;i<=n;++i){
		if(cut[i]) ans.emplace_back(i);
	}
	printf("%ld\n",ans.size());
	for(auto u: ans){
		printf("%d ",u);
	}
	return 0;
}
