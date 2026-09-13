#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn = 24;
int n, sg[kn+5], vis[2005], a[kn+5];

inline void _solv(){
	cin >> n;
	int ans = 0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		ans ^= (a[i] & 1) * sg[n-i];
	}
	if(!ans){
		printf("-1 -1 -1\n0\n");
		return ;
	}
	int res = 0;
	bool flg = false;
	for(int i=1; i<=n; ++i){
		if(!a[i]) continue;
		for(int j=i+1; j<=n; ++j) for(int k=j; k<=n; ++k){
			if((ans ^ sg[n-i] ^ sg[n-j] ^ sg[n-k]) == 0){
				if(!flg){
					printf("%d %d %d\n", i-1, j-1, k-1);
					flg = true;
				}
				++res;
			}
		}
	}
	printf("%d\n", res);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	sg[0] = 0;
	for(int i=1; i<=kn; ++i){
		for(int j=0; j<i; ++j){
			for(int k=j; k<i; ++k) vis[sg[j]^sg[k]] = i;
		}
		sg[i] = 0;
		while(vis[sg[i]] == i) ++sg[i];
	}
	int T; cin >> T;
	while(T--) _solv();
	return 0;
}
