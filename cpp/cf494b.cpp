#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25, mod = 1e9 + 7;
int n, nxt[kn], d[kn];
string a, b;

inline void get_nxt(){
	nxt[1] = 0;
	int i = 2, j = 1;
	while(i < b.size()){
		if(b[i] == b[j]) nxt[i++] = j++;
		else if(j > 1) j = nxt[j-1] + 1;
		else nxt[i++] = 0;
	}
}
inline void kmp(){
	int i = 1, j = 1;
	while(i <= n){
		if(a[i] == b[j]) ++i, ++j;
		else if(j > 1) j = nxt[j-1] + 1;
		else ++i;
		if(j == b.size()) d[i-1] = i - j + 1, j = nxt[j-1] + 1;
	}
}

ll f[kn], s1[kn], s2[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> a >> b;
	n = a.size(); a = " " + a; b = " " + b;
	get_nxt();
	kmp();
	for(int i=1; i<=n; ++i){
		d[i] = d[i] ? d[i] : d[i-1];
	}

	ll ans = 0;
	f[0] = s1[0] = 1;
	for(int i=1; i<=n; ++i){
		if(d[i]) f[i] = (d[i] * s1[d[i]-1] - s2[d[i]-1] + mod) % mod; // + +mod
		s1[i] = (s1[i-1] + f[i]) % mod;
		s2[i] = (s2[i-1] + f[i] * i) % mod;
		ans = (ans + f[i]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
