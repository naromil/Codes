#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n;
ll m;
class Node{
	public: ll v, k;
	bool operator < (const Node &nx) const { return v > nx.v; }
};
class Nodelist{
	public: vector<Node> c;
	int i, k;
	inline void init(){
		i = 0;
		k = c.empty() ? 0 : c[0].k;
	}
	inline bool get(int num, ll &sum){
		while(i < c.size() && k < num){
			sum += c[i].v * k;
			num -= k;
			++i;
			k = (i < c.size()) ? c[i].k : 0;
		}
		if(i == c.size() && num) return false;
		else if(i == c.size()) return true;
		sum += c[i].v * num;
		k -= num;
		return true;
	}
	inline void cycget(vector<Node> &ve, int r){
		while(true){
			if(k > r){
				ve.emp(Node{c[i].v * r, k / r});
				k %= r;
			}
			else{
				ll sum = 0;
				if(!get(r, sum)) return; // why not use it?
				ve.emp(Node{sum, 1});
			}
		}
	}
}a1, a2, a3;

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		int w, v, k; cin >> w >> v >> k;
		if(w == 1) a1.c.emp(Node{v, k});
		if(w == 2) a2.c.emp(Node{v, k});
		if(w == 3) a3.c.emp(Node{v, k});
	}
	sort(a1.c.begin(), a1.c.end());
	sort(a2.c.begin(), a2.c.end());
	sort(a3.c.begin(), a3.c.end());

	ll ans = 0;
	for(int c1=0; c1<6; ++c1) for(int c2=0; c2<3; ++c2) for(int c3=0; c3<2; ++c3){
		ll W = m - c1 - 2 * c2 - 3 * c3, sum = 0;
		if(W < 0) continue;
		a1.init(); if(!a1.get(c1, sum)) continue;
		a2.init(); if(!a2.get(c2, sum)) continue;
		a3.init(); if(!a3.get(c3, sum)) continue;
		vector<Node> c;
		a1.cycget(c, 6);
		a2.cycget(c, 3);
		a3.cycget(c, 2);
		sort(c.begin(), c.end());
		for(auto cr: c){
			if(W >= 6 * cr.k){
				W -= 6 * cr.k;
				sum += cr.v * cr.k;
			}
			else{
				sum += cr.v * (W / 6);
				break;
			}
		}
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
