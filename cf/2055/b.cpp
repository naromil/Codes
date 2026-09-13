#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn],b[kn];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int ps=0;
	for(int i=1;i<=n;++i){
		cin>>b[i];
		if(a[i]<b[i] && ps==0){
			ps=b[i]-a[i];
		}
		else if(a[i]<b[i]) ps=-1;
	}
	if(!~ps){ printf("NO\n"); return; }
	for(int i=1;i<=n;++i){
		if(a[i]<b[i]) continue;
		if(a[i]-ps<b[i]){ printf("NO\n"); return; }
	}
	printf("YES\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
