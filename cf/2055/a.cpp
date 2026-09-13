#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a,b;
inline void _solv(){
	cin>>n>>a>>b;
	if((a-b)%2==0) printf("YES\n");
	else printf("NO\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
