#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 5e3 + 53;
int n, s[kn][kn], f[kn][kn];
char a[kn][kn];
inline int calc(int i, int j, int k, int op){
	int res = s[i][k] - s[i][j-1] - s[i-1][k] + s[i-1][j-1];
	return op ? res : k - j + 1 - res;
}

signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[i][j];
			s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + (a[i][j] == '#');
		}
	}

	memset(f, 0x3f, sizeof f);
	f[0][n+1] = 0;
	for(int i=1; i<=n; ++i){
		int mn = 0x3f3f3f3f;
		for(int j=n+1; j>=1; --j){
			mn = min(mn, f[i-1][j]);
			f[i][j] = min(f[i][j], mn + calc(i, 1, j-1, 1) + calc(i, j, n, 0));
		}
	}
	
	int ans = 0x3f3f3f3f;
	for(int j=n+1; j>=1; --j) ans = min(ans, f[n][j]);
	printf("%d\n", ans);
	return 0;
}
