#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn];
ll f[kn],sum[kn],mini;
inline void _solv(){
	cin>>n; a[n+1]=0;
	for(int i=n;i>=1;--i){ cin>>a[i]; }
	for(int i=1;i<=n;++i){ sum[i]=sum[i-1]+a[i]-1; }
	f[1]=a[1];
	mini=0;
	for(int i=2;i<=n;++i){
		mini=min(mini,f[i-2]-sum[i-2]);
		f[i]=mini+sum[i-2]+max(0, a[i-1]-n+i-1)+a[i];
//		printf("%d: %lld %lld\n",i,f[i],mini);
	}
	printf("%lld\n",min(f[n],f[n-1]+a[n]));
}
// f[i]=f[j]+sum[i-2]-sum[j]+max(0,a[i-1]-n+i-1)
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
