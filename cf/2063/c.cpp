#include<bits/stdc++.h>
#define int long long
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,in[kn];
vector<int> c[kn];
multiset<int> st;
inline void upd(int u,int w){
	st.erase(st.find(in[u]));
	in[u]+=w;
	st.insert(in[u]);
}
inline void _solv(){
	cin>>n;
	st.clear();
	for(int i=1;i<=n;++i){
		in[i]=0;
		c[i].clear();
	}
	for(int i=1,x,y;i<n;++i){
		cin>>x>>y;
		c[x].emp(y);
		c[y].emp(x);
		++in[x];
		++in[y];
	}
	for(int i=1;i<=n;++i) st.insert(in[i]);
	ll ans=0,cur=0;
	for(int k=1;k<=n;++k){
		cur=in[k];
		for(auto v: c[k]){ upd(v,-1); }
		upd(k, -in[k]);
		ans=max(ans, cur+(*st.rbegin())-1);
		for(auto v: c[k]){ upd(v,1); }
		upd(k, cur);
	}
	printf("%lld\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
