#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=4e5+25;
int n,m,a[kn],cnt[kn];
inline void _solv(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	int ans=0;
	for(int k=1;k<=n;++k){
		if(m-k>n) continue;
		if(k<m-k){
			ans+=min(cnt[k], cnt[m-k]);
		}
		else if(k==m-k){
			ans+=(cnt[k]>>1);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i) cnt[i]=0;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
