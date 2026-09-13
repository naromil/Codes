#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int kn=55;
int n,a[kn];
inline void _solv(){
	memset(a,0,sizeof a);
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ans+=a[i];
	}
	for(int k=1;k<n;++k){
		for(int i=n;i>k;--i) a[i]-=a[i-1];
		a[k]=0;
		ll cur=0;
		for(int i=1;i<=n;++i) cur+=a[i];
//		printf("FK: %lld\n",cur);
		if(cur<0) cur=-cur;
		ans=max(ans, cur);
	}
	printf("%lld\n",ans);
}
signed main(){
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
