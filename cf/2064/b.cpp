#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],vis[kn],f[kn];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i) f[i]=vis[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++vis[a[i]];
	}
	int ps=0;
	for(int i=1;i<=n;++i){
		if(vis[a[i]]==1){
			f[i]=f[i-1]+1;
			if(f[i]>f[ps]) ps=i;
		}
	}
	if(!ps) printf("0\n");
	else printf("%d %d\n",ps-f[ps]+1,ps);
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
