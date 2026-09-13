#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;

inline ll _solv(ll n, ll m){
	stack<int> stk;
	for(int i=1; 1ll * i * i <= m; ++i){
		if(m % i == 0) stk.push(i);
	}
	for(int i=sqrt(n); i>=1; --i){
		if(n % i) continue;
		while(stk.top() > i) stk.pop();
		if(m / stk.top() <= n / i) return (i + n/i) << 1;
	}
	return 0x3f3f3f3f3f3f3f3f;
}
ll a, b;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	printf("%lld\n", min(_solv(a + b, a), _solv(a + b, b)));
	return 0;
}