#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 36;
ll x, y, ans, P, Q;

inline void upd(ll p, ll q){
	if(abs(x-p) + abs(y-q) <= ans){
		ans = abs(x-p) + abs(y-q);
		P = p;
		Q = q;
	}
}

inline void _solv(){
	cin >> x >> y;
	ll p = 0, q = 0;
	ans = 0x3f3f3f3f3f3f3f3f;
	for(int k=30; k>=0; --k){
		int bs = 1 << k;
		if(!(x>>k&1) && !(y>>k&1)){
			upd(p|bs, q|(y&bs-1));
			upd(p|(x&bs-1), q|bs);
		}
		else if((x>>k&1) && (y>>k&1)){
			upd(p|bs-1, q|bs);
			break;
		}
		else{
			p |= (x&1<<k);
			q |= (y&1<<k);
		}
	}
	if(!(p & q)) upd(p, q);
	printf("%lld %lld\n", P, Q);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) _solv();
	return 0;
}
