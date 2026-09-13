#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, m, a[kn], rp[kn];
ll s[kn];
set<int> st;

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
		rp[i] = i;
	}
	sort(rp + 1, rp + n + 1, [](int x, int y){ return a[x] > a[y]; });

	ll ans = 0x3f3f3f3f3f3f3f3f;
	st.insert(0);
	st.insert(n + 1);
	for(int ii=1; ii<=n; ++ii){
		int i = rp[ii], cnt = 1;
		ll sum = a[i];
		st.insert(a[i]);
		auto lt = st.find(a[i]), rt = lt;
		while(*prev(lt) != 0 && cnt < m){
			lt = prev(lt);
			sum += a[*lt];
		}
		while(*next(rt) != n + 1 && cnt < m){
			rt = next(rt);
			sum += a[*rt];
		}
		if(cnt < m) continue;
		while(*rt != n + 1){
			ans = max(ans, s[*next(rt)-1] - s[*prev(lt)] - sum);
			sum = sum - a[*lt] + a[*next(rt)];
			lt = next(lt);
			rt = next(rt);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
