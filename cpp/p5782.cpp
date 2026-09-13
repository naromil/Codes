#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=16384;
int n,m;
vector<int> nbr[kn];
stack<int> stk;
bool ins[kn];
int scc[kn],dfn[kn],low[kn],tot=0,sct=0;
void tarjan(int cur){
	stk.push(cur); ins[cur]=true;
	low[cur]=dfn[cur]=++tot;
	for(auto nxt: nbr[cur]){
		if(!dfn[nxt]) tarjan(nxt), low[cur]=min(low[cur],low[nxt]);
		else if(ins[nxt]) low[cur]=min(low[cur],dfn[nxt]);
	}
	if(dfn[cur]==low[cur]){
		++sct;
		while(!stk.empty()){
			int nxt=stk.top(); stk.pop();
			ins[nxt]=false;
			scc[nxt]=sct;
			if(nxt==cur) break;
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int a,b; cin>>a>>b; ++a, ++b;
		nbr[a].emplace_back(b^1);
		nbr[b].emplace_back(a^1);
	}
	for(int i=2;i<=((n<<1)|1);++i) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=(n<<1);i+=2) if(scc[i+1]==scc[i+2]) return cout<<"NIE\n", 0;
	for(int i=1;i<=(n<<1);i+=2) cout<<i+(scc[i+1]>scc[i+2])<<'\n';
	return 0;
}
