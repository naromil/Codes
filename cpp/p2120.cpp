#include<bits/stdc++.h>
#define SZ dq.size()
using namespace std;
using ll=long long;
const int kN=1e6+23;
int n,X[kN],P[kN],C[kN];
ll dis[kN],amo[kN];
ll f[kN];
inline void prep(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&X[i],&P[i],&C[i]);
		dis[i]=dis[i-1]+1ll*X[i]*P[i];
		amo[i]=amo[i-1]+P[i];
	}
}
inline ll calc(int l,int r){
	return X[r]*(amo[r]-amo[l])-(dis[r]-dis[l]);
}
inline ll _up(int j,int k){
	return (f[j]+dis[j]-f[k]-dis[k]);
}
inline ll _dn(int j,int k){
	return amo[j]-amo[k];
}
signed main(){
	prep();
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	deque<int> dq; dq.push_back(0);
	for(int i=1;i<=n;i++){
		while(SZ>=2 && _up(dq[0],dq[1]) >= X[i]*_dn(dq[0],dq[1]))
			dq.pop_front();
		if(SZ)
			f[i]=f[dq[0]]+calc(dq[0],i)+C[i];
		while(SZ>=2 && _up(dq[SZ-2],dq[SZ-1])*_dn(dq[SZ-1],i) >= _up(dq[SZ-1],i)*_dn(dq[SZ-2],dq[SZ-1]))
			dq.pop_back();
		dq.push_back(i);
	}
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int i=n;i>=1;i--){
		ans=min(ans,f[i]);
		if(P[i]) break;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
f[i]=f[j]+calc(j,i)+C[i]
f[i]=f[j]+X[i]*(amo[i]-amo[j])-dis[i]+dis[j]+C[i]
f[j]+dis[j]-X[i]*amo[j]
W[j]=f[j]+dis[j]

W[j]-X[i]*amo[j]>W[k]-X[i]*amo[k]
W[j]-W[k]>X[i](amo[j]-amo[k])
(W[j]-W[k]) / (amo[j]-amo[k]) < X[i]
*/
