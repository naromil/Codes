#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn];
map<ll, int> mp1;
map<ll, array<int, 6>> mp;

inline void _solv(int cs){
	printf("Case #%d: ", cs);
	cin >> n;
	mp.clear();
	mp1.clear();
	for(int i=1; i<=n; ++i) cin >> a[i];

	if(n == 20){
		for(int k=1; k<(1<<n); ++k){
			ll sum = 0;
			for(int i=1; i<=n; ++i){
				if(k>>i-1 & 1) sum += a[i];
			}
			if(mp1.count(sum)){
				printf("Possible\n");
				for(int i=1; i<=n; ++i){
					if(k>>i-1 & 1) printf("%d ", a[i]);
				}
				printf("\n");
				int kk = mp1[sum];
				for(int i=1; i<=n; ++i){
					if(kk>>i-1 & 1) printf("%d ", a[i]);
				}
				printf("\n");
				return;
			}
			mp1[sum] = k;
		}
		printf("Impossible\n");
	}

	else{
		int i;
		ll sum = 0;
		array<int, 6> cr;
		while(true){
			sum = 0;
			for(i=0; i<6; ++i){
				cr[i] = a[rand() % n + 1];
			}
			sort(cr.begin(), cr.end());
			for(i=0; i<6; ++i){
				if(i && cr[i] == cr[i-1]){ sum = -1; break; }
				sum += cr[i];
			}
			if(sum == -1) continue;
			if(mp.count(sum) && mp[sum] != cr){
				printf("Possible\n");
				printf("%d %d %d %d %d %d\n", cr[0], cr[1], cr[2], cr[3], cr[4], cr[5]);
				array<int, 6> pr = mp[sum];
				printf("%d %d %d %d %d %d\n", pr[0], pr[1], pr[2], pr[3], pr[4], pr[5]);
				return;
			}
			mp[sum] = cr;
		}
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	srand(time(0));
	int T; cin >> T;
	for(int ii=1; ii<=T; ++ii) _solv(ii);
	return 0;
}
