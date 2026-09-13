#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
inline void _solv(){
	cin>>n;
	int ans=(n/15+1)*3;
	if(n%15<2) ans-=2-n%15;
	printf("%d\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
