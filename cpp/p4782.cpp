#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e6+26;
int n,m;
vector<int> nbr[kn];
void prep(){
	scanf("%d %d",&n,&m);
	for(int k=1;k<=m;++k){
		int i,a,j,b; scanf("%d %d %d %d",&i,&a,&j,&b);
		nbr[i+a*n].emplace_back(j+(b^1)*n);
		nbr[j+b*n].emplace_back(i+(a^1)*n);
	}
}
stack<int> stk;
int dfn[kn],low[kn],scc[kn],tot=0,sct=0;
bool ins[kn];
void tarjan(int cur){
	stk.push(cur);
	low[cur]=dfn[cur]=++tot;
	ins[cur]=true;
	for(auto nxt: nbr[cur]){
		if(!dfn[nxt]) tarjan(nxt), low[cur]=min(low[cur],low[nxt]);
		else if(ins[nxt]) low[cur]=min(low[cur],dfn[nxt]);
	}
	if(dfn[cur]==low[cur]){
		++sct;
		while(!stk.empty()){
			int nxt=stk.top(); stk.pop();
			scc[nxt]=sct;
			ins[nxt]=false;
			if(nxt==cur) break;
		}
	}
}
int ans[kn];
signed main(){
	prep();
	for(int i=1;i<=(n<<1);++i) if(!dfn[i]) tarjan(i); //////
	for(int i=1;i<=n;++i) if(scc[i]==scc[i+n]) return printf("IMPOSSIBLE\n"), 0;
	printf("POSSIBLE\n");
	for(int i=1;i<=n;++i) ans[i]=(scc[i]<scc[i+n]); //////
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}
