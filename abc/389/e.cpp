#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn];
ll m,ans=0;
inline ll chk(ll mt){
	ll res=0,sum=0;
	for(int i=1;i<=n;++i){
		ll lsd=((mt/a[i]-1)>>1)+1;
		if(lsd<0) continue;
		sum+=lsd*lsd*a[i];
		res+=lsd;
	}
	return sum<=m ? res : -1;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	ll lt=1,rt=m;
	while(lt<=rt){
		ll mt=(lt+rt)>>1, ret=chk(mt);
		if(ret==-1){
			rt=mt-1;
		}
		else{
			ans=ret;
			lt=mt+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
