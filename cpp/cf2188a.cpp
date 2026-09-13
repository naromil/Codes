#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
int n;

inline void _solv(){
	cin >> n;
	int x = (n+1>>1);
	for(int i=1; i<=n; ++i){
		printf("%d ", x);
		x += (i & 1) ? i : -i;
	}
	printf("\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) _solv();
	return 0;
}
