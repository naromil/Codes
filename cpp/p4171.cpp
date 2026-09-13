#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=216;
int n,m;
vector<int> nbr[kn];
int dfn[kn],low[kn],scc[kn],sct=0,tot=0;
bool ins[kn];
stack<int> stk;
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
	int T; cin>>T;
	while(T--){
		cin>>n>>m;
		tot=sct=0;
		for(int i=1;i<=n;++i)
			nbr[i].clear(), dfn[i]=0;
		for(int i=1;i<=m;++i){
			char op1,ch1,op2,ch2;
			cin>>op1>>ch1>>op2>>ch2;
			int t1=(op1=='h'),t2=(op2=='h'),x=ch1-'0',y=ch2-'0';
			nbr[x+t1*n].emplace_back(y+(t2^1)*n);
			nbr[y+t2*n].emplace_back(x+(t1^1)*n);
		}
		for(int i=1;i<=(n<<1);++i) if(!dfn[i]) tarjan(i);
		bool ans=true;
		for(int i=1;i<=n;++i) if(scc[i]==scc[i+n]){ ans=false; break; }
		cout<<(ans?"GOOD":"BAD")<<'\n';
	}
	return 0;
}
