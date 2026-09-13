#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a,b,c,d;
inline bool _solv(){
	cin>>a>>b>>c>>d;
	c-=a;
	d-=b;
	return max(a,b)<=min(a,b)*2+2 && max(c,d)<=min(c,d)*2+2;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) printf(_solv() ? "YES\n" : "NO\n");
	return 0;
}
