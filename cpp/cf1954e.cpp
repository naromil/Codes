#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn], rp[kn], b[kn], c[kn], mx = 0;

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		rp[i] = i;
		b[i] = 1;
		mx = max(mx, a[i]);
	}
	sort(rp + 1, rp + n + 1, [](int x, int y){ return a[x] < a[y]; });

	c[0] = 1;
	for(int I=1; I<=n; ++I){
		int i = rp[I];
		b[i] = 0;
		if(b[i-1] == 1 && b[i+1] == 1) c[a[i]] += 1;
		else if(b[i-1] == 0 && b[i+1] == 0) c[a[i]] += -1;
		
	}
	for(int i=1; i<=mx; ++i){
		c[i] += c[i-1];
	}

	for(int k=1; k<=mx; ++k){
		ll sum = 0;
		for(int i=0; i<=mx; i+=k){
			sum += c[i];
		}
		printf("%lld ", sum);
	}
	printf("\n");
	return 0;
}
