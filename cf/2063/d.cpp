#include<bits/stdc++.h>
#define emp emplace_back
using namespace std;
using ll=long long;
const int kn=2e5+25;
class LINE{
	public: int n; ll a[kn],sum[kn];
	inline void init(){
		for(int i=1;i<=n;++i) cin>>a[i];
		sort(a+1,a+n+1);
//		for(int i=1;i<=n;++i) printf("%lld ",a[i]);
//		printf("\n");
		for(int i=1,j=n;i<=n;++i,--j){
			if(a[i]>=a[j]) break;
			sum[i]=sum[i-1]+(a[j]-a[i]);
		}
	}
	inline void clear(){ for(int i=1;i<=n;++i) a[i]=sum[i]=0; }
}a,b;
inline ll calc(int x,int y){
	if(2*x+y>a.n || 2*y+x>b.n || x<0 || y<0 || x>(a.n>>1) || y>(b.n>>1)) return 0ll;
	return a.sum[x]+b.sum[y];
}
vector<ll> ans;
inline void _solv(){
	cin>>a.n>>b.n;
	a.init();
	b.init();
	for(int k=1,lt,rt,mt,at;;++k){
		at=0;
		lt=max(0,2*k-b.n);
		rt=min(min(k,(a.n>>1)),a.n-k);
//		printf("%d: %d %d\n",k,lt,rt);
//		for(int i=lt;i<=rt+1;++i) printf("%lld ",calc(i,k-i));
//		printf("\n");
		if(lt>rt) break;
		while(lt<=rt){
			mt=(lt+rt)>>1;
			if(calc(mt,k-mt)>calc(at,k-at)) at=mt;
			if(calc(mt,k-mt)<calc(mt+1,k-mt-1)) lt=mt+1;
			else rt=mt-1;
		}
		ans.emp(calc(at,k-at));
	}
	printf("%ld\n",ans.size());
	for(auto u: ans) printf("%lld ",u);
	printf("\n");
	ans.clear();
	a.clear();
	b.clear();
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
