#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 2e5 + 25;
int n;

inline void _solv(){
	cin >> n;
	vector<int> a(1, -1);
	for(int i=1; i<=n; ++i){
		char ch; cin >> ch;
		if(ch == '1') a.emp(i);
	}
	a.emp(n + 2);
	int ans = a.size() - 2;
	for(int i=1; i<a.size(); ++i){
		ans += (a[i] - a[i-1] - 1) / 3;
	}
	printf("%d\n", ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) _solv();
	return 0;
}
