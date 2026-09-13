#include<bits/stdc++.h>
#define emp emplace_back
#define mkp make_pair
using namespace std;
using ll=long long;
const int kn = 1e6 + 16;
int n, m;
string a, b;
set<pair<int,int>> st[2];

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m >> a >> b;
	a = " " + a; b = " " + b;
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		if(a[i] == b[i]) continue;
		int x = a[i] - 48;
		if(!st[x].empty()){
			auto it = st[x].lower_bound(mkp(i % m, 0));
			if(it == st[x].end()) it = st[x].begin();
			ans += (i - (*it).second - 1) / m + 1;
			st[x].erase(it);
		}
		else st[x^1].insert(mkp(i % m, i));
	}
	printf("%lld\n", ans);
	return 0;
}
