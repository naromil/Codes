#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,a[kn];
inline bool _solv(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<n;++i){
		if(a[i]<=a[i+1]){
			a[i+1]-=a[i];
			a[i]=0;
		}
		else break;
	}
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]) return false;
	}
	return true;
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) printf(_solv() ? "YES\n" : "NO\n");
	return 0;
}
