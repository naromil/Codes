#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=108;
int n,dx=0,dy=0;
pii a[kn];
vector<int> vec1,vec2;
inline int _mv(char ch,int k){
	printf("? %c %lld\n",ch,k);
	fflush(stdout);
	if(ch=='U') dy+=k;
	else if(ch=='D') dy-=k;
	else if(ch=='L') dx-=k;
	else if(ch=='R') dx+=k;
	ll res; cin>>res;
	return res;
}
const int d=1e9;
inline void _solv(){
	cin>>n;
	dx=dy=0;
	vec1.clear();
	vec2.clear();
	int maxi1=-2e9,maxi2=-2e9;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
		maxi1=max(maxi1,a[i].x+a[i].y);
		maxi2=max(maxi2,a[i].y-a[i].x);
	}
//	for(int i=1;i<=n;++i){
//		if(a[i].x+a[i].y==maxi1) vec1.emp(i);
//		if(a[i].y-a[i].x==maxi2) vec2.emp(i);
//	}
	_mv('U',d);
	_mv('U',d);
	_mv('R',d);
	int res1=_mv('R',d);
	_mv('L',d);
	_mv('L',d);
	_mv('L',d);
	int res2=_mv('L',d);
	int Y=(maxi1+res1+maxi2+res2-4*d)>>1;
	int X=(maxi1+res1-maxi2-res2+4*d)>>1;
	printf("! %lld %lld\n",X-2*d,Y-2*d);
	fflush(stdout);
}
// X1+Y1=maxi1+res1
// Y1-X1+4d=maxi2+res2
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
