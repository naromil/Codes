#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans=0;
inline bool chk(ll B,int A){
	if(B*B>n) return false;
	if((1ll<<A)>n) return false;
	if(log2(B*B)+log2(1ll<<A)-1>log2(n)) return false;
	if(B*B*(1ll<<A)>n) return false;
	return true;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	ll sqrtn=sqrt(n),B=3;
	ans=log2(n);
	for(int A=60;A>=1&&B<=sqrtn;--A){
		for(int k=30;k>=0;--k) if(chk(B+(1<<k)-1,A)){
			ans+=1ll*(k>0?(1<<k-1):(B&1))*A;
			B+=(1<<k);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
