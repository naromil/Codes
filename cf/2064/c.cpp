#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],pn[kn],pp[kn];
ll f[kn][2];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>0){ pn[i]=pn[i-1]; pp[i]=i; }
		else{ pn[i]=i; pp[i]=pp[i-1]; }
	}
	f[0][0]=f[0][1]=0;
	for(int i=1;i<=n;++i){
		f[i][0]=f[i][1]=0;
		if(a[i]>0){
			f[i][0]=f[pp[i-1]][0] + a[i];
		}
		else{
			f[i][1]=max(f[pn[i-1]][1],f[pp[i-1]][0]) - a[i];
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	printf("%lld\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
