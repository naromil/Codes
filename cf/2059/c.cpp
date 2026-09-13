#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=505;
int n,a[kn][kn],rp[kn];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
		rp[i]=0;
		for(int j=n;j>=1;--j){
			if(a[i][j]==1) ++rp[i];
			else break;
		}
	}
	sort(rp+1,rp+n+1);
//	for(int i=1;i<=n;++i) printf("%d ",rp[i]);
//	printf("\n");
	int ans=1;
	for(int i=1;i<=n;++i){
		if(rp[i]>=ans) ++ans;
	}
	if(ans>n) ans=n;
	printf("%d\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
