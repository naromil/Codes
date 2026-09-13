#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 1e6 + 16;
int n, a[kn], v1[kn], v2[kn];
ll c[kn], sum[kn];
pair<int,int> fs[kn];

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	srand(time(0));
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=1; i<=n; ++i) cin >> v1[i];
	for(int i=1; i<=n; ++i) cin >> v2[i];
	for(int i=1; i<=n; ++i){
		if(!fs[a[i]].first){
			fs[a[i]] = make_pair(i, rand() % 1234567);
			// --
		}
		else{
			c[i] = -fs[a[i]].second;
			c[fs[a[i]].first] += fs[a[i]].second;
		}
	}

	ll ans = 0x3f3f3f3f3f3f3f3f;
	unordered_map<ll, int> mp;
	mp[0] = 0;
	for(int i=1; i<=n; ++i){
		sum[i] = sum[i-1] + c[i];
		if(mp.count(sum[i])){
			int j = mp[sum[i]] + 1;
			ll sum = 0;
			for(int k=j; k<=i; ++k){
				sum += v1[k] * v2[k-j+1];
			}
			ans = min(ans, sum); // max -> min
		}
		mp[sum[i]] = i;
	}
	printf("%lld\n", ans);
	return 0;
}
