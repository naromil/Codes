#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int kn=2e5+25;
int n,m,a[kn];
inline void _solv(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==1){
		printf("0\n");
	}
	else if(n==m){
		int j=1;
		for(int i=1;i<=n;++i){
			if(i&1) continue;
			if(a[i]!=j){
				printf("%d\n",j);
				return;
			}
			++j;
		}
		printf("%d\n",j);
	}
	else{
		for(int i=2;i<=n-m+2&&i<=n;++i){
			if(a[i]!=1){
				printf("1\n");
				return;
			}
		}
		printf("2\n");
	}
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	int T; cin>>T;
	while(T--) _solv();
	return 0;
}
