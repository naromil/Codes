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

class NodeList{
	public:
	vector<Node> a;
	Node operator [] (const int &x){ return a[x]; }
	int i, k;
	inline void init(){
		i = 0;
		k = a.size() ? a[0].k : 0;
	}
	inline bool get(int num, ll &sum){
		while(i < a.size() && k <= num){
			sum += a[i].v * k;
			num -= k;
			++i;
			k = (i >= a.size()) ? 0 : a[i].k;
		}
		if(!num) return true; // ++
		else if(i >= a.size()) return false; // + else
		sum += a[i].v * num;
		k -= num;
		return true;
	}
	inline void cycget(vector<Node> &c, int r){
		while(true){
			if(k > r){
				c.emp(Node{a[i].v * r, k / r}); // (k/r) -> r
				k %= r;
			}
			else{
				ll sum = 0;
				if(!get(r, sum)) return;
				c.emp(Node{sum, 1});
			}
		}
	}
}a1, a2, a3;

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		int w, v, k; cin >> w >> v >> k;
		if(w == 1) a1.a.emp(Node{v, k});
		if(w == 2) a2.a.emp(Node{v, k});
		if(w == 3) a3.a.emp(Node{v, k});
	}
	sort(a1.a.begin(), a1.a.end());
	sort(a2.a.begin(), a2.a.end());
	sort(a3.a.begin(), a3.a.end());

	ll ans = 0;
	for(int c1=0; c1<6; ++c1) for(int c2=0; c2<3; ++c2) for(int c3=0; c3<2; ++c3){
		ll W = m - c1 - c2 * 2 - c3 * 3, sum = 0;
		if(W < 0) continue;
		a1.init();
		if(!a1.get(c1, sum)) continue;
		a2.init();
		if(!a2.get(c2, sum)) continue;
		a3.init();
		if(!a3.get(c3, sum)) continue;

		vector<Node> c;
		a1.cycget(c, 6);
		a2.cycget(c, 3);
		a3.cycget(c, 2);
		sort(c.begin(), c.end());
		for(auto cr: c){
			if(W >= cr.k * 6){
				W -= cr.k * 6;
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
