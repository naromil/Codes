#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n;
ll f[kn][3]; //1:self, 0:son, 2:fa
vector<int> nbr[kn];
ll _min(ll x,ll y,ll z=0x3f3f3f3f){ return (x<=y?(x<=z?x:z):(y<=z?y:z)); }
void dfs(int cur,int pre){
	f[cur][1]=1;
	bool alr=false; int upg=0x3f3f3f3f;
	for(auto nxt: nbr[cur]){
		if(nxt==pre) continue;
		dfs(nxt,cur);
		f[cur][1]+=_min(f[nxt][1],f[nxt][0],f[nxt][2]);
		if(f[nxt][1]<=f[nxt][0]) f[cur][0]+=f[nxt][1], alr=true;
		else f[cur][0]+=f[nxt][0], upg=_min(upg,f[nxt][1]-f[nxt][0]);
		f[cur][2]+=f[nxt][0];
	}
	if(!alr) f[cur][0]+=upg;
}
int dep[kn];
ll ans=0;
void solve(int cur,int pre){
	dep[cur]=dep[pre]+1;
	if(dep[cur]==3){
		ll sum=0;
		for(auto nxt: nbr[cur]) if(nxt!=pre) sum+=_min(f[nxt][1],f[nxt][0]);
		ans+=_min(sum,f[cur][1]);
		return;
	}
	for(auto nxt: nbr[cur]){
		if(nxt==pre) continue;
		solve(nxt,cur);
	}
}
signed main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int x,y; scanf("%d %d",&x,&y);
		nbr[x].emplace_back(y); nbr[y].emplace_back(x);
	}
	dfs(1,0);
	solve(1,0);
	printf("%lld\n",ans);
	return 0;
}
