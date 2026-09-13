#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 3e5 + 35;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, q;
ll a[kn];
class SGT{
	public: ll t[kn<<2], v[kn<<2], mn[kn<<2];
	inline void pu(int u){
		int ls = u<<1, rs = u<<1|1;
		t[u] = t[ls] + t[rs];
		mn[u] = min(mn[ls], mn[rs]);
	}
	inline void pd(int u){
		if(!v[u]) return;
		int ls = u<<1, rs = u<<1|1;
		mn[ls] += v[u];
		mn[rs] += v[u];
		v[ls] += v[u];
		v[rs] += v[u];
		v[u] = 0;
	}
	void bud(int u, int l, int r){
		if(l == r){
			t[u] = 1;
			v[u] = 0;
			mn[u] = a[l];
			return;
		}
		int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
		bud(ls, l, md);
		bud(rs, md+1, r);
		pu(u);
	}
	ll upd(int u, int l, int r, int x, int y, ll w){
		if(y < l || r < x) return 0;
		int md = (l+r)>>1, ls = u<<1, rs = u<<1|1;
		ll res = 0;
		if(x <= l && r <= y && mn[u] > w){
			mn[u] -= w;
			v[u] -= w;
			return w * t[u];
		}
		else if(l == r){
			res = mn[u];
			t[u] = 0;
			mn[u] = inf;
			return res;
		}
		pd(u);
		res = upd(ls, l, md, x, y, w) + upd(rs, md+1, r, x, y, w);
		pu(u);
		return res;
	}
}G;

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	G.bud(1, 1, n);
	cin >> q;
	for(int i=1; i<=q; ++i){
		int x, y; ll w; cin >> x >> y >> w;
		ll res = G.upd(1, 1, n, x, y, w);
		printf("%lld\n", res);
	}
	return 0;
}
