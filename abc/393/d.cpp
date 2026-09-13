#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=5e5+55;
int n;
string a;
ll ls=0,ln=0,rs=0,rn=0,ans=0x3f3f3f3f3f3f3f3f;
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>a;
	a=" "+a;
	for(int i=1;i<=n;++i) if(a[i]=='1'){
		rs+=i;
		++rn;
	}
	for(int i=1;i<=n;++i) if(a[i]=='1'){
		rs-=i;
		--rn;
		ans=min(ans,ln*i-ls-(1+ln)*ln/2+rs-rn*i-(1+rn)*rn/2);
		ls+=i;
		++ln;
	}
	printf("%lld\n",ans);
	return 0;
}
