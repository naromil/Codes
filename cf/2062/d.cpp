#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,L[kn],R[kn],a[kn];
ll ans=0;
vector<int> c[kn];
void dfs(int u,int b){
	a[u]=L[u];
	for(auto v: c[u]){
		if(v==b) continue;
		dfs(v,u);
		a[u]=max(a[u],a[v]);
	}
	a[u]=min(a[u],R[u]);
	for(auto v: c[u]){
		if(v==b) continue;
		if(a[v]>a[u]) ans+=a[v]-a[u];
	}
}
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>L[i]>>R[i];
	}
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
	}
	dfs(1,0);
	printf("%lld\n",a[1]+ans);
	ans=0;
	for(int i=1;i<=n;++i) c[i].clear();
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
