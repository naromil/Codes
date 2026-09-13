#include<bits/stdc++.h>
#include<atcoder/convolution>
using namespace std;
using ll=long long;
const int kn=1e6+16;
int n;
vector<int> a(kn,0);
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		a[x]=1;
	}
	auto b=atcoder::convolution(a,a);
	ll ans=0;
	for(int i=1;i<kn;++i){
		if(!a[i]) continue;
		ans+=b[i<<1]-1>>1;
	}
	printf("%lld\n",ans);
	return 0;
}
