#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m;
ll a[kn];
inline void _solv(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]=a[i]+1ll*(a[i]%(m+1))*m;
	}
	for(int i=1;i<=n;++i){
		printf("%lld ",a[i]);
	}
	printf("\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
