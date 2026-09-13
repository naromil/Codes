#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
inline void _solv(){
	ll a,b;
	cin>>a>>b;
	if(b>1) printf("%lld\n",b-a);
	else printf("1\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
