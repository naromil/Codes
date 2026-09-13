#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=64, p=1e9+7;
int n, m, N, f[2][kn][kn*kn*2];
inline void upd(int &x, ll y){ x = (x + y) % p; }
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	if(n == 1){
		cout << (m == 0) << '\n';
		return 0;
	}
	N = n * n;

	f[1][0][N-2] = f[1][1][N] = 1;
	for(int i=1,x=1; i<n; x=++i&1){
		for(int j=0; j<=i+1; ++j)
			for(int k=0; k<=(i+1)*(i+1)+N; ++k)
				f[x^1][j][k] = 0;
		for(int j=0; j<=i; ++j){
			for(int k=0; k<=i*i+N; ++k){
				ll v = f[x][j][k];
				if(k - 2 * (i+1) >= 0) upd(f[x^1][j][k-2*(i+1)], v);
				upd(f[x^1][j+1][k], v * (2 * (i - j) + 1) % p);
				upd(f[x^1][j+2][k+2*(i+1)], v * (i - j) % p * (i - j) % p);
			}
		}
	}

	printf("%d\n", f[n&1][n][m+N]);
	return 0;
}
