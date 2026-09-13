#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],f[kn],ps[kn],maxi[kn];
vector<int> nxt[kn];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		nxt[i].clear();
		a[i]=f[i]=ps[i]=maxi[i]=0;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		nxt[a[i]].emplace_back(i);
		ps[i]=nxt[a[i]].size()-1;
	}
	for(int i=1;i<=n;++i){
		maxi[i]=maxi[i-1];
		if(ps[i]-a[i]+1<0) continue;
		int j=nxt[a[i]][ps[i]-a[i]+1];
		f[i]=maxi[j-1]+a[i];
		maxi[i]=max(maxi[i-1],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T; while(T--) _solv();
	return 0;
}
