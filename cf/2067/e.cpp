#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],mini[kn],vis[kn];
inline void _solv(){
	cin>>n;
	for(int i=0;i<=n;++i) vis[i]=0;
	int l0=0,ct0=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==0&&!l0) l0=i;
		ct0+=(a[i]==0);
	}
	if(!l0){ printf("%d\n",n); return; }
	vector<int> b;
	for(int i=1;i<=n;++i) if(a[i]>0||i==l0) b.emplace_back(a[i]);
	mini[0]=b[0];
	for(int i=1;i<b.size();++i) mini[i]=min(mini[i-1],b[i]);
	int mex=0;
	for(int i=b.size()-1;i>=1;--i){
		if(b[i]<=n) ++vis[b[i]];
		while(vis[mex]) ++mex;
		if(mini[i-1]<mex){
			printf("%d\n",n-ct0);
			return;
		}
	}
	printf("%d\n",n-ct0+1);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
