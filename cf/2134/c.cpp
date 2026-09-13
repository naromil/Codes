#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn];
vector<int> vec;
inline int getd(int i){ return (i==0||i==n+1 ? 0 : max(0,a[i-1]+a[i+1]-a[i])); }
inline void _solv(){
	cin>>n; a[n+1]=0; vec.clear();
	for(int i=1;i<=n;++i){ cin>>a[i]; }
	ll ans=0;
	for(int i=3;i<n;i+=2){
		int cur=min(a[i],min(getd(i-1),getd(i+1)));
		ans+=cur;
		a[i]-=cur;
	}
	for(int i=1;i<=n;i+=2){
		if(!getd(i-1)&&!getd(i+1)) continue;
		int cur=min(a[i],max(getd(i-1),getd(i+1)));
		ans+=cur;
		a[i]-=cur;
	}
	printf("%lld\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
