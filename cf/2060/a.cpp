#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline void _solv(){
	int a1,a2,a4,a5;
	cin>>a1>>a2>>a4>>a5;
	int a31=a1+a2, a32=a4-a2, a33=a5-a4;
	if(a31==a32&&a32==a33) printf("3\n");
	else if(a31==a32||a31==a33||a32==a33) printf("2\n");
	else printf("1\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
