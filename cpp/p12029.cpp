#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25, inf = 0x3f3f3f3f;
int n, q, a[kn], in[kn];
set<int> st[kn], ms;

inline void upd(int x, int w){
	st[in[x]].erase(x);
	if(st[in[x]].size() == 0) ms.erase(in[x]);
	in[x] += w;
	if(!in[x]) return;
	st[in[x]].insert(x);
	if(st[in[x]].size() == 1) ms.insert(in[x]);
}

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		upd(a[i], 1);
	}

	for(int cs=1; cs<=q; ++cs){
		int x, y; cin >> x >> y;
		upd(a[x], -1);
		a[x] = y;
		upd(a[x], 1);

		int mx = -inf, ans = 0;
		auto j = ms.rbegin();
		for(auto i: ms){
			while(j != ms.rend() && i + *j >= *ms.rbegin()){ // note that two different second-pointer models are different: j and next(j)
				mx = max(mx, *st[*j].rbegin());
				j = next(j);
			}
			ans = max(ans, mx - *st[i].begin());
		}
		printf("%d\n", ans);
	}
	return 0;
}
