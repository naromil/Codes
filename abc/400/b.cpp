#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int inf=1e9;
inline int fpow(ll x,int y){
	ll res=1;
	bool flg=false;
	while(y){
		if(y&1){
			if(flg) return 0;
			else if(res*x>inf) return 0;
			res=res*x;
		}
		x=x*x;
		if(x>inf) flg=true;
		y>>=1;
	}
	return res;
}
int n,m;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	ll ans=0;
	for(int i=0;i<=m;++i){
		int res=fpow(n,i);
		if(res==0){ printf("inf\n"); return 0; }
		ans=ans+res;
		if(ans>inf){ printf("inf\n"); return 0; }
	}
	printf("%lld\n",ans);
	return 0;
}
