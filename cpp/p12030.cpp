#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn = 2e5 + 25, mod = 1e9 + 7;
int n, A, B;
ll m, a[kn];

inline bool chk(ll md){
	ll w = m * (A - B); // - +1
	for(int i=n-A+1; i<=n; ++i){
		if(a[i] + m < md) w -= m;
		else if(a[i] < md) w -= md - a[i];
	}
	return w >= 0;
}

bool flg[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m >> A >> B;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	ll lt = 0, rt = 2e9, at = 0;
	while(lt <= rt){
		ll md = (lt+rt)>>1;
		if(chk(md)) lt = md + 1, at = md;
		else rt = md - 1;
	}
	ll w = m * (A - B); // - +1
	for(int i=n-A+1; i<=n; ++i){
		if(a[i] + m <= at){
			w -= m;
			a[i] += m;
		}
		else if(a[i] < at){
			w -= at - a[i];
			a[i] = at;
			flg[i] = true;
		}
	}

	ll ans = 0;
	for(int i=1; i<=n; ++i){
		if(w && flg[i]) ++a[i], --w;
		ans = (ans + a[i] * a[i] % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
