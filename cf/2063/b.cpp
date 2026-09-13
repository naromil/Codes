#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,L,R,a[kn];
ll ansl=0,ansr=0;
inline void _solv(){
	cin>>n>>L>>R;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ansl=ansr=0;
	for(int i=L;i<=R;++i){
		ansl+=a[i];
		ansr+=a[i];
	}
	sort(a+1,a+L);
	sort(a+L,a+R+1);
	sort(a+R+1,a+n+1);
	for(int i=1,j=R;i<L;++i,--j){
		if(j>=L&&a[i]<a[j]) ansl=ansl-a[j]+a[i];
		else break;
	}
	for(int i=R+1,j=R;i<=n;++i,--j){
		if(j>=L&&a[i]<a[j]) ansr=ansr-a[j]+a[i];
		else break;
	}
	printf("%lld\n",min(ansl,ansr));
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
