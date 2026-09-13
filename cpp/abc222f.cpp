#include<bits/stdc++.h>
#define x first
#define y second
#define pb emplace_back
#define mp make_pair
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],fa[kn];
vector<pair<int,int>> nbr[kn];
ll f[kn];
void init(int cur,int pre){
	fa[cur]=pre;
	f[cur]=a[cur];
	for(auto ntr: nbr[cur]){
		if(ntr.x==pre) continue;
		init(ntr.x,cur);
		f[cur]=max(f[cur],f[ntr.x]+ntr.y);
	}
}
ll dp[kn];
void dfs(int cur,int pre){
	multiset<ll> mst; mst.insert(-1ll);
	for(auto ntr: nbr[cur]) if(ntr.x!=pre) mst.insert(f[ntr.x]+ntr.y);
	for(auto ntr: nbr[cur]){
		if(ntr.x==pre) continue;
		mst.erase(mst.find(f[ntr.x]+ntr.y));
		dp[ntr.x]=max(max(1ll*a[cur],dp[cur]), *mst.rbegin()) + ntr.y;
		mst.insert(f[ntr.x]+ntr.y);
		dfs(ntr.x,cur);
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;i++){
		int x,y,w; cin>>x>>y>>w;
		nbr[x].pb(mp(y,w)), nbr[y].pb(mp(x,w));
	}
	for(int i=1;i<=n;i++) cin>>a[i];

	init(1,0);
	dfs(1,0);
	for(int i=1;i<=n;i++){
		ll ans=dp[i];
		for(auto ntr: nbr[i]) if(ntr.x!=fa[i]) ans=max(ans,f[ntr.x]+ntr.y);
		cout<<ans<<'\n';
	}
	return 0;
}
