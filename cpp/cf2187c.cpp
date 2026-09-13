#include<bits/stdc++.h>
#define emp emplace_back
#define mkp make_pair
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m, cc[kn], dep[kn], siz[kn], fa[kn], dfn[kn], dft = 0, lca[kn], lca2[kn];
vector<int> c[kn], ln[kn];

void dfs(int u, int b){
	dep[u] = dep[b] + 1;
	fa[u] = b;
	dfn[u] = ++dft;
	ln[dep[u]].emp(u);
	siz[u] = 1;
	for(auto v: c[u]){
		if(v == b) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}

inline void _solv(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cc[i] = 0x3f3f3f3f;
		c[i].clear();
		ln[i].clear();
	}
	for(int i=1; i<=m; ++i){
		int x, y; cin >> x >> y;
		cc[n-x+1] = min(cc[n-x+1], n-y+1); // max -> min
	}
	for(int i=2; i<=n; ++i){
		if(cc[i] > 1e9) cc[i] = i - 1;
		c[i].emp(cc[i]);
		c[cc[i]].emp(i);
	}
	dfs(1, 0);

	ll ans = 0;
	for(int k=1; k<=n; ++k){
		if(ln[k].empty()) continue;
		vector<pair<int, ll>> vec;
		ll sum = 0; // <-
		for(int i=0; i<ln[k].size(); ++i){
			int u = ln[k][i];
			if(i > 0){
				lca[u] = (fa[ln[k][i-1]] == fa[u]) ? fa[u] : lca[fa[u]];
				if(lca[u]) while(dfn[lca[u]] > dfn[ln[k][i-1]] || dfn[ln[k][i-1]] > dfn[lca[u]] + siz[lca[u]] - 1) lca[u] = lca[lca[u]]; 
				ll res = 0;
				while(!vec.empty() && dep[vec.back().first] >= dep[lca[u]]){
					sum -= 1ll * vec.back().second * (dep[u] - dep[vec.back().first]); // <->
					res += vec.back().second;
					vec.pop_back();
				}
				sum += res * (dep[u] - dep[lca[u]]); // u <-> l
				vec.emp(mkp(lca[u], res));
			}
			ans += sum;
			vec.emp(mkp(u, siz[u]));
		}
		vec.clear();
		sum = 0; // ++
		for(int i=ln[k].size()-1; i>=0; --i){
			int u = ln[k][i];
			if(i < ln[k].size()-1){
				lca2[u] = (fa[ln[k][i+1]] == fa[u]) ? fa[u] : lca2[fa[u]];
				if(lca2[u]) while(dfn[lca2[u]] > dfn[ln[k][i+1]] || dfn[ln[k][i+1]] > dfn[lca2[u]] + siz[lca2[u]] - 1) lca2[u] = lca2[lca2[u]];
				ll res = 0;
				while(!vec.empty() && dep[vec.back().first] >= dep[lca2[u]]){
					sum -= 1ll * vec.back().second * (dep[u] - dep[vec.back().first]); // <->
					res += vec.back().second;
					vec.pop_back();
				}
				sum += res * (dep[u] - dep[lca2[u]]); // u <-> l
				vec.emp(mkp(lca2[u], res));
			}
			ans += sum;
			vec.emp(mkp(u, siz[u]));
		}
	}
	printf("%lld\n", ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) _solv();
	return 0;
}
