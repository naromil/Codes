#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n;
double K,L,a[kn];
inline void _solv(){
	cin>>n>>K>>L;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	double cur=K, cut=a[1];
	for(int i=2;i<=n;++i){
		if(a[i]<cur) a[i]=min(a[i]+cut, cur);
		else a[i]=max(a[i]-cut, cur);
		if(a[i]<=cur){
			cur=max(cur,a[i]+K);
			continue;
		}
		double met=(a[i]-cur)/2.0;
//		printf("%lld %f: %f %f %f\n",i,cut,cur,a[i],met);
		if(met>L-cur){
			cut+=L-cur;
			cur=L;
			break;
		}
		cut+=met;
		cur+=met+K;
		if(cur>=L){
			break;
		}
	}
	if(cur<L) cut+=L-cur;
	ll ans=2ll*cut;
	printf("%lld\n",ans);
//	printf("FUCKING: %lld %f\n",ans,cur);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
