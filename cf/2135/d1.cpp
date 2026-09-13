#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1e5+15,m=100000;
int l,r;
inline void _solv(){
	printf("? %d ",m); for(int i=1;i<=m;++i){ printf("1 "); } printf("\n"); fflush(stdout);
	int x; cin>>x;
	if(x==1){ printf("! %d\n",m); fflush(stdout); return; }

	double tmpr=1.0*m/(x-1); r=tmpr; r-=(r==tmpr);
	l=ceil(1.0*m/x);
	if(l==r){ printf("! %d\n", l); fflush(stdout); return; }
//	printf("%d %d\n",l,r);

	printf("? %d ",(r-l)<<1); for(int i=l+1;i<=r;++i){ printf("%d %d ",l,i-l); } printf("\n"); fflush(stdout);
	int y; cin>>y;
	printf("! %d\n", r-y+r-l); fflush(stdout);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
