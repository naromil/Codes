#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n, a[kn], b[kn];

inline void _solv(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int ans = 0x3f3f3f3f;
	for(int i=1; i<=n; ++i){
		if(a[i] != b[i]){
			int l = min(a[i], b[i]), r = max(a[i], b[i]);
			ans = min(ans, max(max(r - l, min(l-b[1], r-b[1])), max(min(b[n]-l, b[n]-r), min(b[n]-l, r-b[1]))));
		}
	}
	printf("%d\n", (ans > 1e9) ? -1 : ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) _solv();
	return 0;
}
