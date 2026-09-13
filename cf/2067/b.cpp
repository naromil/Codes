#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=1024;
int n,a[kn];
inline void _solv(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i+=2){
		if(a[i]!=a[i+1]){
			printf("No\n");
			return;
		}
		for(int j=i+2;j<=n;++j) if(a[j]==a[i]) ++a[j];
	}
	printf("Yes\n");
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
