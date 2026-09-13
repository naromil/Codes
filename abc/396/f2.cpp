#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,a[kn],cnt[kn],t[kn];
ll ans[kn];
inline int lb(const int& x){ return -x&x; }
inline void upd(int x){
	if(x==0) ++t[0];
	else for(;x<=m;x+=lb(x)) ++t[x];
}
inline int qry(int x){
	if(x<0) return 0;
	int res=0;
	for(;x;x-=lb(x)) res+=t[x];
	return res+t[0];
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	for(int i=1;i<=n;++i){
		ans[0]+=qry(m)-qry(a[i]);
		int pct=qry(a[i])-qry(a[i]-1)+1;
//		printf("%d: %d %d\n",i,(i-pct),(n-i-cnt[a[i]]+pct));
		ans[m-a[i]]+=(i-pct)-(n-i-cnt[a[i]]+pct);
		upd(a[i]);
	}
	for(int i=0;i<m;++i){
		if(i) ans[i]+=ans[i-1];
		printf("%lld\n",ans[i]);
	}
	return 0;
}
