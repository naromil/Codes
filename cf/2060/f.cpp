#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25, p=998244353;
ll M,f[kn][20];
int n,m;
inline void _solv(){
	cin>>M>>n;
	// clear
	m=min(M, 16ll);
	f[1][0]=1;
	for(int k=1;k<=m;++k){
		for(int i=2;i<=n;++i){
			for(auto j: fc[i]){
				f[i][k]=(f[i][k] + f[j][k-1])%p;
			}
		}
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
