#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,a[kn],suf[kn],pre[kn],smr[kn],bgr[kn],t[kn];
ll ans[kn];
inline int lb(const int& x){ return -x&x; }
inline void upd(int x){
	if(x==0) ++t[0];
	else for(;x<=m;x+=lb(x)) ++t[x];
}
inline int qry(int x){
	int res=0;
	for(;x;x-=lb(x)) res+=t[x];
	return res+t[0];
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++pre[a[i]];
		++suf[a[i]];
	}
	for(int i=1;i<=m;++i) pre[i]+=pre[i-1];
	for(int i=m-1;i>=0;--i) suf[i]+=suf[i+1];
	for(int i=1;i<=n;++i){
		bgr[i]=qry(n)-qry(a[i]);
		if(a[i]-1>=0) smr[i]=qry(a[i]-1);
		ans[0]+=bgr[i];
		upd(a[i]);
	}
	for(int i=1;i<=n;++i){
		printf("%d: %d %d %d %d\n",i,smr[i],bgr[i],(a[i]==0?0:pre[a[i]-1]-smr[i]),suf[a[i]+1]-bgr[i]);
		if(a[i]>0) ans[m-a[i]]-=pre[a[i]-1]-smr[i];
		ans[m-a[i]]-=suf[a[i]+1]-bgr[i];
		ans[m-a[i]]+=bgr[i];
		ans[m-a[i]]+=smr[i];
	}
	for(int i=0;i<m;++i) printf("%lld ",ans[i]);
	printf("\n");
	for(int i=0;i<m;++i){
		if(i) ans[i]+=ans[i-1];
		printf("%lld\n",ans[i]);
	}
	return 0;
}
