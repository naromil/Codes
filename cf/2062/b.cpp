#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n,a[kn];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		if(a[i]<=(max(i-1,n-i)<<1)){ printf("NO\n"); return; }
	}
	printf("YES\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
