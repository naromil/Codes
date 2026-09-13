#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e6+26,km=1e6;
int n,m,a[kn],cnt[kn],f[kn],ans[kn];
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	for(int i=1;i<=km;++i){
		for(int j=i;j<=km;j+=i){
			f[i]+=cnt[j];
		}
	}
	for(int i=1;i<=km;++i){
		if(f[i]<m) continue;
		for(int j=i;j<=km;j+=i){
			ans[j]=max(ans[j],i);
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",ans[a[i]]);
	}
	return 0;
}
