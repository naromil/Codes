#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline void _solv(){
	int x,y;
	cin>>x>>y;
	while(x>y) x-=9;
	if(x+1==y) printf("Yes\n");
	else printf("No\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
